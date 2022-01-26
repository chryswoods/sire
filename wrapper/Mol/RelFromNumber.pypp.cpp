// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "RelFromNumber.pypp.hpp"

namespace bp = boost::python;

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "atomselection.h"

#include "editor.hpp"

#include "evaluator.h"

#include "moleculedata.h"

#include "moleculeview.h"

#include "mover.hpp"

#include "partialmolecule.h"

#include "weightfunction.h"

#include "weightfunction.h"

SireMol::RelFromNumber __copy__(const SireMol::RelFromNumber &other){ return SireMol::RelFromNumber(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

void register_RelFromNumber_class(){

    { //::SireMol::RelFromNumber
        typedef bp::class_< SireMol::RelFromNumber, bp::bases< SireMol::WeightFunction, SireBase::Property > > RelFromNumber_exposer_t;
        RelFromNumber_exposer_t RelFromNumber_exposer = RelFromNumber_exposer_t( "RelFromNumber", "This class calculates the weight by assigning the weight based on the\nratio of the number of atoms in the two groups.\n\nAuthor: Christopher Woods\n", bp::init< >("") );
        bp::scope RelFromNumber_scope( RelFromNumber_exposer );
        RelFromNumber_exposer.def( bp::init< SireMol::RelFromNumber const & >(( bp::arg("other") ), "") );
        RelFromNumber_exposer.def( bp::self != bp::self );
        { //::SireMol::RelFromNumber::operator()
        
            typedef double ( ::SireMol::RelFromNumber::*__call___function_type)( ::SireMol::MoleculeData const &,::SireMol::AtomSelection const &,::SireMol::AtomSelection const &,::SireBase::PropertyMap const & ) const;
            __call___function_type __call___function_value( &::SireMol::RelFromNumber::operator() );
            
            RelFromNumber_exposer.def( 
                "__call__"
                , __call___function_value
                , ( bp::arg("moldata"), bp::arg("group0"), bp::arg("group1"), bp::arg("map")=SireBase::PropertyMap() )
                , "" );
        
        }
        { //::SireMol::RelFromNumber::operator()
        
            typedef double ( ::SireMol::RelFromNumber::*__call___function_type)( ::SireMol::MoleculeView const &,::SireBase::PropertyMap const &,::SireMol::MoleculeView const &,::SireBase::PropertyMap const & ) const;
            __call___function_type __call___function_value( &::SireMol::RelFromNumber::operator() );
            
            RelFromNumber_exposer.def( 
                "__call__"
                , __call___function_value
                , ( bp::arg("view0"), bp::arg("map0"), bp::arg("view1"), bp::arg("map1") )
                , "" );
        
        }
        { //::SireMol::RelFromNumber::operator=
        
            typedef ::SireMol::RelFromNumber & ( ::SireMol::RelFromNumber::*assign_function_type)( ::SireMol::RelFromNumber const & ) ;
            assign_function_type assign_function_value( &::SireMol::RelFromNumber::operator= );
            
            RelFromNumber_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("arg0") )
                , bp::return_self< >()
                , "" );
        
        }
        RelFromNumber_exposer.def( bp::self == bp::self );
        { //::SireMol::RelFromNumber::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::RelFromNumber::typeName );
            
            RelFromNumber_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        RelFromNumber_exposer.staticmethod( "typeName" );
        RelFromNumber_exposer.def( "__copy__", &__copy__);
        RelFromNumber_exposer.def( "__deepcopy__", &__copy__);
        RelFromNumber_exposer.def( "clone", &__copy__);
        RelFromNumber_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMol::RelFromNumber >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        RelFromNumber_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMol::RelFromNumber >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        RelFromNumber_exposer.def_pickle(sire_pickle_suite< ::SireMol::RelFromNumber >());
        RelFromNumber_exposer.def( "__str__", &__str__< ::SireMol::RelFromNumber > );
        RelFromNumber_exposer.def( "__repr__", &__str__< ::SireMol::RelFromNumber > );
    }

}
