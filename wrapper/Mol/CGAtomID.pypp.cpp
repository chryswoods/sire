// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 3 License

#include "boost/python.hpp"
#include "CGAtomID.pypp.hpp"

namespace bp = boost::python;

#include "SireMol/errors.h"

#include "SireStream/datastream.h"

#include "atomidentifier.h"

#include "cgidentifier.h"

#include "chainidentifier.h"

#include "groupatomids.h"

#include "residentifier.h"

#include "segidentifier.h"

#include "groupatomids.h"

SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID> __copy__(const SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID> &other){ return SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID>(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

#include "Helpers/release_gil_policy.hpp"

void register_CGAtomID_class(){

    { //::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >
        typedef bp::class_< SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >, bp::bases< SireMol::GroupAtomIDBase, SireMol::AtomID, SireID::ID > > CGAtomID_exposer_t;
        CGAtomID_exposer_t CGAtomID_exposer = CGAtomID_exposer_t( "CGAtomID", "", bp::init< >("") );
        bp::scope CGAtomID_scope( CGAtomID_exposer );
        CGAtomID_exposer.def( bp::init< SireMol::CGID const &, SireMol::AtomID const & >(( bp::arg("group"), bp::arg("atom") ), "") );
        CGAtomID_exposer.def( bp::init< SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID > const & >(( bp::arg("other") ), "") );
        { //::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::hash
        
            typedef SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID > exported_class_t;
            typedef ::uint ( ::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::*hash_function_type)(  ) const;
            hash_function_type hash_function_value( &::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::hash );
            
            CGAtomID_exposer.def( 
                "hash"
                , hash_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::isNull
        
            typedef SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID > exported_class_t;
            typedef bool ( ::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::*isNull_function_type)(  ) const;
            isNull_function_type isNull_function_value( &::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::isNull );
            
            CGAtomID_exposer.def( 
                "isNull"
                , isNull_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::map
        
            typedef SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID > exported_class_t;
            typedef ::QList< SireMol::AtomIdx > ( ::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::*map_function_type)( ::SireMol::MolInfo const & ) const;
            map_function_type map_function_value( &::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::map );
            
            CGAtomID_exposer.def( 
                "map"
                , map_function_value
                , ( bp::arg("molinfo") )
                , bp::release_gil_policy()
                , "" );
        
        }
        CGAtomID_exposer.def( bp::self != bp::self );
        CGAtomID_exposer.def( bp::self != bp::other< SireID::ID >() );
        CGAtomID_exposer.def( bp::self == bp::self );
        CGAtomID_exposer.def( bp::self == bp::other< SireID::ID >() );
        { //::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::toString
        
            typedef SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID > exported_class_t;
            typedef ::QString ( ::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::toString );
            
            CGAtomID_exposer.def( 
                "toString"
                , toString_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::typeName
        
            typedef SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID > exported_class_t;
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::typeName );
            
            CGAtomID_exposer.def( 
                "typeName"
                , typeName_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::what
        
            typedef SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID > exported_class_t;
            typedef char const * ( ::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireMol::GroupAtomID< SireMol::CGID, SireMol::AtomID >::what );
            
            CGAtomID_exposer.def( 
                "what"
                , what_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        CGAtomID_exposer.staticmethod( "typeName" );
        CGAtomID_exposer.def( "__copy__", &__copy__);
        CGAtomID_exposer.def( "__deepcopy__", &__copy__);
        CGAtomID_exposer.def( "clone", &__copy__);
        CGAtomID_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID> >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        CGAtomID_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID> >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        CGAtomID_exposer.def_pickle(sire_pickle_suite< ::SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID> >());
        CGAtomID_exposer.def( "__str__", &__str__< ::SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID> > );
        CGAtomID_exposer.def( "__repr__", &__str__< ::SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID> > );
        CGAtomID_exposer.def( "__hash__", &::SireMol::GroupAtomID<SireMol::CGID, SireMol::AtomID>::hash );
    }

}
