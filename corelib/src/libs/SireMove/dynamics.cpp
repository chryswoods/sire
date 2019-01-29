/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2009  Christopher Woods
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

#include "dynamics.h"

#include "SireStream/datastream.h"

using namespace SireMove;
using namespace SireStream;

static const RegisterMetaType<Dynamics> r_dynamics( MAGIC_ONLY,
                                                    "SireMove::Dynamics" );

/** Serialise to a binary datastream */
QDataStream &operator<<(QDataStream &ds, const Dynamics &dynamics)
{
    writeHeader(ds, r_dynamics, 1);
    
    ds << dynamics.ensmble << static_cast<const Move&>(dynamics);
    
    return ds;
}

/** Extract from a binary datastream */
QDataStream &operator>>(QDataStream &ds, Dynamics &dynamics)
{
    VersionID v = readHeader(ds, r_dynamics);
    
    if (v == 1)
    {
        ds >> dynamics.ensmble >> static_cast<Move&>(dynamics);
    }
    else
        throw version_error(v, "1", r_dynamics, CODELOC);
        
    return ds;
}

/** Constructor */
Dynamics::Dynamics(const PropertyMap &map) : Move(map)
{}

/** Copy constructor */
Dynamics::Dynamics(const Dynamics &other) : Move(other), ensmble(other.ensmble)
{}

/** Destructor */
Dynamics::~Dynamics()
{}

/** Copy assignment operator */
Dynamics& Dynamics::operator=(const Dynamics &other)
{
    ensmble = other.ensmble;
    Move::operator=(other);
    
    return *this;
}

/** Comparison operator */
bool Dynamics::operator==(const Dynamics &other) const
{
    return ensmble == other.ensmble and Move::operator==(other);
}

/** Comparison operator */
bool Dynamics::operator!=(const Dynamics &other) const
{
    return ensmble != other.ensmble or Move::operator!=(other);
}

/** Internal function used by derived classes to set the ensemble 
    for this move */
void Dynamics::setEnsemble(const Ensemble &ensemble)
{
    ensmble = ensemble;
}

/** Return the ensemble that would be generated by this move */
Ensemble Dynamics::ensemble() const
{
    return ensmble;
}
