/********************************************\
  *
  *  Sire - Molecular Simulation Framework
  *
  *  Copyright (C) 2018  Christopher Woods
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

#ifndef SIREMOL_SELECT_H
#define SIREMOL_SELECT_H

#include "SireBase/property.h"
#include "SireBase/propertymap.h"

#include "SireMol/viewsofmol.h"
#include "SireMol/mover.hpp"

#include <boost/shared_ptr.hpp>

#include <QList>

SIRE_BEGIN_HEADER

namespace SireMol
{
class Select;
class SelectResult;
class SelectResultMover;
}

QDataStream& operator<<(QDataStream&, const SireMol::Select&);
QDataStream& operator>>(QDataStream&, SireMol::Select&);

QDataStream& operator<<(QDataStream&, const SireMol::SelectResult&);
QDataStream& operator>>(QDataStream&, SireMol::SelectResult&);

QDataStream& operator<<(QDataStream&, const SireMol::SelectResultMover&);
QDataStream& operator>>(QDataStream&, SireMol::SelectResultMover&);

namespace SireMol
{

class MolGroupsBase;
class MoleculeGroup;
class Molecules;
class MoleculeView;
class ViewsOfMol;

namespace parser
{
/** This is the base class of all of the select objects. It is a private
    object that should only be used by Select

    @author Christopher Woods
*/
class SelectEngine
{

public:
    SelectEngine();
    virtual ~SelectEngine();
    
    SelectResult operator()(const MolGroupsBase &molgroups,
                            const PropertyMap &map = PropertyMap()) const;
    
    SelectResult operator()(const MoleculeGroup &molgroup,
                            const PropertyMap &map = PropertyMap()) const;
    
    SelectResult operator()(const Molecules &molecules,
                            const PropertyMap &map = PropertyMap()) const;
    
    SelectResult operator()(const MoleculeView &molecule,
                            const PropertyMap &map = PropertyMap()) const;
    
protected:
    virtual ViewsOfMol selectFromMolecule(const MoleculeView &molecule,
                                          const PropertyMap &map) const=0;

    virtual SelectResult select(const MoleculeView &molecule,
                                const PropertyMap &map) const;

    virtual SelectResult select(const Molecules &molecules,
                                const PropertyMap &map) const;

    virtual SelectResult select(const MoleculeGroup &molgroup,
                                const PropertyMap &map) const;
    
    virtual SelectResult select(const MolGroupsBase &molgroups,
                                const PropertyMap &map) const;
};

using SelectEnginePtr = boost::shared_ptr<SelectEngine>;

} //end of namespace parser

/** This is the only publicly visible selector class. This provides a 
    front-end interface to selecting atoms and molecules
    
    @author Christopher Woods
*/
class SIREMOL_EXPORT Select : public SireBase::ConcreteProperty<Select,SireBase::Property>
{

friend QDataStream& ::operator<<(QDataStream&, const Select&);
friend QDataStream& ::operator>>(QDataStream&, Select&);

public:
    Select();
    Select(const QString &str);
    
    Select(const Select &other);
    
    ~Select();
    
    Select& operator=(const Select &other);
    
    bool operator==(const Select &other) const;
    bool operator!=(const Select &other) const;

    Select* clone() const;
    
    const char* what() const;
    static const char* typeName();
    
    QString toString() const;

    SelectResult operator()(const MolGroupsBase &molgroups,
                            const PropertyMap &map = PropertyMap()) const;
    
    SelectResult operator()(const MoleculeGroup &molgroup,
                            const PropertyMap &map = PropertyMap()) const;
    
    SelectResult operator()(const Molecules &molecules,
                            const PropertyMap &map = PropertyMap()) const;
    
    SelectResult operator()(const MoleculeView &molecule,
                            const PropertyMap &map = PropertyMap()) const;

    static void setToken(const QString &token, const QString &selection);
    static void resetTokens();

private:
    /** The actual search string */
    QString search_string;

    /** The underlying engine used to perform the selection */
    parser::SelectEnginePtr e;
};

/** This class holds the result of a Select 

    @author Christopher Woods
*/
class SIREMOL_EXPORT SelectResult
    : public SireBase::ConcreteProperty<SelectResult,SireBase::Property>
{

friend QDataStream& ::operator<<(QDataStream &ds, const SelectResult&);
friend QDataStream& ::operator>>(QDataStream &ds, SelectResult&);

public:
    SelectResult();
    
    SelectResult(const MolGroupsBase &molgroups);
    SelectResult(const MoleculeGroup &molgroup);
    SelectResult(const Molecules &molecules);
    SelectResult(const MoleculeView &molview);
    
    SelectResult(const QList<ViewsOfMol> molviews);
    
    SelectResult(const SelectResult &other);

    ~SelectResult();

    SelectResult& operator=(const SelectResult &other);
    
    bool operator==(const SelectResult &other) const;
    bool operator!=(const SelectResult &other) const;
    
    static const char* typeName();
    
    const char* what() const;
    
    SelectResult* clone() const;

    QString toString() const;

    MolViewPtr operator[](int i) const;

    SelectResultMover move() const;
    
    bool isEmpty() const;
    
    int count() const;
    int size() const;

    QList<ViewsOfMol> views() const;

private:
    /** The list of all ViewsOfMol views */
    QList<ViewsOfMol> molviews;
};

/** This class provides a simple "move" interface to move all 
    views in a SelectResult 
    
    @author Christopher Woods
*/
class SIREMOL_EXPORT SelectResultMover
    : public SireBase::ConcreteProperty<SelectResultMover,SireBase::Property>
{

friend QDataStream& ::operator<<(QDataStream &ds, const SelectResultMover&);
friend QDataStream& ::operator>>(QDataStream &ds, SelectResultMover&);

public:
    SelectResultMover();
    SelectResultMover(const SelectResult &other);
    
    SelectResultMover(const SelectResultMover &other);
    
    ~SelectResultMover();

    SelectResultMover& operator=(const SelectResultMover &other);
    
    bool operator==(const SelectResultMover &other) const;
    bool operator!=(const SelectResultMover &other) const;
    
    static const char* typeName();
    
    const char* what() const;
    
    SelectResultMover* clone() const;

    QString toString() const;
    
    SelectResultMover& translate(const Vector &delta);
    
    SelectResult commit() const;

private:
    /** All of the views that will be moved */
    QList< Mover<ViewsOfMol> > molviews;
};

} //end of namespace SireMol

Q_DECLARE_METATYPE( SireMol::Select )
Q_DECLARE_METATYPE( SireMol::SelectResult )
Q_DECLARE_METATYPE( SireMol::SelectResultMover )

SIRE_EXPOSE_CLASS( SireMol::Select )
SIRE_EXPOSE_CLASS( SireMol::SelectResult )
SIRE_EXPOSE_CLASS( SireMol::SelectResultMover )

SIRE_END_HEADER

#endif
