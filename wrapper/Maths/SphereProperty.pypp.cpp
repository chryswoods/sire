// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "SphereProperty.pypp.hpp"

namespace bp = boost::python;

#include "SireMaths/sphereproperty.h"

#include "sphereproperty.h"

#include "sphereproperty.h"

SireBase::PODProperty<SireMaths::Sphere> __copy__(const SireBase::PODProperty<SireMaths::Sphere> &other){ return SireBase::PODProperty<SireMaths::Sphere>(other); }

#include "Helpers/str.hpp"

#include "Helpers/release_gil_policy.hpp"

void register_SphereProperty_class(){

    { //::SireBase::PODProperty< SireMaths::Sphere >
        typedef bp::class_< SireBase::PODProperty< SireMaths::Sphere >, bp::bases< SireMaths::Sphere, SireBase::Property > > SphereProperty_exposer_t;
        SphereProperty_exposer_t SphereProperty_exposer = SphereProperty_exposer_t( "SphereProperty", "", bp::init< >("") );
        bp::scope SphereProperty_scope( SphereProperty_exposer );
        SphereProperty_exposer.def( bp::init< SireMaths::Sphere const & >(( bp::arg("value") ), "") );
        SphereProperty_exposer.def( bp::init< SireBase::PODProperty< SireMaths::Sphere > const & >(( bp::arg("other") ), "") );
        SphereProperty_exposer.def( bp::self != bp::self );
        SphereProperty_exposer.def( bp::self != bp::other< SireMaths::Sphere >() );
        { //::SireBase::PODProperty< SireMaths::Sphere >::operator=
        
            typedef SireBase::PODProperty< SireMaths::Sphere > exported_class_t;
            typedef ::SireBase::PODProperty< SireMaths::Sphere > & ( ::SireBase::PODProperty< SireMaths::Sphere >::*assign_function_type)( ::SireBase::PODProperty< SireMaths::Sphere > const & ) ;
            assign_function_type assign_function_value( &::SireBase::PODProperty< SireMaths::Sphere >::operator= );
            
            SphereProperty_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        SphereProperty_exposer.def( bp::self == bp::self );
        SphereProperty_exposer.def( bp::self == bp::other< SireMaths::Sphere >() );
        { //::SireBase::PODProperty< SireMaths::Sphere >::toString
        
            typedef SireBase::PODProperty< SireMaths::Sphere > exported_class_t;
            typedef ::QString ( ::SireBase::PODProperty< SireMaths::Sphere >::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireBase::PODProperty< SireMaths::Sphere >::toString );
            
            SphereProperty_exposer.def( 
                "toString"
                , toString_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireBase::PODProperty< SireMaths::Sphere >::typeName
        
            typedef SireBase::PODProperty< SireMaths::Sphere > exported_class_t;
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireBase::PODProperty< SireMaths::Sphere >::typeName );
            
            SphereProperty_exposer.def( 
                "typeName"
                , typeName_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireBase::PODProperty< SireMaths::Sphere >::what
        
            typedef SireBase::PODProperty< SireMaths::Sphere > exported_class_t;
            typedef char const * ( ::SireBase::PODProperty< SireMaths::Sphere >::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireBase::PODProperty< SireMaths::Sphere >::what );
            
            SphereProperty_exposer.def( 
                "what"
                , what_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        SphereProperty_exposer.staticmethod( "typeName" );
        SphereProperty_exposer.def( "__copy__", &__copy__);
        SphereProperty_exposer.def( "__deepcopy__", &__copy__);
        SphereProperty_exposer.def( "clone", &__copy__);
        SphereProperty_exposer.def( "__str__", &__str__< ::SireBase::PODProperty<SireMaths::Sphere> > );
        SphereProperty_exposer.def( "__repr__", &__str__< ::SireBase::PODProperty<SireMaths::Sphere> > );
    }

}
