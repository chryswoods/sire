// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "Mover_Chain_.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/errors.h"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "atom.h"

#include "chain.h"

#include "chaineditor.h"

#include "chainresid.h"

#include "evaluator.h"

#include "groupatomids.h"

#include "molecule.h"

#include "mover.hpp"

#include "mover_metaid.h"

#include "residue.h"

#include "selector.hpp"

#include "chain.h"

#include "SireMaths/align.h"

#include "SireMaths/axisset.h"

#include "SireMaths/matrix.h"

#include "SireMaths/quaternion.h"

#include "SireMaths/rotate.h"

#include "SireMaths/vectorproperty.h"

#include "SireMol/errors.h"

#include "SireUnits/units.h"

#include "SireVol/coordgroup.h"

#include "SireVol/space.h"

#include "angleid.h"

#include "atomcoords.h"

#include "atommatcher.h"

#include "atommatchers.h"

#include "bondid.h"

#include "connectivity.h"

#include "dihedralid.h"

#include "improperid.h"

#include "mover.h"

#include "tostring.h"

#include "weightfunction.h"

#include "mover.h"

SireMol::Mover<SireMol::Chain> __copy__(const SireMol::Mover<SireMol::Chain> &other){ return SireMol::Mover<SireMol::Chain>(other); }

#include "Helpers/str.hpp"

#include "Helpers/len.hpp"

void register_Mover_Chain__class(){

    { //::SireMol::Mover< SireMol::Chain >
        typedef bp::class_< SireMol::Mover< SireMol::Chain >, bp::bases< SireMol::MoverBase, SireMol::Chain, SireMol::MoleculeView, SireBase::Property > > Mover_Chain__exposer_t;
        Mover_Chain__exposer_t Mover_Chain__exposer = Mover_Chain__exposer_t( "Mover_Chain_", "", bp::init< >("") );
        bp::scope Mover_Chain__scope( Mover_Chain__exposer );
        Mover_Chain__exposer.def( bp::init< SireMol::Chain const & >(( bp::arg("view") ), "") );
        Mover_Chain__exposer.def( bp::init< SireMol::Chain const &, SireMol::AtomSelection const & >(( bp::arg("view"), bp::arg("movable_atoms") ), "") );
        Mover_Chain__exposer.def( bp::init< SireMol::Mover< SireMol::Chain > const & >(( bp::arg("other") ), "") );
        { //::SireMol::Mover< SireMol::Chain >::align
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*align_function_type)( ::SireMol::MoleculeView const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMol::Chain >::align );
            
            Mover_Chain__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::align
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*align_function_type)( ::SireMol::MoleculeView const &,::SireBase::PropertyMap const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMol::Chain >::align );
            
            Mover_Chain__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("map0"), bp::arg("map1") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::align
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*align_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMol::Chain >::align );
            
            Mover_Chain__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("matcher"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::align
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*align_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMol::Chain >::align );
            
            Mover_Chain__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("matcher"), bp::arg("map0"), bp::arg("map1") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::alignTo
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*alignTo_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const & ) ;
            alignTo_function_type alignTo_function_value( &::SireMol::Mover< SireMol::Chain >::alignTo );
            
            Mover_Chain__exposer.def( 
                "alignTo"
                , alignTo_function_value
                , ( bp::arg("other"), bp::arg("matcher"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::alignTo
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*alignTo_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const &,::SireBase::PropertyMap const & ) ;
            alignTo_function_type alignTo_function_value( &::SireMol::Mover< SireMol::Chain >::alignTo );
            
            Mover_Chain__exposer.def( 
                "alignTo"
                , alignTo_function_value
                , ( bp::arg("other"), bp::arg("matcher"), bp::arg("map0"), bp::arg("map1") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::alignTo
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*alignTo_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomSelection const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const & ) ;
            alignTo_function_type alignTo_function_value( &::SireMol::Mover< SireMol::Chain >::alignTo );
            
            Mover_Chain__exposer.def( 
                "alignTo"
                , alignTo_function_value
                , ( bp::arg("other"), bp::arg("aligning_atoms"), bp::arg("matcher"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::alignTo
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*alignTo_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomSelection const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const &,::SireBase::PropertyMap const & ) ;
            alignTo_function_type alignTo_function_value( &::SireMol::Mover< SireMol::Chain >::alignTo );
            
            Mover_Chain__exposer.def( 
                "alignTo"
                , alignTo_function_value
                , ( bp::arg("other"), bp::arg("aligning_atoms"), bp::arg("matcher"), bp::arg("map0"), bp::arg("map1") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::change
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*change_function_type)( ::SireMol::BondID const &,::SireUnits::Dimension::Length,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMol::Chain >::change );
            
            Mover_Chain__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("bond"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::change
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*change_function_type)( ::SireMol::AngleID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMol::Chain >::change );
            
            Mover_Chain__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("angle"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::change
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*change_function_type)( ::SireMol::DihedralID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMol::Chain >::change );
            
            Mover_Chain__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("dihedral"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::change
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*change_function_type)( ::SireMol::BondID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMol::Chain >::change );
            
            Mover_Chain__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("bond"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::change
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*change_function_type)( ::SireMol::ImproperID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMol::Chain >::change );
            
            Mover_Chain__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("improper"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::changeFrame
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*changeFrame_function_type)( ::SireMaths::AxisSet const &,::SireMaths::AxisSet const &,::SireBase::PropertyMap const & ) ;
            changeFrame_function_type changeFrame_function_value( &::SireMol::Mover< SireMol::Chain >::changeFrame );
            
            Mover_Chain__exposer.def( 
                "changeFrame"
                , changeFrame_function_value
                , ( bp::arg("from_frame"), bp::arg("to_frame"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::commit
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Chain ( ::SireMol::Mover< SireMol::Chain >::*commit_function_type)(  ) const;
            commit_function_type commit_function_value( &::SireMol::Mover< SireMol::Chain >::commit );
            
            Mover_Chain__exposer.def( 
                "commit"
                , commit_function_value
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::mapInto
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*mapInto_function_type)( ::SireMaths::AxisSet const &,::SireBase::PropertyMap const & ) ;
            mapInto_function_type mapInto_function_value( &::SireMol::Mover< SireMol::Chain >::mapInto );
            
            Mover_Chain__exposer.def( 
                "mapInto"
                , mapInto_function_value
                , ( bp::arg("axes"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::operator=
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*assign_function_type)( ::SireMol::Mover< SireMol::Chain > const & ) ;
            assign_function_type assign_function_value( &::SireMol::Mover< SireMol::Chain >::operator= );
            
            Mover_Chain__exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::operator=
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*assign_function_type)( ::SireMol::Chain const & ) ;
            assign_function_type assign_function_value( &::SireMol::Mover< SireMol::Chain >::operator= );
            
            Mover_Chain__exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::rotate
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*rotate_function_type)( ::SireMaths::Quaternion const &,::SireMaths::Vector const &,::SireBase::PropertyMap const & ) ;
            rotate_function_type rotate_function_value( &::SireMol::Mover< SireMol::Chain >::rotate );
            
            Mover_Chain__exposer.def( 
                "rotate"
                , rotate_function_value
                , ( bp::arg("quat"), bp::arg("point"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::rotate
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*rotate_function_type)( ::SireMaths::Matrix const &,::SireMaths::Vector const &,::SireBase::PropertyMap const & ) ;
            rotate_function_type rotate_function_value( &::SireMol::Mover< SireMol::Chain >::rotate );
            
            Mover_Chain__exposer.def( 
                "rotate"
                , rotate_function_value
                , ( bp::arg("rotmat"), bp::arg("point"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::set
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*set_function_type)( ::SireMol::BondID const &,::SireUnits::Dimension::Length,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMol::Chain >::set );
            
            Mover_Chain__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("bond"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::set
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*set_function_type)( ::SireMol::AngleID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMol::Chain >::set );
            
            Mover_Chain__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("angle"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::set
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*set_function_type)( ::SireMol::DihedralID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMol::Chain >::set );
            
            Mover_Chain__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("dihedral"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::set
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*set_function_type)( ::SireMol::ImproperID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMol::Chain >::set );
            
            Mover_Chain__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("improper"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::setAll
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*setAll_function_type)( ::SireMol::DihedralID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            setAll_function_type setAll_function_value( &::SireMol::Mover< SireMol::Chain >::setAll );
            
            Mover_Chain__exposer.def( 
                "setAll"
                , setAll_function_value
                , ( bp::arg("dihedral"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::toString
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::QString ( ::SireMol::Mover< SireMol::Chain >::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMol::Mover< SireMol::Chain >::toString );
            
            Mover_Chain__exposer.def( 
                "toString"
                , toString_function_value
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::transform
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*transform_function_type)( ::SireMaths::Transform const &,::SireBase::PropertyMap const & ) ;
            transform_function_type transform_function_value( &::SireMol::Mover< SireMol::Chain >::transform );
            
            Mover_Chain__exposer.def( 
                "transform"
                , transform_function_value
                , ( bp::arg("transform"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::translate
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef ::SireMol::Mover< SireMol::Chain > & ( ::SireMol::Mover< SireMol::Chain >::*translate_function_type)( ::SireMaths::Vector const &,::SireBase::PropertyMap const & ) ;
            translate_function_type translate_function_value( &::SireMol::Mover< SireMol::Chain >::translate );
            
            Mover_Chain__exposer.def( 
                "translate"
                , translate_function_value
                , ( bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMol::Chain >::typeName
        
            typedef SireMol::Mover< SireMol::Chain > exported_class_t;
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::Mover< SireMol::Chain >::typeName );
            
            Mover_Chain__exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        Mover_Chain__exposer.staticmethod( "typeName" );
        Mover_Chain__exposer.def( "__copy__", &__copy__);
        Mover_Chain__exposer.def( "__deepcopy__", &__copy__);
        Mover_Chain__exposer.def( "clone", &__copy__);
        Mover_Chain__exposer.def( "__str__", &__str__< ::SireMol::Mover<SireMol::Chain> > );
        Mover_Chain__exposer.def( "__repr__", &__str__< ::SireMol::Mover<SireMol::Chain> > );
        Mover_Chain__exposer.def( "__len__", &__len_size< ::SireMol::Mover<SireMol::Chain> > );
    }

}
