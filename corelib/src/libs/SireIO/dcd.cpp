/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2022  Christopher Woods
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation; either version 3 of the License, or
  *  (at your option) any later version.
  *
  *  This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.
  *
  *  You should have received a copy of the GNU General Public License
  *  along with this program; if not, write to the Free Software
  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  *
  *  For full details of the license please see the COPYING file
  *  that should have come with this distribution.
  *
  *  You can contact the authors at https://sire.openbiosim.org
  *
\*********************************************/

#include "SireIO/dcd.h"
#include "SireIO/fortranfile.h"

#include "SireSystem/system.h"

#include "SireIO/amberformat.h"

#include "SireMol/atomcoords.h"
#include "SireMol/atomforces.h"
#include "SireMol/atomvelocities.h"
#include "SireMol/core.h"
#include "SireMol/mgname.h"
#include "SireMol/molecule.h"
#include "SireMol/moleditor.h"
#include "SireMol/molidx.h"
#include "SireMol/trajectory.h"

#include "SireVol/periodicbox.h"
#include "SireVol/triclinicbox.h"

#include "SireUnits/dimensions.h"
#include "SireUnits/units.h"

#include "SireBase/booleanproperty.h"
#include "SireBase/generalunitproperty.h"
#include "SireBase/getinstalldir.h"
#include "SireBase/parallel.h"
#include "SireBase/stringproperty.h"
#include "SireBase/timeproperty.h"
#include "SireBase/unittest.h"
#include "SireBase/releasegil.h"
#include "SireBase/progressbar.h"

#include "SireIO/errors.h"

#include "SireStream/shareddatastream.h"

#include "tostring.h"

#include "sire_version.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDateTime>

using namespace SireIO;
using namespace SireIO::detail;
using namespace SireMaths;
using namespace SireMol;
using namespace SireBase;
using namespace SireSystem;
using namespace SireVol;
using namespace SireUnits;
using namespace SireUnits::Dimension;
using namespace SireStream;

//// Thanks to the MDAnalysis parser
//// (https://github.com/MDAnalysis/mdanalysis/blob/develop/package/MDAnalysis/lib/formats/include/readdcd.h)
//// which really helped with the reverse engineering of the DCD fileformat
//// ESPECIALLY(!) the weird handling of the periodic box info!

/** This class provides a low-level interface to reading and writing
 *  a DCD file. It is designed to be used only with the
 *  DCD class
 */
class DCDFile
{
public:
    DCDFile();
    DCDFile(const QString &filename);
    ~DCDFile();

    bool open(QIODevice::OpenMode mode = QIODevice::ReadOnly);

    SireMol::Frame readFrame(int i, bool use_parallel = true) const;

    void writeHeader(int nframes, int natoms, bool has_periodic_space);
    void writeFrame(const SireMol::Frame &frame, bool use_parallel = true);

    int nAtoms() const;
    int nFrames() const;

    QString getTitle() const;
    void setTitle(QString title);

    SireUnits::Dimension::Time getTimeStep() const;
    void setTimeStep(const SireUnits::Dimension::Time &timestep);

    void close();

private:
    void readHeader();

    SpacePtr readSpace(int frame) const;
    QVector<Vector> readCoordinates(int frame) const;
    SireUnits::Dimension::Time readTime(int frame) const;

    void _lkr_reset();
    void _lkr_reindexFrames();
    void _lkr_readFrameIntoBuffer(int i);
    void _lkr_writeBufferToFile();

    /** The current frame that has been read into the buffer */
    FortranFile f;

    QString filename;

    QStringList title;

    QVector<qint32> fixed_atoms;

    /** The number of atoms in the frame - we assume all
     *  frames have the same number of atoms
     */
    qint64 natoms;

    /** The number of frames in the file */
    qint64 nframes;

    double timestep;

    SireVol::SpacePtr spc;

    qint64 istart;
    qint64 nsavc;
    qint64 nfixed;

    qint64 first_frame_line;

    QVector<Vector> first_frame;

    bool CHARMM_FORMAT;
    bool HAS_EXTRA_BLOCK;
    bool HAS_FOUR_DIMS;

    bool have_written_header;
};

//// DCDFile

DCDFile::DCDFile()
    : natoms(0), nframes(0), timestep(0), istart(0), nsavc(0), nfixed(0), first_frame_line(0), CHARMM_FORMAT(false),
      HAS_EXTRA_BLOCK(false), HAS_FOUR_DIMS(false), have_written_header(false)
{
}

DCDFile::DCDFile(const QString &fname)
    : filename(fname), natoms(0), nframes(0), timestep(0), istart(0), nsavc(0), nfixed(0), first_frame_line(0), CHARMM_FORMAT(false),
      HAS_EXTRA_BLOCK(false), HAS_FOUR_DIMS(false), have_written_header(false)
{
}

DCDFile::~DCDFile()
{
}

bool DCDFile::open(QIODevice::OpenMode mode)
{
    QString fname = this->filename;

    this->close();

    this->filename = fname;

    f = FortranFile(this->filename, mode);

    if (mode == QIODevice::ReadOnly)
    {
        this->readHeader();
    }

    return true;
}

void DCDFile::close()
{
    this->operator=(DCDFile());
}

void DCDFile::readHeader()
{
    if (f.nRecords() == 0)
    {
        nframes = 0;
        natoms = 0;
        return;
    }

    auto line = f[0];

    auto typ = line.readChar(4);

    if (typ != "CORD")
        throw SireIO::parse_error(QObject::tr("This does not look like a DCD file, because it does "
                                              "not start with 'CORD'. Starts with %1.")
                                      .arg(typ),
                                  CODELOC);

    auto ints = line.readInt32(9);

    nframes = ints[0];
    istart = ints[1];
    nsavc = ints[2];
    nfixed = ints[8];

    // now need to check the value at buffer[80] as, if this is non-zero,
    // then this is a CHARMM format DCD file
    CHARMM_FORMAT = line.readInt32At(80) != 0;

    // the value at buffer[44] says if there is an extra block
    HAS_EXTRA_BLOCK = line.readInt32At(44) != 0;

    // the value at buffer[48] says whether or not we have four dimensions
    HAS_FOUR_DIMS = line.readInt32At(48) != 0;

    timestep = 0;

    // read the timestep between frames (it is assumed to be in picoseconds)
    if (CHARMM_FORMAT)
    {
        timestep = line.readFloat32At(40);
    }
    else
    {
        timestep = line.readFloat64At(40);
    }

    line = f[1];

    int ntitle = line.readInt32(1)[0];

    for (int i = 0; i < ntitle; ++i)
    {
        QString t = line.readChar(32).simplified().replace(QChar('\0'), "");

        if (not t.isEmpty())
            title.append(t);
    }

    line = f[2];

    natoms = line.readInt32(1)[0];

    int linenum = 3;

    if (nfixed != 0)
    {
        line = f[linenum];
        linenum += 1;

        fixed_atoms = line.readInt32(nfixed);
    }

    first_frame_line = linenum;

    // now sanity check the rest of the file
    int num_lines_per_frame = 3;

    if (HAS_FOUR_DIMS)
    {
        num_lines_per_frame += 1;
    }

    if (CHARMM_FORMAT and HAS_EXTRA_BLOCK)
    {
        num_lines_per_frame += 1;
    }

    if (nframes != 0)
    {
        if (f.nRecords() != first_frame_line + (num_lines_per_frame * nframes))
        {
            // we need to calculate nframes?
            qDebug() << QObject::tr("WARNING: Wrong number of records in the DCD file. Expect to have %1 "
                                    "for %2 frames, but actually have %3.")
                            .arg(first_frame_line + (num_lines_per_frame * nframes))
                            .arg(nframes)
                            .arg(f.nRecords());

            nframes = (f.nRecords() - first_frame_line) / num_lines_per_frame;
        }
    }
    else
    {
        // we need to calculate nframes
        nframes = (f.nRecords() - first_frame_line) / num_lines_per_frame;
    }

    if (nframes == 0)
    {
        // this is an empty file!
        spc = SpacePtr(new Cartesian());
        return;
    }

    // now read in the first frame, in case we have to do any merging
    // with the fixed atoms - start by reading the space
    spc = this->readSpace(0);

    if (nfixed != 0)
    {
        // we have to read in the first set of coordinates, as these
        // hold the fixed atoms as well as the movable atoms
        if (CHARMM_FORMAT and HAS_EXTRA_BLOCK)
        {
            line = f[linenum];
            linenum += 1;

            line.readFloat64(6);
        }

        line = f[linenum];
        linenum += 1;
        auto x = line.readFloat32(natoms);

        line = f[linenum];
        linenum += 1;
        auto y = line.readFloat32(natoms);

        line = f[linenum];
        linenum += 1;
        auto z = line.readFloat32(natoms);

        first_frame = QVector<Vector>(natoms);

        for (int i = 0; i < natoms; ++i)
        {
            first_frame[i] = Vector(x[i], y[i], z[i]);
        }
    }
}

void DCDFile::writeHeader(int nframes, int natoms, bool has_periodic_space)
{
    FortranRecord line(f.isLittleEndian());

    // bytes 0 to 3
    line.writeChar("CORD", 4);

    // first values are 9 integers, initialised to zero
    QVector<qint32> ints(9, 0);

    // every value is zero, as we don't know what they are
    ints[0] = nframes;
    // ints[1] = 0; // index of the first frame - we don't know this either...
    ints[2] = 1;       // number of timesteps between frames
    ints[3] = nframes; // number of timesteps written
    // ints[8] = 0; // nfixed is zero - everything will be treated as moving

    // bytes 4 to 39
    line.writeInt32(ints, 9);

    // bytes 40 to 43
    line.writeFloat32(timestep);

    // bytes 44 to 47
    if (has_periodic_space)
    {
        HAS_EXTRA_BLOCK = true;
        line.writeInt32(1); // has an extra block
    }
    else
    {
        HAS_EXTRA_BLOCK = false;
        line.writeInt32(0); // no extra block
    }

    // bytes 48-51
    line.writeInt32(0); // not four dimensions

    // bytes 52-79 - should all be zero - can re-use ints
    ints[0] = 0;
    ints[2] = 0;
    ints[3] = 0;
    line.writeInt32(ints, 7);

    // bytes 80-83
    line.writeInt32(24); // 24 as we are in CHARMM format - we need this to write space info
    CHARMM_FORMAT = true;

    // we will only write 3D coordinates
    HAS_FOUR_DIMS = false;

    f.write(line);

    // now write the title
    line = FortranRecord(f.isLittleEndian());

    if (title.isEmpty())
    {
        auto now = QDateTime::currentDateTime();

        title.append("Created by https://sire.openbiosim.org");
        title.append(QString("Version: %1").arg(SIRE_VERSION));
        title.append(QString("REMARKS Created %1 at %2")
                         .arg(now.toString("dd MMMM yyyy"))
                         .arg(now.toString("hh:mm.ss")));
    }

    line.writeInt32(title.count());

    for (const auto &t : title)
    {
        line.writeChar(t, 80);
    }

    f.write(line);

    // now write the number of atoms
    line = FortranRecord(f.isLittleEndian());
    line.writeInt32(natoms);

    f.write(line);

    have_written_header = true;
}

SireUnits::Dimension::Time DCDFile::readTime(int frame) const
{
    return ((istart * timestep) + (frame * timestep)) * picosecond;
}

SpacePtr DCDFile::readSpace(int frame) const
{
    if (frame < 0 or frame >= nframes)
    {
        throw SireIO::parse_error(
            QObject::tr("Trying to access an invalid frame (%1) from a DCD with %2 frames.").arg(frame).arg(nframes),
            CODELOC);
    }

    // get the line number for this frame
    int num_lines_per_frame = 3;

    if (HAS_FOUR_DIMS)
        num_lines_per_frame += 1;

    if (CHARMM_FORMAT and HAS_EXTRA_BLOCK)
    {
        num_lines_per_frame += 1;

        int linenum = first_frame_line + (frame * num_lines_per_frame);

        auto line = f[linenum];

        auto boxinfo = line.readFloat64(6);

        // there isn't a well-defined standard for the box info

        // first check for Charmm or NAMD > 2.5 format. This has the data
        // written as [A, gamma, B, beta, alpha, C] (yes, really!)

        auto A = boxinfo[0];
        auto B = boxinfo[2];
        auto C = boxinfo[5];

        auto alpha = boxinfo[4];
        auto beta = boxinfo[3];
        auto gamma = boxinfo[1];

        if (A == 0 and B == 0 and C == 0)
        {
            // this is an infinite cartesian space
            return SpacePtr(new Cartesian());
        }

        try
        {
            if (alpha <= 1.0 and alpha >= -1.0 and beta <= 1.0 and beta >= -1.0 and gamma <= 1.0 and gamma >= -1.0)
            {
                // the angle cosines have been saved
                alpha = 90 - ((std::asin(alpha)) * radians).to(degrees);
                beta = 90 - ((std::asin(beta)) * radians).to(degrees);
                gamma = 90 - ((std::asin(gamma)) * radians).to(degrees);
            }
            else if (alpha < 0 or beta < 0 or gamma < 0 or A < 0 or B < 0 or C < 0 or
                     alpha > 180 or beta > 180 or gamma > 180)
            {
                // new CHARMM format - these are the box vectors
                return SpacePtr(new TriclinicBox(Vector(boxinfo[0], boxinfo[1], boxinfo[3]),
                                                 Vector(boxinfo[1], boxinfo[2], boxinfo[4]),
                                                 Vector(boxinfo[3], boxinfo[4], boxinfo[5])));
            }

            if (alpha == 90 and beta == 90 and gamma == 90)
            {
                // this is a PeriodicBox
                return SpacePtr(new PeriodicBox(Vector(A, B, C)));
            }
            else
            {
                // this is a triclinic space
                return SpacePtr(new TriclinicBox(A, B, C,
                                                 alpha * degrees,
                                                 beta * degrees,
                                                 gamma * degrees));
            }
        }
        catch (const SireError::exception &e)
        {
            qDebug() << "WARNING - cannot interpret the space information for the DCD file.";
            qDebug() << "WARNING - data is" << Sire::toString(boxinfo);
            qDebug() << "WARNING - error is" << e.what() << ":" << e.why();
        }
    }

    // this is an infinite cartesian space
    return SpacePtr(new Cartesian());
}

QVector<Vector> DCDFile::readCoordinates(int frame) const
{
    if (frame < 0 or frame >= nframes)
    {
        throw SireIO::parse_error(
            QObject::tr("Trying to access an invalid frame (%1) from a DCD with %2 frames.").arg(frame).arg(nframes),
            CODELOC);
    }

    // get the line number for this frame
    int num_lines_per_frame = 3;
    int skip_unitcell = 0;

    if (HAS_FOUR_DIMS)
        num_lines_per_frame += 1;

    if (CHARMM_FORMAT and HAS_EXTRA_BLOCK)
    {
        num_lines_per_frame += 1;
        skip_unitcell = 1;
    }

    int linenum = first_frame_line + (frame * num_lines_per_frame) + skip_unitcell;

    if (nfixed == 0)
    {
        // read in the x, y, and z data
        auto line = f[linenum];
        auto x = line.readFloat32(natoms);
        line = f[linenum + 1];
        auto y = line.readFloat32(natoms);
        line = f[linenum + 2];
        auto z = line.readFloat32(natoms);

        QVector<Vector> coords(natoms);

        auto coords_data = coords.data();
        const auto x_data = x.constData();
        const auto y_data = y.constData();
        const auto z_data = z.constData();

        for (int i = 0; i < natoms; ++i)
        {
            coords_data[i] = Vector(x_data[i], y_data[i], z_data[i]);
        }

        return coords;
    }
    else if (frame == 0)
    {
        return first_frame;
    }
    else
    {
        // read the coordinates and map them into a copy of first_frame
        QVector<Vector> frame = first_frame;

        // TODO
        throw SireError::incomplete_code(QObject::tr(
                                             "Need to write the code to read DCD frames with fixed atoms!"),
                                         CODELOC);

        return frame;
    }
}

Frame DCDFile::readFrame(int frame, bool use_parallel) const
{
    frame = SireID::Index(frame).map(nframes);

    auto space = this->readSpace(frame);
    auto coords = this->readCoordinates(frame);
    auto time = this->readTime(frame);

    return Frame(this->readCoordinates(frame),
                 this->readSpace(frame).read(),
                 this->readTime(frame));
}

void DCDFile::writeFrame(const SireMol::Frame &frame, bool use_parallel)
{
    const int natoms = frame.nAtoms();

    if (natoms <= 0 or (not frame.hasCoordinates()))
        return;

    bool has_periodic_space = frame.space().isPeriodic();

    // now write the space
    if (has_periodic_space)
    {
        double A, B, C, alpha, beta, gamma;

        if (frame.space().isA<PeriodicBox>())
        {
            const auto dims = frame.space().asA<PeriodicBox>().dimensions();

            A = dims.x();
            B = dims.y();
            C = dims.z();

            alpha = 90.0;
            beta = 90.0;
            gamma = 90.0;
        }
        else
        {
            TriclinicBox box;

            if (frame.space().isA<TriclinicBox>())
                box = frame.space().asA<TriclinicBox>();
            else
            {
                auto matrix = frame.space().boxMatrix();
                box = TriclinicBox(matrix.column0(), matrix.column1(), matrix.column2());
            }

            A = box.vector0().magnitude();
            B = box.vector1().magnitude();
            C = box.vector2().magnitude();

            alpha = box.alpha();
            beta = box.beta();
            gamma = box.gamma();
        }

        FortranRecord line(f.isLittleEndian());

        // we will only write values in CHARMM format
        // [A, gamma, B, beta, alpha, C]

        line.writeFloat64(A);
        line.writeFloat64(gamma);
        line.writeFloat64(B);
        line.writeFloat64(beta);
        line.writeFloat64(alpha);
        line.writeFloat64(C);

        f.write(line);
    }

    // now write the x, y and z coordinates
    QVector<float> x(natoms);
    QVector<float> y(natoms);
    QVector<float> z(natoms);

    auto x_data = x.data();
    auto y_data = y.data();
    auto z_data = z.data();

    const auto coords_data = frame.coordinates().constData();

    for (int i = 0; i < natoms; ++i)
    {
        const auto &c = coords_data[i];

        x_data[i] = c.x();
        y_data[i] = c.y();
        z_data[i] = c.z();
    }

    FortranRecord line(f.isLittleEndian());
    line.writeFloat32(x, natoms);
    f.write(line);

    line = FortranRecord(f.isLittleEndian());
    line.writeFloat32(y, natoms);
    f.write(line);

    line = FortranRecord(f.isLittleEndian());
    line.writeFloat32(z, natoms);
    f.write(line);
}

QString DCDFile::getTitle() const
{
    return title.join("");
}

void DCDFile::setTitle(QString t)
{
    // need to split into blocks of 80 characters
    title.clear();

    while (t.length() > 80)
    {
        title.append(t.mid(0, 80));
        t.remove(0, 80);
    }

    if (t.length() > 0)
    {
        title.append(t);
    }
}

SireUnits::Dimension::Time DCDFile::getTimeStep() const
{
    return timestep * picosecond;
}

void DCDFile::setTimeStep(const SireUnits::Dimension::Time &t)
{
    timestep = t.to(picosecond);
}

int DCDFile::nAtoms() const
{
    return natoms;
}

int DCDFile::nFrames() const
{
    return nframes;
}

////////
//////// Implemenetation of DCD
////////

static const RegisterMetaType<DCD> r_dcd;
const RegisterParser<DCD> register_dcd;

QDataStream &operator<<(QDataStream &ds, const DCD &dcd)
{
    writeHeader(ds, r_dcd, 1);

    SharedDataStream sds(ds);

    sds << dcd.current_frame << dcd.parse_warnings
        << dcd.nframes << dcd.frame_idx
        << static_cast<const MoleculeParser &>(dcd);

    return ds;
}

QDataStream &operator>>(QDataStream &ds, DCD &dcd)
{
    VersionID v = readHeader(ds, r_dcd);

    if (v == 1)
    {
        SharedDataStream sds(ds);

        sds >> dcd.current_frame >> dcd.parse_warnings >> dcd.nframes >> dcd.frame_idx >> static_cast<MoleculeParser &>(dcd);
    }
    else
        throw version_error(v, "1", r_dcd, CODELOC);

    return ds;
}

/** Constructor */
DCD::DCD()
    : ConcreteProperty<DCD, MoleculeParser>(),
      nframes(0), frame_idx(0)
{
}

/** Return the format name that is used to identify this file format within Sire */
QString DCD::formatName() const
{
    return "DCD";
}

/** Return the suffixes that DCD files will typically have */
QStringList DCD::formatSuffix() const
{
    static const QStringList suffixes = {"DCD"};
    return suffixes;
}

/** Return a description of the file format */
QString DCD::formatDescription() const
{
    return QObject::tr("DCD coordinate/velocity binary trajectory files "
                       "based on charmm / namd / x-plor format.");
}

/** This is not a text file */
bool DCD::isTextFile() const
{
    return false;
}

/** Open the file and read in all the metadata */
void DCD::parse()
{
    f.reset(new DCDFile(this->filename()));

    try
    {
        if (not f->open(QIODevice::ReadOnly))
        {
            throw SireIO::parse_error(QObject::tr(
                                          "Failed to open DCDFile %1")
                                          .arg(this->filename()),
                                      CODELOC);
        }

        nframes = f->nFrames();

        if (nframes == 0)
        {
            this->setScore(0);
            f.reset();
            throw SireIO::parse_error(QObject::tr(
                                          "Failed to read any frames from DCDFile %1. Is the file empty?")
                                          .arg(this->filename()),
                                      CODELOC);
        }

        current_frame = f->readFrame(0, this->usesParallel());
        frame_idx = 0;

        this->setScore(f->nFrames() * current_frame.nAtoms());
    }
    catch (...)
    {
        this->setScore(0);
        f.reset();
        throw;
    }
}

/** Construct by parsing the passed file */
DCD::DCD(const QString &filename, const PropertyMap &map)
    : ConcreteProperty<DCD, MoleculeParser>(map),
      nframes(0), frame_idx(0)
{
    // this gets the absolute file path
    this->setFilename(filename);
    this->parse();
}

/** Construct by parsing the data in the passed text lines */
DCD::DCD(const QStringList &lines, const PropertyMap &map)
    : ConcreteProperty<DCD, MoleculeParser>(lines, map)
{
    throw SireIO::parse_error(QObject::tr("You cannot create a binary Gromacs DCD file from a set of text lines!"),
                              CODELOC);
}

/** Construct by extracting the necessary data from the passed System */
DCD::DCD(const System &system, const PropertyMap &map)
    : ConcreteProperty<DCD, MoleculeParser>(system, map),
      nframes(1), frame_idx(0)
{
    current_frame = MoleculeParser::createFrame(system, map);
}

/** Copy constructor */
DCD::DCD(const DCD &other)
    : ConcreteProperty<DCD, MoleculeParser>(other),
      current_frame(other.current_frame), parse_warnings(other.parse_warnings),
      nframes(other.nframes), frame_idx(other.frame_idx), f(other.f)
{
}

/** Destructor */
DCD::~DCD()
{
}

DCD &DCD::operator=(const DCD &other)
{
    if (this != &other)
    {
        current_frame = other.current_frame;
        parse_warnings = other.parse_warnings;
        nframes = other.nframes;
        frame_idx = other.frame_idx;
        f = other.f;

        MoleculeParser::operator=(other);
    }

    return *this;
}

bool DCD::operator==(const DCD &other) const
{
    return MoleculeParser::operator==(other);
}

bool DCD::operator!=(const DCD &other) const
{
    return MoleculeParser::operator!=(other);
}

const char *DCD::typeName()
{
    return QMetaType::typeName(qMetaTypeId<DCD>());
}

const char *DCD::what() const
{
    return DCD::typeName();
}

bool DCD::isFrame() const
{
    return true;
}

int DCD::nFrames() const
{
    return nframes;
}

int DCD::count() const
{
    return this->nFrames();
}

int DCD::size() const
{
    return this->nFrames();
}

Frame DCD::getFrame(int frame) const
{
    frame = SireID::Index(frame).map(this->nFrames());

    if (frame < 0)
        frame = 0;

    if (frame == frame_idx)
        return current_frame;

    if (f.get() == 0)
    {
        throw SireError::file_error(QObject::tr(
                                        "Somehow we don't have access to the underlying DCD file?"),
                                    CODELOC);
    }

    return f->readFrame(frame, this->usesParallel());
}

DCD DCD::operator[](int i) const
{
    i = SireID::Index(i).map(this->nFrames());

    DCD ret(*this);

    ret.current_frame = this->getFrame(i);
    ret.frame_idx = i;

    return ret;
}

QString DCD::toString() const
{
    if (this->nAtoms() == 0)
    {
        return QObject::tr("DCD::null");
    }
    else
    {
        return QObject::tr("DCD( nAtoms() = %1, nFrames() = %2 )")
            .arg(this->nAtoms())
            .arg(this->nFrames());
    }
}

/** Parse from the passed file */
DCD DCD::parse(const QString &filename)
{
    return DCD(filename);
}

/** Internal function used to add the data from this parser into the passed System */
void DCD::addToSystem(System &system, const PropertyMap &map) const
{
    MoleculeParser::copyFromFrame(current_frame, system, map);

    // update the System fileformat property to record that it includes
    // data from this file format
    QString fileformat = this->formatName();

    PropertyName fileformat_property = map["fileformat"];

    try
    {
        QString last_format = system.property(fileformat_property).asA<StringProperty>().value();
        fileformat = QString("%1,%2").arg(last_format, fileformat);
    }
    catch (...)
    {
    }

    if (fileformat_property.hasSource())
    {
        system.setProperty(fileformat_property.source(), StringProperty(fileformat));
    }
    else
    {
        system.setProperty("fileformat", StringProperty(fileformat));
    }
}

/** Return the number of atoms whose coordinates are contained in this restart file */
int DCD::nAtoms() const
{
    return current_frame.nAtoms();
}

/** Return this parser constructed from the passed filename */
MoleculeParserPtr DCD::construct(const QString &filename, const PropertyMap &map) const
{
    // don't construct from a pointer as it could leak
    return MoleculeParserPtr(DCD(filename, map));
}

/** Return this parser constructed from the passed set of lines */
MoleculeParserPtr DCD::construct(const QStringList &lines, const PropertyMap &map) const
{
    // don't construct from a pointer as it could leak
    return MoleculeParserPtr(DCD(lines, map));
}

/** Return this parser constructed from the passed SireSystem::System */
MoleculeParserPtr DCD::construct(const SireSystem::System &system, const PropertyMap &map) const
{
    // don't construct from a pointer as it could leak
    return MoleculeParserPtr(DCD(system, map));
}

/** Write this binary file 'filename' */
QStringList DCD::writeToFile(const QString &filename) const
{
    if (this->nFrames() == 0 or this->nAtoms() == 0)
        return QStringList();

    auto gil = SireBase::release_gil();

    createDirectoryForFile(filename);

    DCDFile outfile(filename);

    if (not outfile.open(QIODevice::WriteOnly))
        throw SireError::file_error(QObject::tr(
                                        "Could not open %1 to write the DCD file.")
                                        .arg(filename),
                                    CODELOC);

    if (this->writingTrajectory())
    {
        const auto frames = this->framesToWrite();

        if (frames.isEmpty())
            return QStringList();

        ProgressBar bar("Save DCD", frames.count());
        bar.setSpeedUnit("frames / s");

        bar = bar.enter();

        Frame first_frame = this->createFrame(frames[0]);
        Frame second_frame;

        if (frames.count() > 1)
        {
            second_frame = this->createFrame(frames[1]);
            outfile.setTimeStep(second_frame.time() - first_frame.time());
        }

        outfile.writeHeader(frames.count(), first_frame.nAtoms(),
                            first_frame.space().isPeriodic());

        outfile.writeFrame(first_frame, usesParallel());
        bar.setProgress(1);

        first_frame = Frame();

        if (frames.count() > 1)
        {
            outfile.writeFrame(second_frame, usesParallel());
            bar.setProgress(2);
            second_frame = Frame();
        }

        for (int i = 2; i < frames.count(); ++i)
        {
            const auto frame = this->createFrame(frames[i]);
            outfile.writeFrame(frame, usesParallel());
            bar.setProgress(i + 1);
        }

        bar.success();
    }
    else
    {
        outfile.writeHeader(1, current_frame.nAtoms(),
                            current_frame.space().isPeriodic());

        outfile.writeFrame(current_frame, usesParallel());
    }

    outfile.close();

    return QStringList(filename);
}
