// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "HarmonicSwitchingFunction.pypp.hpp"

namespace bp = boost::python;

#include "SireFF/errors.h"

#include "SireMaths/maths.h"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "SireUnits/units.h"

#include "switchingfunction.h"

#include <QMutex>

#include <cmath>

#include <numeric>

#include "switchingfunction.h"

SireMM::HarmonicSwitchingFunction __copy__(const SireMM::HarmonicSwitchingFunction &other){ return SireMM::HarmonicSwitchingFunction(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

void register_HarmonicSwitchingFunction_class(){

    { //::SireMM::HarmonicSwitchingFunction
        typedef bp::class_< SireMM::HarmonicSwitchingFunction, bp::bases< SireMM::SwitchingFunction, SireBase::Property > > HarmonicSwitchingFunction_exposer_t;
        HarmonicSwitchingFunction_exposer_t HarmonicSwitchingFunction_exposer = HarmonicSwitchingFunction_exposer_t( "HarmonicSwitchingFunction", "This class implements harmonic switching functions - these scale the energy\nharmonically down to zero.\n\nAuthor: Christopher Woods\n", bp::init< >("Construct a null harmonic switching function (no cutoff)") );
        bp::scope HarmonicSwitchingFunction_scope( HarmonicSwitchingFunction_exposer );
        HarmonicSwitchingFunction_exposer.def( bp::init< SireUnits::Dimension::Length >(( bp::arg("cutoffdist") ), "Construct an harmonic switching function which represents a hard\ncutoff of both the electrostatic and vdw interactions at a distance\nof cutoffdist") );
        HarmonicSwitchingFunction_exposer.def( bp::init< SireUnits::Dimension::Length, SireUnits::Dimension::Length >(( bp::arg("cutoffdist"), bp::arg("featherdist") ), "Construct an harmonic switching function which represents the smoothed\ncutoff, with the cutoff at cutoffdist, but smoothed down using an\nharmonic function from featherdist. If featherdist >= cutoffdist\nthen this represents a hard cutoff") );
        HarmonicSwitchingFunction_exposer.def( bp::init< SireUnits::Dimension::Length, SireUnits::Dimension::Length, SireUnits::Dimension::Length >(( bp::arg("cutoffdist"), bp::arg("elecfeather"), bp::arg("vdwfeather") ), "Construct an harmonic switching function which represents the smoothed\ncutoff, with the cutoff at cutoffdist, but with the electrostatic\ninteractions smoothed down using a harmonic function from\nelecfeather and the vdw interactions smoothed down using\nan harmonic function from vdwfeather. If either feather distance\nis greater than the cutoff, then a hard cutoff for that interaction\nwill be used.") );
        HarmonicSwitchingFunction_exposer.def( bp::init< SireUnits::Dimension::Length, SireUnits::Dimension::Length, SireUnits::Dimension::Length, SireUnits::Dimension::Length >(( bp::arg("eleccutoff"), bp::arg("elecfeather"), bp::arg("vdwcutoff"), bp::arg("vdwfeather") ), "Construct an harmonic switching function which represents the smoothed\ncutoff, with the electrostatic interactions cutoff at eleccutoff, and\nsmoothed down using an harmonic function from elecfeather, and the\nvdw interactions cutoff at vdwcutoff and smoothed down using an\nharmonic function from vdwfeather. If either feather distance is\ngreater than the corresponding cutoff, then a hard cutoff will be\nused for that interaction.") );
        HarmonicSwitchingFunction_exposer.def( bp::init< SireMM::HarmonicSwitchingFunction const & >(( bp::arg("other") ), "Copy constructor") );
        { //::SireMM::HarmonicSwitchingFunction::dElectrostaticScaleFactor
        
            typedef double ( ::SireMM::HarmonicSwitchingFunction::*dElectrostaticScaleFactor_function_type)( ::SireUnits::Dimension::Length ) const;
            dElectrostaticScaleFactor_function_type dElectrostaticScaleFactor_function_value( &::SireMM::HarmonicSwitchingFunction::dElectrostaticScaleFactor );
            
            HarmonicSwitchingFunction_exposer.def( 
                "dElectrostaticScaleFactor"
                , dElectrostaticScaleFactor_function_value
                , ( bp::arg("dist") )
                , "This throws an exception as the harmonic switching function has\na discontinuous first derivative, so is not suitable for force evaluations\nThrow: SireFF::missing_derivative\n" );
        
        }
        { //::SireMM::HarmonicSwitchingFunction::dVDWScaleFactor
        
            typedef double ( ::SireMM::HarmonicSwitchingFunction::*dVDWScaleFactor_function_type)( ::SireUnits::Dimension::Length ) const;
            dVDWScaleFactor_function_type dVDWScaleFactor_function_value( &::SireMM::HarmonicSwitchingFunction::dVDWScaleFactor );
            
            HarmonicSwitchingFunction_exposer.def( 
                "dVDWScaleFactor"
                , dVDWScaleFactor_function_value
                , ( bp::arg("dist") )
                , "This throws an exception as the harmonic switching function has\na discontinuous first derivative, so is not suitable for force evaluations\nThrow: SireFF::missing_derivative\n" );
        
        }
        { //::SireMM::HarmonicSwitchingFunction::electrostaticScaleFactor
        
            typedef double ( ::SireMM::HarmonicSwitchingFunction::*electrostaticScaleFactor_function_type)( ::SireUnits::Dimension::Length ) const;
            electrostaticScaleFactor_function_type electrostaticScaleFactor_function_value( &::SireMM::HarmonicSwitchingFunction::electrostaticScaleFactor );
            
            HarmonicSwitchingFunction_exposer.def( 
                "electrostaticScaleFactor"
                , electrostaticScaleFactor_function_value
                , ( bp::arg("dist") )
                , "Return the scale factor for the electrostatic interaction for the\n" );
        
        }
        HarmonicSwitchingFunction_exposer.def( bp::self != bp::self );
        { //::SireMM::HarmonicSwitchingFunction::operator=
        
            typedef ::SireMM::HarmonicSwitchingFunction & ( ::SireMM::HarmonicSwitchingFunction::*assign_function_type)( ::SireMM::HarmonicSwitchingFunction const & ) ;
            assign_function_type assign_function_value( &::SireMM::HarmonicSwitchingFunction::operator= );
            
            HarmonicSwitchingFunction_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        HarmonicSwitchingFunction_exposer.def( bp::self == bp::self );
        { //::SireMM::HarmonicSwitchingFunction::toString
        
            typedef ::QString ( ::SireMM::HarmonicSwitchingFunction::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMM::HarmonicSwitchingFunction::toString );
            
            HarmonicSwitchingFunction_exposer.def( 
                "toString"
                , toString_function_value
                , "Return a string representation of this switching function" );
        
        }
        { //::SireMM::HarmonicSwitchingFunction::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMM::HarmonicSwitchingFunction::typeName );
            
            HarmonicSwitchingFunction_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        { //::SireMM::HarmonicSwitchingFunction::vdwScaleFactor
        
            typedef double ( ::SireMM::HarmonicSwitchingFunction::*vdwScaleFactor_function_type)( ::SireUnits::Dimension::Length ) const;
            vdwScaleFactor_function_type vdwScaleFactor_function_value( &::SireMM::HarmonicSwitchingFunction::vdwScaleFactor );
            
            HarmonicSwitchingFunction_exposer.def( 
                "vdwScaleFactor"
                , vdwScaleFactor_function_value
                , ( bp::arg("dist") )
                , "Return the scale factor for the vdw interaction for the\n" );
        
        }
        HarmonicSwitchingFunction_exposer.staticmethod( "typeName" );
        HarmonicSwitchingFunction_exposer.def( "__copy__", &__copy__);
        HarmonicSwitchingFunction_exposer.def( "__deepcopy__", &__copy__);
        HarmonicSwitchingFunction_exposer.def( "clone", &__copy__);
        HarmonicSwitchingFunction_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMM::HarmonicSwitchingFunction >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        HarmonicSwitchingFunction_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMM::HarmonicSwitchingFunction >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        HarmonicSwitchingFunction_exposer.def_pickle(sire_pickle_suite< ::SireMM::HarmonicSwitchingFunction >());
        HarmonicSwitchingFunction_exposer.def( "__str__", &__str__< ::SireMM::HarmonicSwitchingFunction > );
        HarmonicSwitchingFunction_exposer.def( "__repr__", &__str__< ::SireMM::HarmonicSwitchingFunction > );
    }

}
