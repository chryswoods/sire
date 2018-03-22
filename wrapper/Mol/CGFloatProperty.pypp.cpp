// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "CGFloatProperty.pypp.hpp"

namespace bp = boost::python;

#include "cgproperty.hpp"

#include "cgproperty.hpp"

#include "SireMaths/vector.h"

#include "SireMol/moleculeview.h"

SireMol::CGProperty<double> __copy__(const SireMol::CGProperty<double> &other){ return SireMol::CGProperty<double>(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

#include "Helpers/len.hpp"

void register_CGFloatProperty_class(){

    { //::SireMol::CGProperty< double >
        typedef bp::class_< SireMol::CGProperty< double >, bp::bases< SireMol::CGProp, SireMol::MolViewProperty, SireBase::Property > > CGFloatProperty_exposer_t;
        CGFloatProperty_exposer_t CGFloatProperty_exposer = CGFloatProperty_exposer_t( "CGFloatProperty", "", bp::init< >("") );
        bp::scope CGFloatProperty_scope( CGFloatProperty_exposer );
        CGFloatProperty_exposer.def( bp::init< SireMol::MoleculeInfoData const & >(( bp::arg("molinfo") ), "") );
        CGFloatProperty_exposer.def( bp::init< QVector< double > const & >(( bp::arg("values") ), "") );
        CGFloatProperty_exposer.def( bp::init< SireMol::CGProperty< double > const & >(( bp::arg("other") ), "") );
        { //::SireMol::CGProperty< double >::array
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef ::QVector< double > const & ( ::SireMol::CGProperty< double >::*array_function_type)(  ) const;
            array_function_type array_function_value( &::SireMol::CGProperty< double >::array );
            
            CGFloatProperty_exposer.def( 
                "array"
                , array_function_value
                , bp::return_value_policy< bp::copy_const_reference >()
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::assertCanConvert
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef void ( ::SireMol::CGProperty< double >::*assertCanConvert_function_type)( ::QVariant const & ) const;
            assertCanConvert_function_type assertCanConvert_function_value( &::SireMol::CGProperty< double >::assertCanConvert );
            
            CGFloatProperty_exposer.def( 
                "assertCanConvert"
                , assertCanConvert_function_value
                , ( bp::arg("value") )
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::assignFrom
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef void ( ::SireMol::CGProperty< double >::*assignFrom_function_type)( ::SireMol::CGProperty< QVariant > const & ) ;
            assignFrom_function_type assignFrom_function_value( &::SireMol::CGProperty< double >::assignFrom );
            
            CGFloatProperty_exposer.def( 
                "assignFrom"
                , assignFrom_function_value
                , ( bp::arg("variant") )
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::at
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef double const & ( ::SireMol::CGProperty< double >::*at_function_type)( ::SireMol::CGIdx const & ) const;
            at_function_type at_function_value( &::SireMol::CGProperty< double >::at );
            
            CGFloatProperty_exposer.def( 
                "at"
                , at_function_value
                , ( bp::arg("cgidx") )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::canConvert
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef bool ( ::SireMol::CGProperty< double >::*canConvert_function_type)( ::QVariant const & ) const;
            canConvert_function_type canConvert_function_value( &::SireMol::CGProperty< double >::canConvert );
            
            CGFloatProperty_exposer.def( 
                "canConvert"
                , canConvert_function_value
                , ( bp::arg("value") )
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::count
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef int ( ::SireMol::CGProperty< double >::*count_function_type)(  ) const;
            count_function_type count_function_value( &::SireMol::CGProperty< double >::count );
            
            CGFloatProperty_exposer.def( 
                "count"
                , count_function_value
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::fromVariant
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef ::SireMol::CGProperty< double > ( *fromVariant_function_type )( ::SireMol::CGProperty< QVariant > const & );
            fromVariant_function_type fromVariant_function_value( &::SireMol::CGProperty< double >::fromVariant );
            
            CGFloatProperty_exposer.def( 
                "fromVariant"
                , fromVariant_function_value
                , ( bp::arg("variant") )
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::get
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef double const & ( ::SireMol::CGProperty< double >::*get_function_type)( ::SireMol::CGIdx const & ) const;
            get_function_type get_function_value( &::SireMol::CGProperty< double >::get );
            
            CGFloatProperty_exposer.def( 
                "get"
                , get_function_value
                , ( bp::arg("cgidx") )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::isCompatibleWith
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef bool ( ::SireMol::CGProperty< double >::*isCompatibleWith_function_type)( ::SireMol::MoleculeInfoData const & ) const;
            isCompatibleWith_function_type isCompatibleWith_function_value( &::SireMol::CGProperty< double >::isCompatibleWith );
            
            CGFloatProperty_exposer.def( 
                "isCompatibleWith"
                , isCompatibleWith_function_value
                , ( bp::arg("molinfo") )
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::isEmpty
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef bool ( ::SireMol::CGProperty< double >::*isEmpty_function_type)(  ) const;
            isEmpty_function_type isEmpty_function_value( &::SireMol::CGProperty< double >::isEmpty );
            
            CGFloatProperty_exposer.def( 
                "isEmpty"
                , isEmpty_function_value
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::nCutGroups
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef int ( ::SireMol::CGProperty< double >::*nCutGroups_function_type)(  ) const;
            nCutGroups_function_type nCutGroups_function_value( &::SireMol::CGProperty< double >::nCutGroups );
            
            CGFloatProperty_exposer.def( 
                "nCutGroups"
                , nCutGroups_function_value
                , "" );
        
        }
        CGFloatProperty_exposer.def( bp::self != bp::self );
        { //::SireMol::CGProperty< double >::operator=
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef ::SireMol::CGProperty< double > & ( ::SireMol::CGProperty< double >::*assign_function_type)( ::SireMol::CGProperty< double > const & ) ;
            assign_function_type assign_function_value( &::SireMol::CGProperty< double >::operator= );
            
            CGFloatProperty_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        CGFloatProperty_exposer.def( bp::self == bp::self );
        { //::SireMol::CGProperty< double >::operator[]
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef double const & ( ::SireMol::CGProperty< double >::*__getitem___function_type)( ::SireMol::CGIdx const & ) const;
            __getitem___function_type __getitem___function_value( &::SireMol::CGProperty< double >::operator[] );
            
            CGFloatProperty_exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("cgidx") )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::set
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef ::SireMol::CGProperty< double > & ( ::SireMol::CGProperty< double >::*set_function_type)( ::SireMol::CGIdx,double const & ) ;
            set_function_type set_function_value( &::SireMol::CGProperty< double >::set );
            
            CGFloatProperty_exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("cgidx"), bp::arg("value") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::size
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef int ( ::SireMol::CGProperty< double >::*size_function_type)(  ) const;
            size_function_type size_function_value( &::SireMol::CGProperty< double >::size );
            
            CGFloatProperty_exposer.def( 
                "size"
                , size_function_value
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::toString
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef ::QString ( ::SireMol::CGProperty< double >::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMol::CGProperty< double >::toString );
            
            CGFloatProperty_exposer.def( 
                "toString"
                , toString_function_value
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::toVariant
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef ::SireMol::CGProperty< QVariant > ( ::SireMol::CGProperty< double >::*toVariant_function_type)(  ) const;
            toVariant_function_type toVariant_function_value( &::SireMol::CGProperty< double >::toVariant );
            
            CGFloatProperty_exposer.def( 
                "toVariant"
                , toVariant_function_value
                , "" );
        
        }
        { //::SireMol::CGProperty< double >::typeName
        
            typedef SireMol::CGProperty< double > exported_class_t;
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::CGProperty< double >::typeName );
            
            CGFloatProperty_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        CGFloatProperty_exposer.staticmethod( "fromVariant" );
        CGFloatProperty_exposer.staticmethod( "typeName" );
        CGFloatProperty_exposer.def( "__copy__", &__copy__);
        CGFloatProperty_exposer.def( "__deepcopy__", &__copy__);
        CGFloatProperty_exposer.def( "clone", &__copy__);
        CGFloatProperty_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMol::CGProperty<double> >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        CGFloatProperty_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMol::CGProperty<double> >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        CGFloatProperty_exposer.def( "__str__", &__str__< ::SireMol::CGProperty<double> > );
        CGFloatProperty_exposer.def( "__repr__", &__str__< ::SireMol::CGProperty<double> > );
        CGFloatProperty_exposer.def( "__len__", &__len_size< ::SireMol::CGProperty<double> > );
    }

}
