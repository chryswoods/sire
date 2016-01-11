// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "Helpers/clone_const_reference.hpp"
#include "IntraFF.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/booleanproperty.h"

#include "SireBase/errors.h"

#include "SireBase/lengthproperty.h"

#include "SireError/errors.h"

#include "SireMol/atomselection.h"

#include "SireMol/molecule.h"

#include "SireMol/molecules.h"

#include "SireMol/molresid.h"

#include "SireMol/partialmolecule.h"

#include "SireMol/residue.h"

#include "SireMol/selector.hpp"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "SireUnits/units.h"

#include "cljcalculator.h"

#include "cljshiftfunction.h"

#include "intraff.h"

#include <QDebug>

#include <QElapsedTimer>

#include "intraff.h"

SireMM::IntraFF __copy__(const SireMM::IntraFF &other){ return SireMM::IntraFF(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

#include "Helpers/len.hpp"

void register_IntraFF_class(){

    { //::SireMM::IntraFF
        typedef bp::class_< SireMM::IntraFF, bp::bases< SireFF::G1FF, SireFF::FF, SireMol::MolGroupsBase, SireBase::Property > > IntraFF_exposer_t;
        IntraFF_exposer_t IntraFF_exposer = IntraFF_exposer_t( "IntraFF", bp::init< >() );
        bp::scope IntraFF_scope( IntraFF_exposer );
        IntraFF_exposer.def( bp::init< QString const & >(( bp::arg("name") )) );
        IntraFF_exposer.def( bp::init< SireMM::IntraFF const & >(( bp::arg("other") )) );
        { //::SireMM::IntraFF::accept
        
            typedef void ( ::SireMM::IntraFF::*accept_function_type)(  ) ;
            accept_function_type accept_function_value( &::SireMM::IntraFF::accept );
            
            IntraFF_exposer.def( 
                "accept"
                , accept_function_value );
        
        }
        { //::SireMM::IntraFF::cljFunction
        
            typedef ::SireMM::CLJIntraFunction const & ( ::SireMM::IntraFF::*cljFunction_function_type)(  ) const;
            cljFunction_function_type cljFunction_function_value( &::SireMM::IntraFF::cljFunction );
            
            IntraFF_exposer.def( 
                "cljFunction"
                , cljFunction_function_value
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::SireMM::IntraFF::cljFunction
        
            typedef ::SireMM::CLJIntraFunction const & ( ::SireMM::IntraFF::*cljFunction_function_type)( ::QString ) const;
            cljFunction_function_type cljFunction_function_value( &::SireMM::IntraFF::cljFunction );
            
            IntraFF_exposer.def( 
                "cljFunction"
                , cljFunction_function_value
                , ( bp::arg("key") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::SireMM::IntraFF::cljFunctionKeys
        
            typedef ::QStringList ( ::SireMM::IntraFF::*cljFunctionKeys_function_type)(  ) const;
            cljFunctionKeys_function_type cljFunctionKeys_function_value( &::SireMM::IntraFF::cljFunctionKeys );
            
            IntraFF_exposer.def( 
                "cljFunctionKeys"
                , cljFunctionKeys_function_value );
        
        }
        { //::SireMM::IntraFF::cljFunctions
        
            typedef ::QHash< QString, SireBase::PropPtr< SireMM::CLJFunction > > ( ::SireMM::IntraFF::*cljFunctions_function_type)(  ) const;
            cljFunctions_function_type cljFunctions_function_value( &::SireMM::IntraFF::cljFunctions );
            
            IntraFF_exposer.def( 
                "cljFunctions"
                , cljFunctions_function_value );
        
        }
        { //::SireMM::IntraFF::components
        
            typedef ::SireMM::MultiCLJComponent const & ( ::SireMM::IntraFF::*components_function_type)(  ) const;
            components_function_type components_function_value( &::SireMM::IntraFF::components );
            
            IntraFF_exposer.def( 
                "components"
                , components_function_value
                , bp::return_value_policy<bp::clone_const_reference>() );
        
        }
        { //::SireMM::IntraFF::containsProperty
        
            typedef bool ( ::SireMM::IntraFF::*containsProperty_function_type)( ::QString const & ) const;
            containsProperty_function_type containsProperty_function_value( &::SireMM::IntraFF::containsProperty );
            
            IntraFF_exposer.def( 
                "containsProperty"
                , containsProperty_function_value
                , ( bp::arg("name") ) );
        
        }
        { //::SireMM::IntraFF::disableParallelCalculation
        
            typedef void ( ::SireMM::IntraFF::*disableParallelCalculation_function_type)(  ) ;
            disableParallelCalculation_function_type disableParallelCalculation_function_value( &::SireMM::IntraFF::disableParallelCalculation );
            
            IntraFF_exposer.def( 
                "disableParallelCalculation"
                , disableParallelCalculation_function_value );
        
        }
        { //::SireMM::IntraFF::disableReproducibleCalculation
        
            typedef void ( ::SireMM::IntraFF::*disableReproducibleCalculation_function_type)(  ) ;
            disableReproducibleCalculation_function_type disableReproducibleCalculation_function_value( &::SireMM::IntraFF::disableReproducibleCalculation );
            
            IntraFF_exposer.def( 
                "disableReproducibleCalculation"
                , disableReproducibleCalculation_function_value );
        
        }
        { //::SireMM::IntraFF::enableParallelCalculation
        
            typedef void ( ::SireMM::IntraFF::*enableParallelCalculation_function_type)(  ) ;
            enableParallelCalculation_function_type enableParallelCalculation_function_value( &::SireMM::IntraFF::enableParallelCalculation );
            
            IntraFF_exposer.def( 
                "enableParallelCalculation"
                , enableParallelCalculation_function_value );
        
        }
        { //::SireMM::IntraFF::enableReproducibleCalculation
        
            typedef void ( ::SireMM::IntraFF::*enableReproducibleCalculation_function_type)(  ) ;
            enableReproducibleCalculation_function_type enableReproducibleCalculation_function_value( &::SireMM::IntraFF::enableReproducibleCalculation );
            
            IntraFF_exposer.def( 
                "enableReproducibleCalculation"
                , enableReproducibleCalculation_function_value );
        
        }
        { //::SireMM::IntraFF::mustNowRecalculateFromScratch
        
            typedef void ( ::SireMM::IntraFF::*mustNowRecalculateFromScratch_function_type)(  ) ;
            mustNowRecalculateFromScratch_function_type mustNowRecalculateFromScratch_function_value( &::SireMM::IntraFF::mustNowRecalculateFromScratch );
            
            IntraFF_exposer.def( 
                "mustNowRecalculateFromScratch"
                , mustNowRecalculateFromScratch_function_value );
        
        }
        { //::SireMM::IntraFF::nCLJFunctions
        
            typedef int ( ::SireMM::IntraFF::*nCLJFunctions_function_type)(  ) const;
            nCLJFunctions_function_type nCLJFunctions_function_value( &::SireMM::IntraFF::nCLJFunctions );
            
            IntraFF_exposer.def( 
                "nCLJFunctions"
                , nCLJFunctions_function_value );
        
        }
        { //::SireMM::IntraFF::needsAccepting
        
            typedef bool ( ::SireMM::IntraFF::*needsAccepting_function_type)(  ) const;
            needsAccepting_function_type needsAccepting_function_value( &::SireMM::IntraFF::needsAccepting );
            
            IntraFF_exposer.def( 
                "needsAccepting"
                , needsAccepting_function_value );
        
        }
        IntraFF_exposer.def( bp::self != bp::self );
        { //::SireMM::IntraFF::operator=
        
            typedef ::SireMM::IntraFF & ( ::SireMM::IntraFF::*assign_function_type)( ::SireMM::IntraFF const & ) ;
            assign_function_type assign_function_value( &::SireMM::IntraFF::operator= );
            
            IntraFF_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
        IntraFF_exposer.def( bp::self == bp::self );
        { //::SireMM::IntraFF::properties
        
            typedef ::SireBase::Properties const & ( ::SireMM::IntraFF::*properties_function_type)(  ) const;
            properties_function_type properties_function_value( &::SireMM::IntraFF::properties );
            
            IntraFF_exposer.def( 
                "properties"
                , properties_function_value
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::SireMM::IntraFF::property
        
            typedef ::SireBase::Property const & ( ::SireMM::IntraFF::*property_function_type)( ::QString const & ) const;
            property_function_type property_function_value( &::SireMM::IntraFF::property );
            
            IntraFF_exposer.def( 
                "property"
                , property_function_value
                , ( bp::arg("name") )
                , bp::return_value_policy<bp::clone_const_reference>() );
        
        }
        { //::SireMM::IntraFF::removeAllCLJFunctions
        
            typedef void ( ::SireMM::IntraFF::*removeAllCLJFunctions_function_type)(  ) ;
            removeAllCLJFunctions_function_type removeAllCLJFunctions_function_value( &::SireMM::IntraFF::removeAllCLJFunctions );
            
            IntraFF_exposer.def( 
                "removeAllCLJFunctions"
                , removeAllCLJFunctions_function_value );
        
        }
        { //::SireMM::IntraFF::removeCLJFunctionAt
        
            typedef void ( ::SireMM::IntraFF::*removeCLJFunctionAt_function_type)( ::QString ) ;
            removeCLJFunctionAt_function_type removeCLJFunctionAt_function_value( &::SireMM::IntraFF::removeCLJFunctionAt );
            
            IntraFF_exposer.def( 
                "removeCLJFunctionAt"
                , removeCLJFunctionAt_function_value
                , ( bp::arg("key") ) );
        
        }
        { //::SireMM::IntraFF::setCLJFunction
        
            typedef void ( ::SireMM::IntraFF::*setCLJFunction_function_type)( ::SireMM::CLJIntraFunction const & ) ;
            setCLJFunction_function_type setCLJFunction_function_value( &::SireMM::IntraFF::setCLJFunction );
            
            IntraFF_exposer.def( 
                "setCLJFunction"
                , setCLJFunction_function_value
                , ( bp::arg("cljfunc") ) );
        
        }
        { //::SireMM::IntraFF::setCLJFunction
        
            typedef void ( ::SireMM::IntraFF::*setCLJFunction_function_type)( ::QString,::SireMM::CLJIntraFunction const & ) ;
            setCLJFunction_function_type setCLJFunction_function_value( &::SireMM::IntraFF::setCLJFunction );
            
            IntraFF_exposer.def( 
                "setCLJFunction"
                , setCLJFunction_function_value
                , ( bp::arg("key"), bp::arg("cljfunc") ) );
        
        }
        { //::SireMM::IntraFF::setProperty
        
            typedef bool ( ::SireMM::IntraFF::*setProperty_function_type)( ::QString const &,::SireBase::Property const & ) ;
            setProperty_function_type setProperty_function_value( &::SireMM::IntraFF::setProperty );
            
            IntraFF_exposer.def( 
                "setProperty"
                , setProperty_function_value
                , ( bp::arg("name"), bp::arg("property") ) );
        
        }
        { //::SireMM::IntraFF::setUseParallelCalculation
        
            typedef void ( ::SireMM::IntraFF::*setUseParallelCalculation_function_type)( bool ) ;
            setUseParallelCalculation_function_type setUseParallelCalculation_function_value( &::SireMM::IntraFF::setUseParallelCalculation );
            
            IntraFF_exposer.def( 
                "setUseParallelCalculation"
                , setUseParallelCalculation_function_value
                , ( bp::arg("on") ) );
        
        }
        { //::SireMM::IntraFF::setUseReproducibleCalculation
        
            typedef void ( ::SireMM::IntraFF::*setUseReproducibleCalculation_function_type)( bool ) ;
            setUseReproducibleCalculation_function_type setUseReproducibleCalculation_function_value( &::SireMM::IntraFF::setUseReproducibleCalculation );
            
            IntraFF_exposer.def( 
                "setUseReproducibleCalculation"
                , setUseReproducibleCalculation_function_value
                , ( bp::arg("on") ) );
        
        }
        { //::SireMM::IntraFF::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMM::IntraFF::typeName );
            
            IntraFF_exposer.def( 
                "typeName"
                , typeName_function_value );
        
        }
        { //::SireMM::IntraFF::usesParallelCalculation
        
            typedef bool ( ::SireMM::IntraFF::*usesParallelCalculation_function_type)(  ) const;
            usesParallelCalculation_function_type usesParallelCalculation_function_value( &::SireMM::IntraFF::usesParallelCalculation );
            
            IntraFF_exposer.def( 
                "usesParallelCalculation"
                , usesParallelCalculation_function_value );
        
        }
        { //::SireMM::IntraFF::usesReproducibleCalculation
        
            typedef bool ( ::SireMM::IntraFF::*usesReproducibleCalculation_function_type)(  ) const;
            usesReproducibleCalculation_function_type usesReproducibleCalculation_function_value( &::SireMM::IntraFF::usesReproducibleCalculation );
            
            IntraFF_exposer.def( 
                "usesReproducibleCalculation"
                , usesReproducibleCalculation_function_value );
        
        }
        { //::SireMM::IntraFF::what
        
            typedef char const * ( ::SireMM::IntraFF::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireMM::IntraFF::what );
            
            IntraFF_exposer.def( 
                "what"
                , what_function_value );
        
        }
        IntraFF_exposer.staticmethod( "typeName" );
        IntraFF_exposer.def( "__copy__", &__copy__);
        IntraFF_exposer.def( "__deepcopy__", &__copy__);
        IntraFF_exposer.def( "clone", &__copy__);
        IntraFF_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMM::IntraFF >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        IntraFF_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMM::IntraFF >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        IntraFF_exposer.def( "__str__", &__str__< ::SireMM::IntraFF > );
        IntraFF_exposer.def( "__repr__", &__str__< ::SireMM::IntraFF > );
        IntraFF_exposer.def( "__len__", &__len_count< ::SireMM::IntraFF > );
    }

}