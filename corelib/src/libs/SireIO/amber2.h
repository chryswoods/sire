/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2017  Christopher Woods
  *
  *  This program is free software; you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation; either version 2 of the License, or
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
  *  You can contact the authors via the developer's mailing list
  *  at http://siremol.org
  *
\*********************************************/

#ifndef SIREIO_AMBER2_H
#define SIREIO_AMBER2_H

#include "moleculeparser.h"

#include "SireMaths/vector.h"
#include "SireMM/ljparameter.h"

SIRE_BEGIN_HEADER

namespace SireIO
{
class AmberParm;
class AmberRst;
}

QDataStream& operator<<(QDataStream&, const SireIO::AmberParm&);
QDataStream& operator>>(QDataStream&, SireIO::AmberParm&);

QDataStream& operator<<(QDataStream&, const SireIO::AmberRst&);
QDataStream& operator>>(QDataStream&, SireIO::AmberRst&);

namespace SireMol
{
class MolEditor;
class MoleculeInfoData;
}

namespace SireMM
{
class AmberParams;
}

namespace SireIO
{

/** This class represents an Amber-format restart/coordinate file (ascii),
    currently supporting these files from Amber7 to Amber16.
    
    The format of this file is described here;
    
    http://ambermd.org/formats.html
    
    (specifically the "AMBER coordinate/restart" file specification
 
    @author Christopher Woods
*/
class SIREIO_EXPORT AmberRst : public SireBase::ConcreteProperty<AmberRst,MoleculeParser>
{

friend QDataStream& ::operator<<(QDataStream&, const AmberRst&);
friend QDataStream& ::operator>>(QDataStream&, AmberRst&);

public:
    AmberRst();
    AmberRst(const QString &filename,
             const PropertyMap &map = PropertyMap());
    AmberRst(const QStringList &lines,
             const PropertyMap &map = PropertyMap());
    AmberRst(const SireSystem::System &system,
             const PropertyMap &map = PropertyMap());
    
    AmberRst(const AmberRst &other);
    
    ~AmberRst();
    
    AmberRst& operator=(const AmberRst &other);
    
    bool operator==(const AmberRst &other) const;
    bool operator!=(const AmberRst &other) const;
    
    static const char* typeName();
    
    const char* what() const;

    QString toString() const;

    QString formatName() const;

    static AmberRst parse(const QString &filename);

    QString title() const;
    double time() const;

    int nAtoms() const;
    
    bool hasVelocities() const;

    QVector<SireMaths::Vector> coordinates() const;
    QVector<SireMaths::Vector> velocities() const;

    SireMaths::Vector boxDimensions() const;
    SireMaths::Vector boxAngles() const;

protected:
    void addToSystem(SireSystem::System &system, const PropertyMap &map) const;

private:
    void parse(const PropertyMap &map);

    void readBoxInfo(int boxidx);

    /** The title of the file */
    QString ttle;
    
    /** The current time of the simulation */
    double current_time;
    
    /** The coordinate data */
    QVector<SireMaths::Vector> coords;
    
    /** The velocity data in amber units */
    QVector<SireMaths::Vector> vels;
    
    /** The box dimensions */
    SireMaths::Vector box_dims;
    
    /** The box angles */
    SireMaths::Vector box_angs;
};

/** This class represents an Amber-format parameter file, currently
    supporting top files produced from Amber7 until Amber16
    
    The format of this file is described here;
    
    http://ambermd.org/formats.html
    
    (specifically the "PARM" parameter/topology file specification)
 
    @author Christopher Woods
*/
class SIREIO_EXPORT AmberParm : public SireBase::ConcreteProperty<AmberParm,MoleculeParser>
{

friend QDataStream& ::operator<<(QDataStream&, const AmberParm&);
friend QDataStream& ::operator>>(QDataStream&, AmberParm&);

public:
    enum FLAG_TYPE { UNKNOWN = 0,
                     INTEGER = 1,
                     FLOAT = 2,
                     STRING = 3 };

    AmberParm();

    AmberParm(const QString &filename,
              const PropertyMap &map = PropertyMap());
    AmberParm(const QStringList &lines,
              const PropertyMap &map = PropertyMap());

    AmberParm(const SireSystem::System &system,
              const PropertyMap &map = PropertyMap());
    
    AmberParm(const AmberParm &other);
    
    ~AmberParm();
    
    AmberParm& operator=(const AmberParm &other);
    
    bool operator==(const AmberParm &other) const;
    bool operator!=(const AmberParm &other) const;
  
    static const char* typeName();
  
    const char* what() const;
    
    QString toString() const;
    
    QString formatName() const;
    
    bool isLead() const;
    
    static AmberParm parse(const QString &filename,
                           const PropertyMap &map = PropertyMap());

    SireMol::Molecule getMolecule(int i, const PropertyMap &map = PropertyMap()) const;
    
    SireMol::Molecule getMolecule(int i, const AmberRst &rst,
                                  const PropertyMap &map = PropertyMap()) const;
    
    QVector<QString> linesForFlag(const QString &flag) const;
    
    QStringList flags() const;

    FLAG_TYPE flagType(const QString &flag) const;
    
    QVector<qint64> intData(const QString &flag) const;
    QVector<double> floatData(const QString &flag) const;
    QVector<QString> stringData(const QString &flag) const;

    QString title() const;

    int nAtoms() const;
    
    int nTypes() const;
    
    int nBonds() const;
    int nBondsWithHydrogen() const;
    int nBondsNoHydrogen() const;
    
    int nAngles() const;
    int nAnglesWithHydrogen() const;
    int nAnglesNoHydrogen() const;
    
    int nDihedrals() const;
    int nDihedralsWithHydrogen() const;
    int nDihedralsNoHydrogen() const;
    
    int nExcluded() const;
    int nResidues() const;
    
    int nMolecules() const;
    
    int nAtoms(int molidx) const;
    
    void assertSane() const;

protected:
    SireSystem::System startSystem(const PropertyMap &map) const;

private:
    void parse(const PropertyMap &map);

    void rebuildAfterReload();
    void rebuildLJParameters();
    void rebuildBADIndicies();
    void rebuildExcludedAtoms();

    SireMM::AmberParams getAmberParams(int imol, const SireMol::MoleculeInfoData &molinfo) const;

    SireMol::MolStructureEditor getMolStructure(int start_idx, int natoms,
                                                const SireBase::PropertyName &cutting) const;

    SireMol::MolEditor getMolecule(int molidx, int start_idx, int natoms,
                                   const PropertyMap &map) const;

    QVector< QPair<int,int> > moleculeIndicies() const;

    QVector<int> getAtomIndexToMolIndex() const;

    /** Function to process all flags, returning the parsing score */
    double processAllFlags();
    
    /** A map showing the line number of all flags. This holds
        the start index and number of lines for each flag */
    QHash< QString,QPair<qint64,qint64> > flag_to_line;
    
    /** The raw int data for the integer flags */
    QHash< QString, QVector<qint64> > int_data;
    
    /** The raw float data for the float flags */
    QHash< QString, QVector<double> > float_data;
    
    /** The raw string data for the string flags */
    QHash< QString, QVector<QString> > string_data;
    
    /** All of the LJ parameters, indexed by atom type */
    QVector<SireMM::LJParameter> lj_data;

    /** The indicies of the bonds for each molecule */
    QVector< QVector<int> > bonds_inc_h, bonds_exc_h;
    
    /** The indicies of the angles for each molecule */
    QVector< QVector<int> > angs_inc_h, angs_exc_h;
    
    /** The indicies of the dihedrals for each molecule */
    QVector< QVector<int> > dihs_inc_h, dihs_exc_h;
    
    /** The excluded atoms for each atom of each molecule */
    QVector< QVector< QVector<int> > > excl_atoms;
    
    /** A copy of the POINTER data to prevent over-lookup */
    QVector<qint64> pointers;
};

#ifndef SIRE_SKIP_INLINE_FUNCTIONS

/** The AmberParm parser is a lead parser - it is capable alone
    of creating the System */
inline bool AmberParm::isLead() const
{
    return true;
}

#endif // SIRE_SKIP_INLINE_FUNCTIONS

}

Q_DECLARE_METATYPE( SireIO::AmberParm )
Q_DECLARE_METATYPE( SireIO::AmberRst )

SIRE_EXPOSE_CLASS( SireIO::AmberParm )
SIRE_EXPOSE_CLASS( SireIO::AmberRst )

SIRE_END_HEADER

#endif

