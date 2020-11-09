// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "GromacsBond.pypp.hpp"

namespace bp = boost::python;

#include "SireCAS/conditional.h"

#include "SireCAS/exp.h"

#include "SireCAS/sum.h"

#include "SireCAS/trigfuncs.h"

#include "SireError/errors.h"

#include "SireID/index.h"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "SireUnits/units.h"

#include "amberparams.h"

#include "gromacsparams.h"

#include "gromacsparams.h"

SireMM::GromacsBond __copy__(const SireMM::GromacsBond &other){ return SireMM::GromacsBond(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

#include "Helpers/len.hpp"

void register_GromacsBond_class(){

    { //::SireMM::GromacsBond
        typedef bp::class_< SireMM::GromacsBond > GromacsBond_exposer_t;
        GromacsBond_exposer_t GromacsBond_exposer = GromacsBond_exposer_t( "GromacsBond", "This class holds all of the information about a Gromacs Bond\n\nAuthor: Christopher Woods\n", bp::init< >("Null constructor") );
        bp::scope GromacsBond_scope( GromacsBond_exposer );
        GromacsBond_exposer.def( bp::init< int >(( bp::arg("function_type") ), "Construct a bond that is of the specified type, but the parameters have yet\nto be resolved. This is because Gromacs can indicate the required type of\nfunction in the molecule specification, without providing the parameters") );
        GromacsBond_exposer.def( bp::init< int, double, bp::optional< double, double, double > >(( bp::arg("function_type"), bp::arg("k0"), bp::arg("k1")=0, bp::arg("k2")=0, bp::arg("k3")=0 ), "Construct a bond of the specified function type with specified parameters\n(the order should be the same as in the Gromacs Manual, table 5.5)") );
        GromacsBond_exposer.def( bp::init< int, QList< double > const & >(( bp::arg("function_type"), bp::arg("params") ), "Construct a bond of the specified function type by interpreting the parameter\ndata from the passed list of parameter values. These should be in the\nsame order as in the Gromacs Manual, table 5.5") );
        GromacsBond_exposer.def( bp::init< SireCAS::Expression const &, SireCAS::Symbol const & >(( bp::arg("bond"), bp::arg("R") ), "Construct from the passed bond, using R as the symbol for the R value") );
        GromacsBond_exposer.def( bp::init< SireMM::GromacsBond const & >(( bp::arg("other") ), "Copy constructor") );
        { //::SireMM::GromacsBond::assertResolved
        
            typedef void ( ::SireMM::GromacsBond::*assertResolved_function_type)(  ) const;
            assertResolved_function_type assertResolved_function_value( &::SireMM::GromacsBond::assertResolved );
            
            GromacsBond_exposer.def( 
                "assertResolved"
                , assertResolved_function_value
                , "Assert that the parameters for this bond have been resolved" );
        
        }
        { //::SireMM::GromacsBond::at
        
            typedef double ( ::SireMM::GromacsBond::*at_function_type)( int ) const;
            at_function_type at_function_value( &::SireMM::GromacsBond::at );
            
            GromacsBond_exposer.def( 
                "at"
                , at_function_value
                , ( bp::arg("i") )
                , "Return the ith parameter for this bond" );
        
        }
        { //::SireMM::GromacsBond::atomsAreBonded
        
            typedef bool ( ::SireMM::GromacsBond::*atomsAreBonded_function_type)(  ) const;
            atomsAreBonded_function_type atomsAreBonded_function_value( &::SireMM::GromacsBond::atomsAreBonded );
            
            GromacsBond_exposer.def( 
                "atomsAreBonded"
                , atomsAreBonded_function_value
                , "Return whether or not this GromacsBond implies that the atoms are actually\nbonded together" );
        
        }
        { //::SireMM::GromacsBond::count
        
            typedef int ( ::SireMM::GromacsBond::*count_function_type)(  ) const;
            count_function_type count_function_value( &::SireMM::GromacsBond::count );
            
            GromacsBond_exposer.def( 
                "count"
                , count_function_value
                , "Return the number of parameters associated with this bond type" );
        
        }
        { //::SireMM::GromacsBond::equilibriumLength
        
            typedef ::SireUnits::Dimension::Length ( ::SireMM::GromacsBond::*equilibriumLength_function_type)(  ) const;
            equilibriumLength_function_type equilibriumLength_function_value( &::SireMM::GromacsBond::equilibriumLength );
            
            GromacsBond_exposer.def( 
                "equilibriumLength"
                , equilibriumLength_function_value
                , "Return the equilibrium length of this bond" );
        
        }
        { //::SireMM::GromacsBond::functionType
        
            typedef int ( ::SireMM::GromacsBond::*functionType_function_type)(  ) const;
            functionType_function_type functionType_function_value( &::SireMM::GromacsBond::functionType );
            
            GromacsBond_exposer.def( 
                "functionType"
                , functionType_function_value
                , "Return the Gromacs ID number for the function type for this bond. See table\n5.5 in the Gromacs manual for information" );
        
        }
        { //::SireMM::GromacsBond::functionTypeString
        
            typedef ::QString ( ::SireMM::GromacsBond::*functionTypeString_function_type)(  ) const;
            functionTypeString_function_type functionTypeString_function_value( &::SireMM::GromacsBond::functionTypeString );
            
            GromacsBond_exposer.def( 
                "functionTypeString"
                , functionTypeString_function_value
                , "Return the string description of the function type for this bond" );
        
        }
        { //::SireMM::GromacsBond::hash
        
            typedef ::uint ( ::SireMM::GromacsBond::*hash_function_type)(  ) const;
            hash_function_type hash_function_value( &::SireMM::GromacsBond::hash );
            
            GromacsBond_exposer.def( 
                "hash"
                , hash_function_value
                , "Return a hash for this bond" );
        
        }
        { //::SireMM::GromacsBond::isHarmonic
        
            typedef bool ( ::SireMM::GromacsBond::*isHarmonic_function_type)(  ) const;
            isHarmonic_function_type isHarmonic_function_value( &::SireMM::GromacsBond::isHarmonic );
            
            GromacsBond_exposer.def( 
                "isHarmonic"
                , isHarmonic_function_value
                , "Return whether or not this is a harmonic bond" );
        
        }
        { //::SireMM::GromacsBond::isResolved
        
            typedef bool ( ::SireMM::GromacsBond::*isResolved_function_type)(  ) const;
            isResolved_function_type isResolved_function_value( &::SireMM::GromacsBond::isResolved );
            
            GromacsBond_exposer.def( 
                "isResolved"
                , isResolved_function_value
                , "Return whether or not the parameters for this bond are resolved" );
        
        }
        { //::SireMM::GromacsBond::isSimple
        
            typedef bool ( ::SireMM::GromacsBond::*isSimple_function_type)(  ) const;
            isSimple_function_type isSimple_function_value( &::SireMM::GromacsBond::isSimple );
            
            GromacsBond_exposer.def( 
                "isSimple"
                , isSimple_function_value
                , "All Gromacs bonds are simple (just a function of the bond length)" );
        
        }
        { //::SireMM::GromacsBond::needsResolving
        
            typedef bool ( ::SireMM::GromacsBond::*needsResolving_function_type)(  ) const;
            needsResolving_function_type needsResolving_function_value( &::SireMM::GromacsBond::needsResolving );
            
            GromacsBond_exposer.def( 
                "needsResolving"
                , needsResolving_function_value
                , "Return whether or not this parameter needs resolving" );
        
        }
        GromacsBond_exposer.def( bp::self != bp::self );
        GromacsBond_exposer.def( bp::self < bp::self );
        GromacsBond_exposer.def( bp::self <= bp::self );
        { //::SireMM::GromacsBond::operator=
        
            typedef ::SireMM::GromacsBond & ( ::SireMM::GromacsBond::*assign_function_type)( ::SireMM::GromacsBond const & ) ;
            assign_function_type assign_function_value( &::SireMM::GromacsBond::operator= );
            
            GromacsBond_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        GromacsBond_exposer.def( bp::self == bp::self );
        GromacsBond_exposer.def( bp::self > bp::self );
        GromacsBond_exposer.def( bp::self >= bp::self );
        { //::SireMM::GromacsBond::operator[]
        
            typedef double ( ::SireMM::GromacsBond::*__getitem___function_type)( int ) const;
            __getitem___function_type __getitem___function_value( &::SireMM::GromacsBond::operator[] );
            
            GromacsBond_exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMM::GromacsBond::parameters
        
            typedef ::QList< double > ( ::SireMM::GromacsBond::*parameters_function_type)(  ) const;
            parameters_function_type parameters_function_value( &::SireMM::GromacsBond::parameters );
            
            GromacsBond_exposer.def( 
                "parameters"
                , parameters_function_value
                , "Return all of the parameters for this bond" );
        
        }
        { //::SireMM::GromacsBond::size
        
            typedef int ( ::SireMM::GromacsBond::*size_function_type)(  ) const;
            size_function_type size_function_value( &::SireMM::GromacsBond::size );
            
            GromacsBond_exposer.def( 
                "size"
                , size_function_value
                , "Return the number of parameters associated with this bond type" );
        
        }
        { //::SireMM::GromacsBond::toExpression
        
            typedef ::SireCAS::Expression ( ::SireMM::GromacsBond::*toExpression_function_type)( ::SireCAS::Symbol const & ) const;
            toExpression_function_type toExpression_function_value( &::SireMM::GromacsBond::toExpression );
            
            GromacsBond_exposer.def( 
                "toExpression"
                , toExpression_function_value
                , ( bp::arg("R") )
                , "Return this function converted to a SireCAS::Expression using the passed symbol\nto represent the bond length" );
        
        }
        { //::SireMM::GromacsBond::toString
        
            typedef ::QString ( ::SireMM::GromacsBond::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMM::GromacsBond::toString );
            
            GromacsBond_exposer.def( 
                "toString"
                , toString_function_value
                , "Return a string representation of this bond" );
        
        }
        { //::SireMM::GromacsBond::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMM::GromacsBond::typeName );
            
            GromacsBond_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        { //::SireMM::GromacsBond::what
        
            typedef char const * ( ::SireMM::GromacsBond::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireMM::GromacsBond::what );
            
            GromacsBond_exposer.def( 
                "what"
                , what_function_value
                , "" );
        
        }
        GromacsBond_exposer.staticmethod( "typeName" );
        GromacsBond_exposer.def( "__copy__", &__copy__);
        GromacsBond_exposer.def( "__deepcopy__", &__copy__);
        GromacsBond_exposer.def( "clone", &__copy__);
        GromacsBond_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMM::GromacsBond >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        GromacsBond_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMM::GromacsBond >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        GromacsBond_exposer.def( "__str__", &__str__< ::SireMM::GromacsBond > );
        GromacsBond_exposer.def( "__repr__", &__str__< ::SireMM::GromacsBond > );
        GromacsBond_exposer.def( "__len__", &__len_size< ::SireMM::GromacsBond > );
        GromacsBond_exposer.def( "__hash__", &::SireMM::GromacsBond::hash );
    }

}
