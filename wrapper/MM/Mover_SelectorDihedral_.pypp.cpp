// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 3 License

#include "boost/python.hpp"
#include "Mover_SelectorDihedral_.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/errors.h"

#include "SireBase/slice.h"

#include "SireCAS/symbol.h"

#include "SireCAS/values.h"

#include "SireID/index.h"

#include "SireMol/molecule.h"

#include "SireMol/mover.hpp"

#include "SireMol/selector.hpp"

#include "SireStream/datastream.h"

#include "SireStream/shareddatastream.h"

#include "SireUnits/units.h"

#include "fouratomfunctions.h"

#include "selectordihedral.h"

#include <QDebug>

#include "selectordihedral.h"

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

SireMol::Mover<SireMM::SelectorDihedral> __copy__(const SireMol::Mover<SireMM::SelectorDihedral> &other){ return SireMol::Mover<SireMM::SelectorDihedral>(other); }

#include "Helpers/str.hpp"

#include "Helpers/release_gil_policy.hpp"

#include "Helpers/len.hpp"

void register_Mover_SelectorDihedral__class(){

    { //::SireMol::Mover< SireMM::SelectorDihedral >
        typedef bp::class_< SireMol::Mover< SireMM::SelectorDihedral >, bp::bases< SireMol::MoverBase, SireMM::SelectorDihedral, SireMol::MoleculeView, SireBase::Property > > Mover_SelectorDihedral__exposer_t;
        Mover_SelectorDihedral__exposer_t Mover_SelectorDihedral__exposer = Mover_SelectorDihedral__exposer_t( "Mover_SelectorDihedral_", "", bp::init< >("") );
        bp::scope Mover_SelectorDihedral__scope( Mover_SelectorDihedral__exposer );
        Mover_SelectorDihedral__exposer.def( bp::init< SireMM::SelectorDihedral const & >(( bp::arg("view") ), "") );
        Mover_SelectorDihedral__exposer.def( bp::init< SireMM::SelectorDihedral const &, SireMol::AtomSelection const & >(( bp::arg("view"), bp::arg("movable_atoms") ), "") );
        Mover_SelectorDihedral__exposer.def( bp::init< SireMol::Mover< SireMM::SelectorDihedral > const & >(( bp::arg("other") ), "") );
        { //::SireMol::Mover< SireMM::SelectorDihedral >::align
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*align_function_type)( ::SireMol::MoleculeView const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::align );
            
            Mover_SelectorDihedral__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::align
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*align_function_type)( ::SireMol::MoleculeView const &,::SireBase::PropertyMap const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::align );
            
            Mover_SelectorDihedral__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("map0"), bp::arg("map1") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::align
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*align_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::align );
            
            Mover_SelectorDihedral__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("matcher"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::align
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*align_function_type)( ::SireMol::MoleculeView const &,::SireMol::AtomMatcher const &,::SireBase::PropertyMap const &,::SireBase::PropertyMap const & ) ;
            align_function_type align_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::align );
            
            Mover_SelectorDihedral__exposer.def( 
                "align"
                , align_function_value
                , ( bp::arg("other"), bp::arg("matcher"), bp::arg("map0"), bp::arg("map1") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::change
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*change_function_type)( ::SireMol::BondID const &,::SireUnits::Dimension::Length,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::change );
            
            Mover_SelectorDihedral__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("bond"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::change
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*change_function_type)( ::SireMol::AngleID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::change );
            
            Mover_SelectorDihedral__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("angle"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::change
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*change_function_type)( ::SireMol::DihedralID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::change );
            
            Mover_SelectorDihedral__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("dihedral"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::change
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*change_function_type)( ::SireMol::BondID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::change );
            
            Mover_SelectorDihedral__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("bond"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::change
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*change_function_type)( ::SireMol::ImproperID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            change_function_type change_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::change );
            
            Mover_SelectorDihedral__exposer.def( 
                "change"
                , change_function_value
                , ( bp::arg("improper"), bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::changeFrame
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*changeFrame_function_type)( ::SireMaths::AxisSet const &,::SireMaths::AxisSet const &,::SireBase::PropertyMap const & ) ;
            changeFrame_function_type changeFrame_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::changeFrame );
            
            Mover_SelectorDihedral__exposer.def( 
                "changeFrame"
                , changeFrame_function_value
                , ( bp::arg("from_frame"), bp::arg("to_frame"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::commit
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMM::SelectorDihedral ( ::SireMol::Mover< SireMM::SelectorDihedral >::*commit_function_type)(  ) const;
            commit_function_type commit_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::commit );
            
            Mover_SelectorDihedral__exposer.def( 
                "commit"
                , commit_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::makeWhole
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*makeWhole_function_type)( ::SireBase::PropertyMap const & ) ;
            makeWhole_function_type makeWhole_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::makeWhole );
            
            Mover_SelectorDihedral__exposer.def( 
                "makeWhole"
                , makeWhole_function_value
                , ( bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::makeWhole
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*makeWhole_function_type)( ::SireMaths::Vector const &,::SireBase::PropertyMap const & ) ;
            makeWhole_function_type makeWhole_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::makeWhole );
            
            Mover_SelectorDihedral__exposer.def( 
                "makeWhole"
                , makeWhole_function_value
                , ( bp::arg("center"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::mapInto
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*mapInto_function_type)( ::SireMaths::AxisSet const &,::SireBase::PropertyMap const & ) ;
            mapInto_function_type mapInto_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::mapInto );
            
            Mover_SelectorDihedral__exposer.def( 
                "mapInto"
                , mapInto_function_value
                , ( bp::arg("axes"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::operator=
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*assign_function_type)( ::SireMol::Mover< SireMM::SelectorDihedral > const & ) ;
            assign_function_type assign_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::operator= );
            
            Mover_SelectorDihedral__exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::operator=
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*assign_function_type)( ::SireMM::SelectorDihedral const & ) ;
            assign_function_type assign_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::operator= );
            
            Mover_SelectorDihedral__exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::rotate
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*rotate_function_type)( ::SireMaths::Quaternion const &,::SireMaths::Vector const &,::SireBase::PropertyMap const & ) ;
            rotate_function_type rotate_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::rotate );
            
            Mover_SelectorDihedral__exposer.def( 
                "rotate"
                , rotate_function_value
                , ( bp::arg("quat"), bp::arg("point"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::rotate
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*rotate_function_type)( ::SireMaths::Matrix const &,::SireMaths::Vector const &,::SireBase::PropertyMap const & ) ;
            rotate_function_type rotate_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::rotate );
            
            Mover_SelectorDihedral__exposer.def( 
                "rotate"
                , rotate_function_value
                , ( bp::arg("rotmat"), bp::arg("point"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::set
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*set_function_type)( ::SireMol::BondID const &,::SireUnits::Dimension::Length,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::set );
            
            Mover_SelectorDihedral__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("bond"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::set
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*set_function_type)( ::SireMol::AngleID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::set );
            
            Mover_SelectorDihedral__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("angle"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::set
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*set_function_type)( ::SireMol::DihedralID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::set );
            
            Mover_SelectorDihedral__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("dihedral"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::set
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*set_function_type)( ::SireMol::ImproperID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            set_function_type set_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::set );
            
            Mover_SelectorDihedral__exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("improper"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::setAll
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*setAll_function_type)( ::SireMol::DihedralID const &,::SireUnits::Dimension::Angle,::SireBase::PropertyMap const & ) ;
            setAll_function_type setAll_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::setAll );
            
            Mover_SelectorDihedral__exposer.def( 
                "setAll"
                , setAll_function_value
                , ( bp::arg("dihedral"), bp::arg("value"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::toString
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::QString ( ::SireMol::Mover< SireMM::SelectorDihedral >::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::toString );
            
            Mover_SelectorDihedral__exposer.def( 
                "toString"
                , toString_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::transform
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*transform_function_type)( ::SireMaths::Transform const &,::SireBase::PropertyMap const & ) ;
            transform_function_type transform_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::transform );
            
            Mover_SelectorDihedral__exposer.def( 
                "transform"
                , transform_function_value
                , ( bp::arg("transform"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::translate
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef ::SireMol::Mover< SireMM::SelectorDihedral > & ( ::SireMol::Mover< SireMM::SelectorDihedral >::*translate_function_type)( ::SireMaths::Vector const &,::SireBase::PropertyMap const & ) ;
            translate_function_type translate_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::translate );
            
            Mover_SelectorDihedral__exposer.def( 
                "translate"
                , translate_function_value
                , ( bp::arg("delta"), bp::arg("map")=SireBase::PropertyMap() )
                , bp::return_self< >()
                , "" );
        
        }
        { //::SireMol::Mover< SireMM::SelectorDihedral >::typeName
        
            typedef SireMol::Mover< SireMM::SelectorDihedral > exported_class_t;
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMol::Mover< SireMM::SelectorDihedral >::typeName );
            
            Mover_SelectorDihedral__exposer.def( 
                "typeName"
                , typeName_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        Mover_SelectorDihedral__exposer.staticmethod( "typeName" );
        Mover_SelectorDihedral__exposer.def( "__copy__", &__copy__);
        Mover_SelectorDihedral__exposer.def( "__deepcopy__", &__copy__);
        Mover_SelectorDihedral__exposer.def( "clone", &__copy__);
        Mover_SelectorDihedral__exposer.def( "__str__", &__str__< ::SireMol::Mover<SireMM::SelectorDihedral> > );
        Mover_SelectorDihedral__exposer.def( "__repr__", &__str__< ::SireMol::Mover<SireMM::SelectorDihedral> > );
        Mover_SelectorDihedral__exposer.def( "__len__", &__len_size< ::SireMol::Mover<SireMM::SelectorDihedral> > );
    }

}
