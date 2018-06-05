// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "AtomIDMatcher.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/parallel.h"

#include "SireError/errors.h"

#include "SireStream/datastream.h"

#include "SireUnits/units.h"

#include "atomidentifier.h"

#include "atomidx.h"

#include "atommatcher.h"

#include "atommatchers.h"

#include "atomname.h"

#include "atomselection.h"

#include "evaluator.h"

#include "moleculeinfodata.h"

#include "moleculeview.h"

#include "tostring.h"

#include "atommatchers.h"

SireMol::AtomIDMatcher __copy__(const SireMol::AtomIDMatcher &other){ return SireMol::AtomIDMatcher(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

void register_AtomIDMatcher_class(){

    { //::SireMol::AtomIDMatcher
        typedef bp::class_< SireMol::AtomIDMatcher, bp::bases< SireMol::AtomMatcher, SireBase::Property > > AtomIDMatcher_exposer_t;
        AtomIDMatcher_exposer_t AtomIDMatcher_exposer = AtomIDMatcher_exposer_t( "AtomIDMatcher", "This is an atom matcher that allows the user to specify\nexactly how one atom matches another in the molecule\nby mapping one AtomIdentifier to another\n\nAuthor: Christopher Woods\n", bp::init< >("Constructor") );
        bp::scope AtomIDMatcher_scope( AtomIDMatcher_exposer );
        AtomIDMatcher_exposer.def( bp::init< QList< QPair< QString, QString > > const & >(( bp::arg("match_names") ), "Construct to match atom names") );
        AtomIDMatcher_exposer.def( bp::init< QList< QPair< int, int > > const & >(( bp::arg("match_idxs") ), "Construct to match atom indexes") );
        AtomIDMatcher_exposer.def( bp::init< QList< QPair< SireMol::AtomIdentifier, SireMol::AtomIdentifier > > const & >(( bp::arg("match_ids") ), "Construct to match specified AtomIdentifiers") );
        AtomIDMatcher_exposer.def( bp::init< QList< boost::tuples::tuple< QString, QString, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type > > const & >(( bp::arg("match_names") ), "Construct to match atom names") );
        AtomIDMatcher_exposer.def( bp::init< QList< boost::tuples::tuple< int, int, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type > > const & >(( bp::arg("match_idxs") ), "Construct to match specified AtomIdentifiers") );
        AtomIDMatcher_exposer.def( bp::init< QList< boost::tuples::tuple< SireMol::AtomIdentifier, SireMol::AtomIdentifier, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type > > const & >(( bp::arg("match_ids") ), "Construct to match specified AtomIdentifiers") );
        AtomIDMatcher_exposer.def( bp::init< QHash< QString, QString > const & >(( bp::arg("match_names") ), "Construct to match atom names") );
        AtomIDMatcher_exposer.def( bp::init< QHash< int, int > const & >(( bp::arg("match_idxs") ), "Construct to match atom indexes") );
        AtomIDMatcher_exposer.def( bp::init< QHash< SireMol::AtomIdentifier, SireMol::AtomIdentifier > const & >(( bp::arg("match_ids") ), "Construct to match specified AtomIdentifiers") );
        AtomIDMatcher_exposer.def( bp::init< QString const & >(( bp::arg("match_names") ), "Shorthand to construct to match atom names from the passed single string,\nwith format atom0:atom1,atom2:atom3 etc. (i.e. comma separated pairs,\neach pair is colon separated to match atom to atom, e.g. this string\nmatches atom0 to atom1, and atom2 to atom3)") );
        AtomIDMatcher_exposer.def( bp::init< SireMol::AtomIDMatcher const & >(( bp::arg("other") ), "Copy constructor") );
        { //::SireMol::AtomIDMatcher::isNull
        
            typedef bool ( ::SireMol::AtomIDMatcher::*isNull_function_type)(  ) const;
            isNull_function_type isNull_function_value( &::SireMol::AtomIDMatcher::isNull );
            
            AtomIDMatcher_exposer.def( 
                "isNull"
                , isNull_function_value
                , "Return whether or not this matcher is null (cannot be used for matching)" );
        
        }
        AtomIDMatcher_exposer.def( bp::self != bp::self );
        { //::SireMol::AtomIDMatcher::operator=
        
            typedef ::SireMol::AtomIDMatcher & ( ::SireMol::AtomIDMatcher::*assign_function_type)( ::SireMol::AtomIDMatcher const & ) ;
            assign_function_type assign_function_value( &::SireMol::AtomIDMatcher::operator= );
            
            AtomIDMatcher_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        AtomIDMatcher_exposer.def( bp::self == bp::self );
        { //::SireMol::AtomIDMatcher::toString
        
            typedef ::QString ( ::SireMol::AtomIDMatcher::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMol::AtomIDMatcher::toString );
            
            AtomIDMatcher_exposer.def( 
                "toString"
                , toString_function_value
                , "" );
        
        }
        { //::SireMol::AtomIDMatcher::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::AtomIDMatcher::typeName );
            
            AtomIDMatcher_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        { //::SireMol::AtomIDMatcher::what
        
            typedef char const * ( ::SireMol::AtomIDMatcher::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireMol::AtomIDMatcher::what );
            
            AtomIDMatcher_exposer.def( 
                "what"
                , what_function_value
                , "" );
        
        }
        AtomIDMatcher_exposer.staticmethod( "typeName" );
        AtomIDMatcher_exposer.def( "__copy__", &__copy__);
        AtomIDMatcher_exposer.def( "__deepcopy__", &__copy__);
        AtomIDMatcher_exposer.def( "clone", &__copy__);
        AtomIDMatcher_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMol::AtomIDMatcher >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        AtomIDMatcher_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMol::AtomIDMatcher >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        AtomIDMatcher_exposer.def( "__str__", &__str__< ::SireMol::AtomIDMatcher > );
        AtomIDMatcher_exposer.def( "__repr__", &__str__< ::SireMol::AtomIDMatcher > );
    }

}
