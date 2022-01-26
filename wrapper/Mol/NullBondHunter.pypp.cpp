// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "NullBondHunter.pypp.hpp"

namespace bp = boost::python;

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "SireVol/coordgroup.h"

#include "atom.h"

#include "atomcoords.h"

#include "atomelements.h"

#include "atomselection.h"

#include "bondhunter.h"

#include "connectivity.h"

#include "molecule.h"

#include "moleculedata.h"

#include "moleculeinfodata.h"

#include "moleculeview.h"

#include "mover.hpp"

#include "selector.hpp"

#include <QDebug>

#include <QMutex>

#include "bondhunter.h"

SireMol::NullBondHunter __copy__(const SireMol::NullBondHunter &other){ return SireMol::NullBondHunter(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

void register_NullBondHunter_class(){

    { //::SireMol::NullBondHunter
        typedef bp::class_< SireMol::NullBondHunter, bp::bases< SireMol::BondHunter, SireBase::Property > > NullBondHunter_exposer_t;
        NullBondHunter_exposer_t NullBondHunter_exposer = NullBondHunter_exposer_t( "NullBondHunter", "This is a null bond hunter. This finds no bonds in a molecule and is used\nwhen you want to create an empty connectivity object for a molecule\n\nAuthor: Christopher Woods\n", bp::init< >("Constructor") );
        bp::scope NullBondHunter_scope( NullBondHunter_exposer );
        NullBondHunter_exposer.def( bp::init< SireMol::NullBondHunter const & >(( bp::arg("other") ), "Copy constructor") );
        { //::SireMol::NullBondHunter::operator()
        
            typedef ::SireMol::Connectivity ( ::SireMol::NullBondHunter::*__call___function_type)( ::SireMol::MoleculeView const &,::SireBase::PropertyMap const & ) const;
            __call___function_type __call___function_value( &::SireMol::NullBondHunter::operator() );
            
            NullBondHunter_exposer.def( 
                "__call__"
                , __call___function_value
                , ( bp::arg("molview"), bp::arg("map")=SireBase::PropertyMap() )
                , "" );
        
        }
        { //::SireMol::NullBondHunter::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::NullBondHunter::typeName );
            
            NullBondHunter_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        { //::SireMol::NullBondHunter::what
        
            typedef char const * ( ::SireMol::NullBondHunter::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireMol::NullBondHunter::what );
            
            NullBondHunter_exposer.def( 
                "what"
                , what_function_value
                , "" );
        
        }
        NullBondHunter_exposer.staticmethod( "typeName" );
        NullBondHunter_exposer.def( "__copy__", &__copy__);
        NullBondHunter_exposer.def( "__deepcopy__", &__copy__);
        NullBondHunter_exposer.def( "clone", &__copy__);
        NullBondHunter_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMol::NullBondHunter >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        NullBondHunter_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMol::NullBondHunter >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        NullBondHunter_exposer.def_pickle(sire_pickle_suite< ::SireMol::NullBondHunter >());
        NullBondHunter_exposer.def( "__str__", &__str__< ::SireMol::NullBondHunter > );
        NullBondHunter_exposer.def( "__repr__", &__str__< ::SireMol::NullBondHunter > );
    }

}
