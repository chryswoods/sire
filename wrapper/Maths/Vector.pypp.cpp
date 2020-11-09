// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "Vector.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/quickcopy.hpp"

#include "SireError/errors.h"

#include "SireID/index.h"

#include "SireStream/datastream.h"

#include "SireUnits/units.h"

#include "matrix.h"

#include "nvector.h"

#include "quaternion.h"

#include "sincos.h"

#include "vector.h"

#include <QDebug>

#include <QRegExp>

#include <QString>

#include <cmath>

#include "vector.h"

SireMaths::Vector __copy__(const SireMaths::Vector &other){ return SireMaths::Vector(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

#include "Helpers/len.hpp"

void register_Vector_class(){

    { //::SireMaths::Vector
        typedef bp::class_< SireMaths::Vector > Vector_exposer_t;
        Vector_exposer_t Vector_exposer = Vector_exposer_t( "Vector", "", bp::init< bp::optional< double > >(( bp::arg("val")=0. ), "Construct from a tuple of three values") );
        bp::scope Vector_scope( Vector_exposer );
        Vector_exposer.def( bp::init< double, double, double >(( bp::arg("xpos"), bp::arg("ypos"), bp::arg("zpos") ), "") );
        Vector_exposer.def( bp::init< boost::tuples::tuple< double, double, double, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type, boost::tuples::null_type > const & >(( bp::arg("pos") ), "Construct from a tuple of three values") );
        Vector_exposer.def( bp::init< QString const & >(( bp::arg("str") ), "Construct from a QString\nThrow: SireError::invalid_arg\n") );
        Vector_exposer.def( bp::init< SireMaths::NVector const & >(( bp::arg("other") ), "Copy constructor") );
        Vector_exposer.def( bp::init< SireMaths::Vector const & >(( bp::arg("other") ), "Copy constructor") );
        { //::SireMaths::Vector::angle
        
            typedef ::SireUnits::Dimension::Angle ( *angle_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            angle_function_type angle_function_value( &::SireMaths::Vector::angle );
            
            Vector_exposer.def( 
                "angle"
                , angle_function_value
                , ( bp::arg("v0"), bp::arg("v1") )
                , "Return the angle between vectors v0 and v1 - this is the smallest\nangle, and will always lie between 0 and 180 degrees" );
        
        }
        { //::SireMaths::Vector::angle
        
            typedef ::SireUnits::Dimension::Angle ( *angle_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const &,::SireMaths::Vector const & );
            angle_function_type angle_function_value( &::SireMaths::Vector::angle );
            
            Vector_exposer.def( 
                "angle"
                , angle_function_value
                , ( bp::arg("v0"), bp::arg("v1"), bp::arg("v2") )
                , "Return the angle between v0-v1-v2 (treating the vectors as points in space)" );
        
        }
        { //::SireMaths::Vector::at
        
            typedef double ( ::SireMaths::Vector::*at_function_type)( int ) const;
            at_function_type at_function_value( &::SireMaths::Vector::at );
            
            Vector_exposer.def( 
                "at"
                , at_function_value
                , ( bp::arg("i") )
                , "Access elements by index" );
        
        }
        { //::SireMaths::Vector::b
        
            typedef double ( ::SireMaths::Vector::*b_function_type)(  ) const;
            b_function_type b_function_value( &::SireMaths::Vector::b );
            
            Vector_exposer.def( 
                "b"
                , b_function_value
                , "Return the components via rgb (limited between 0 and 1)" );
        
        }
        { //::SireMaths::Vector::bearing
        
            typedef ::SireUnits::Dimension::Angle ( ::SireMaths::Vector::*bearing_function_type)(  ) const;
            bearing_function_type bearing_function_value( &::SireMaths::Vector::bearing );
            
            Vector_exposer.def( 
                "bearing"
                , bearing_function_value
                , "Return the bearing of this vector against (0,1,0) (north) on the xy plane" );
        
        }
        { //::SireMaths::Vector::bearingXY
        
            typedef ::SireUnits::Dimension::Angle ( ::SireMaths::Vector::*bearingXY_function_type)( ::SireMaths::Vector const & ) const;
            bearingXY_function_type bearingXY_function_value( &::SireMaths::Vector::bearingXY );
            
            Vector_exposer.def( 
                "bearingXY"
                , bearingXY_function_value
                , ( bp::arg("v") )
                , "Return the bearing of this vector against v on the xy plane" );
        
        }
        { //::SireMaths::Vector::bearingXZ
        
            typedef ::SireUnits::Dimension::Angle ( ::SireMaths::Vector::*bearingXZ_function_type)( ::SireMaths::Vector const & ) const;
            bearingXZ_function_type bearingXZ_function_value( &::SireMaths::Vector::bearingXZ );
            
            Vector_exposer.def( 
                "bearingXZ"
                , bearingXZ_function_value
                , ( bp::arg("v") )
                , "Return the bearing of this vector against v on the xz plane" );
        
        }
        { //::SireMaths::Vector::bearingYZ
        
            typedef ::SireUnits::Dimension::Angle ( ::SireMaths::Vector::*bearingYZ_function_type)( ::SireMaths::Vector const & ) const;
            bearingYZ_function_type bearingYZ_function_value( &::SireMaths::Vector::bearingYZ );
            
            Vector_exposer.def( 
                "bearingYZ"
                , bearingYZ_function_value
                , ( bp::arg("v") )
                , "Return the bearing of this vector against v on the yz plane" );
        
        }
        { //::SireMaths::Vector::count
        
            typedef int ( ::SireMaths::Vector::*count_function_type)(  ) const;
            count_function_type count_function_value( &::SireMaths::Vector::count );
            
            Vector_exposer.def( 
                "count"
                , count_function_value
                , "Return the size of the Vector (always 3 - unless you disagree\nwith me that we should be living in a 3-dimensional space)" );
        
        }
        { //::SireMaths::Vector::cross
        
            typedef ::SireMaths::Vector ( *cross_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            cross_function_type cross_function_value( &::SireMaths::Vector::cross );
            
            Vector_exposer.def( 
                "cross"
                , cross_function_value
                , ( bp::arg("v0"), bp::arg("v1") )
                , "Note that the cross product returns a normal vector, i.e. it has been\nnormalised" );
        
        }
        { //::SireMaths::Vector::dihedral
        
            typedef ::SireUnits::Dimension::Angle ( *dihedral_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const &,::SireMaths::Vector const &,::SireMaths::Vector const & );
            dihedral_function_type dihedral_function_value( &::SireMaths::Vector::dihedral );
            
            Vector_exposer.def( 
                "dihedral"
                , dihedral_function_value
                , ( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3") )
                , "Return the dihedral angle between v0-v1-v2-v3 (treating the vectors as points)" );
        
        }
        { //::SireMaths::Vector::direction
        
            typedef ::SireMaths::Vector ( ::SireMaths::Vector::*direction_function_type)(  ) const;
            direction_function_type direction_function_value( &::SireMaths::Vector::direction );
            
            Vector_exposer.def( 
                "direction"
                , direction_function_value
                , "Return the unit vector pointing in the direction of this vector" );
        
        }
        { //::SireMaths::Vector::distance
        
            typedef double ( *distance_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            distance_function_type distance_function_value( &::SireMaths::Vector::distance );
            
            Vector_exposer.def( 
                "distance"
                , distance_function_value
                , ( bp::arg("v1"), bp::arg("v2") )
                , "Return the distance between two vectors" );
        
        }
        { //::SireMaths::Vector::distance2
        
            typedef double ( *distance2_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            distance2_function_type distance2_function_value( &::SireMaths::Vector::distance2 );
            
            Vector_exposer.def( 
                "distance2"
                , distance2_function_value
                , ( bp::arg("v1"), bp::arg("v2") )
                , "Return the distance squared between two vectors" );
        
        }
        { //::SireMaths::Vector::dot
        
            typedef double ( *dot_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            dot_function_type dot_function_value( &::SireMaths::Vector::dot );
            
            Vector_exposer.def( 
                "dot"
                , dot_function_value
                , ( bp::arg("v0"), bp::arg("v1") )
                , "Return the dot product of v0 and v1" );
        
        }
        { //::SireMaths::Vector::fromString
        
            typedef ::SireMaths::Vector ( *fromString_function_type )( ::QString const & );
            fromString_function_type fromString_function_value( &::SireMaths::Vector::fromString );
            
            Vector_exposer.def( 
                "fromString"
                , fromString_function_value
                , ( bp::arg("str") )
                , "Construct a Vector from the QString representation returned by toString()\nThrow: SireError::invalid_arg\n" );
        
        }
        { //::SireMaths::Vector::g
        
            typedef double ( ::SireMaths::Vector::*g_function_type)(  ) const;
            g_function_type g_function_value( &::SireMaths::Vector::g );
            
            Vector_exposer.def( 
                "g"
                , g_function_value
                , "Return the components via rgb (limited between 0 and 1)" );
        
        }
        { //::SireMaths::Vector::generate
        
            typedef ::SireMaths::Vector ( *generate_function_type )( double,::SireMaths::Vector const &,::SireUnits::Dimension::Angle const &,::SireMaths::Vector const &,::SireUnits::Dimension::Angle const &,::SireMaths::Vector const & );
            generate_function_type generate_function_value( &::SireMaths::Vector::generate );
            
            Vector_exposer.def( 
                "generate"
                , generate_function_value
                , ( bp::arg("dst"), bp::arg("v1"), bp::arg("ang"), bp::arg("v2"), bp::arg("dih"), bp::arg("v3") )
                , "Generate a vector, v0, that has distance dst v0-v1, angle ang v0-v1-v2,\nand dihedral dih v0-v1-v2-v3" );
        
        }
        { //::SireMaths::Vector::getitem
        
            typedef double ( ::SireMaths::Vector::*getitem_function_type)( int ) const;
            getitem_function_type getitem_function_value( &::SireMaths::Vector::getitem );
            
            Vector_exposer.def( 
                "getitem"
                , getitem_function_value
                , ( bp::arg("i") )
                , "Access elements by index (used by python)" );
        
        }
        { //::SireMaths::Vector::invDistance
        
            typedef double ( *invDistance_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            invDistance_function_type invDistance_function_value( &::SireMaths::Vector::invDistance );
            
            Vector_exposer.def( 
                "invDistance"
                , invDistance_function_value
                , ( bp::arg("v1"), bp::arg("v2") )
                , "Return the 1  distance between two vectors" );
        
        }
        { //::SireMaths::Vector::invDistance2
        
            typedef double ( *invDistance2_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            invDistance2_function_type invDistance2_function_value( &::SireMaths::Vector::invDistance2 );
            
            Vector_exposer.def( 
                "invDistance2"
                , invDistance2_function_value
                , ( bp::arg("v1"), bp::arg("v2") )
                , "Return 1  distance2 between two vectors" );
        
        }
        { //::SireMaths::Vector::invLength
        
            typedef double ( ::SireMaths::Vector::*invLength_function_type)(  ) const;
            invLength_function_type invLength_function_value( &::SireMaths::Vector::invLength );
            
            Vector_exposer.def( 
                "invLength"
                , invLength_function_value
                , "" );
        
        }
        { //::SireMaths::Vector::invLength2
        
            typedef double ( ::SireMaths::Vector::*invLength2_function_type)(  ) const;
            invLength2_function_type invLength2_function_value( &::SireMaths::Vector::invLength2 );
            
            Vector_exposer.def( 
                "invLength2"
                , invLength2_function_value
                , "Return the inverse length squared" );
        
        }
        { //::SireMaths::Vector::isZero
        
            typedef bool ( ::SireMaths::Vector::*isZero_function_type)(  ) const;
            isZero_function_type isZero_function_value( &::SireMaths::Vector::isZero );
            
            Vector_exposer.def( 
                "isZero"
                , isZero_function_value
                , "Return whether or not this is a zero length vector" );
        
        }
        { //::SireMaths::Vector::length
        
            typedef double ( ::SireMaths::Vector::*length_function_type)(  ) const;
            length_function_type length_function_value( &::SireMaths::Vector::length );
            
            Vector_exposer.def( 
                "length"
                , length_function_value
                , "" );
        
        }
        { //::SireMaths::Vector::length2
        
            typedef double ( ::SireMaths::Vector::*length2_function_type)(  ) const;
            length2_function_type length2_function_value( &::SireMaths::Vector::length2 );
            
            Vector_exposer.def( 
                "length2"
                , length2_function_value
                , "" );
        
        }
        { //::SireMaths::Vector::magnitude
        
            typedef double ( ::SireMaths::Vector::*magnitude_function_type)(  ) const;
            magnitude_function_type magnitude_function_value( &::SireMaths::Vector::magnitude );
            
            Vector_exposer.def( 
                "magnitude"
                , magnitude_function_value
                , "Return the length of this vector" );
        
        }
        { //::SireMaths::Vector::manhattanLength
        
            typedef double ( ::SireMaths::Vector::*manhattanLength_function_type)(  ) const;
            manhattanLength_function_type manhattanLength_function_value( &::SireMaths::Vector::manhattanLength );
            
            Vector_exposer.def( 
                "manhattanLength"
                , manhattanLength_function_value
                , "Return the manhattan length of the vector" );
        
        }
        { //::SireMaths::Vector::max
        
            typedef ::SireMaths::Vector ( ::SireMaths::Vector::*max_function_type)( ::SireMaths::Vector const & ) const;
            max_function_type max_function_value( &::SireMaths::Vector::max );
            
            Vector_exposer.def( 
                "max"
                , max_function_value
                , ( bp::arg("other") )
                , "Return a vector that has the maximum xyz components out of this\nand other" );
        
        }
        { //::SireMaths::Vector::metricTensor
        
            typedef ::SireMaths::Matrix ( ::SireMaths::Vector::*metricTensor_function_type)(  ) const;
            metricTensor_function_type metricTensor_function_value( &::SireMaths::Vector::metricTensor );
            
            Vector_exposer.def( 
                "metricTensor"
                , metricTensor_function_value
                , "Return the metric tensor of a vector, i.e.\n| yy + zz,    -xy    -xz      |\n|    -yx,   xx + zz  -yz      |\n|    -zx       -zy    xx + yy |\n" );
        
        }
        { //::SireMaths::Vector::min
        
            typedef ::SireMaths::Vector ( ::SireMaths::Vector::*min_function_type)( ::SireMaths::Vector const & ) const;
            min_function_type min_function_value( &::SireMaths::Vector::min );
            
            Vector_exposer.def( 
                "min"
                , min_function_value
                , ( bp::arg("other") )
                , "Return a vector that has the minimum components" );
        
        }
        { //::SireMaths::Vector::normalise
        
            typedef ::SireMaths::Vector ( ::SireMaths::Vector::*normalise_function_type)(  ) const;
            normalise_function_type normalise_function_value( &::SireMaths::Vector::normalise );
            
            Vector_exposer.def( 
                "normalise"
                , normalise_function_value
                , "Return a normalised form of the vector" );
        
        }
        Vector_exposer.def( bp::self != bp::self );
        Vector_exposer.def( bp::self *= bp::other< double >() );
        Vector_exposer.def( bp::self += bp::self );
        Vector_exposer.def( -bp::self );
        Vector_exposer.def( bp::self -= bp::self );
        Vector_exposer.def( bp::self /= bp::other< double >() );
        { //::SireMaths::Vector::operator=
        
            typedef ::SireMaths::Vector const & ( ::SireMaths::Vector::*assign_function_type)( ::SireMaths::Vector const & ) ;
            assign_function_type assign_function_value( &::SireMaths::Vector::operator= );
            
            Vector_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "" );
        
        }
        Vector_exposer.def( bp::self == bp::self );
        { //::SireMaths::Vector::operator[]
        
            typedef double ( ::SireMaths::Vector::*__getitem___function_type)( int ) const;
            __getitem___function_type __getitem___function_value( &::SireMaths::Vector::operator[] );
            
            Vector_exposer.def( 
                "__getitem__"
                , __getitem___function_value
                , ( bp::arg("i") )
                , "" );
        
        }
        { //::SireMaths::Vector::r
        
            typedef double ( ::SireMaths::Vector::*r_function_type)(  ) const;
            r_function_type r_function_value( &::SireMaths::Vector::r );
            
            Vector_exposer.def( 
                "r"
                , r_function_value
                , "Return the components via rgb (limited between 0 and 1)" );
        
        }
        { //::SireMaths::Vector::realCross
        
            typedef ::SireMaths::Vector ( *realCross_function_type )( ::SireMaths::Vector const &,::SireMaths::Vector const & );
            realCross_function_type realCross_function_value( &::SireMaths::Vector::realCross );
            
            Vector_exposer.def( 
                "realCross"
                , realCross_function_value
                , ( bp::arg("v0"), bp::arg("v1") )
                , "This is a regular cross product." );
        
        }
        { //::SireMaths::Vector::set
        
            typedef void ( ::SireMaths::Vector::*set_function_type)( double,double,double ) ;
            set_function_type set_function_value( &::SireMaths::Vector::set );
            
            Vector_exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("x"), bp::arg("y"), bp::arg("z") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::set
        
            typedef void ( ::SireMaths::Vector::*set_function_type)( int,double const & ) ;
            set_function_type set_function_value( &::SireMaths::Vector::set );
            
            Vector_exposer.def( 
                "set"
                , set_function_value
                , ( bp::arg("i"), bp::arg("v") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::setB
        
            typedef void ( ::SireMaths::Vector::*setB_function_type)( double ) ;
            setB_function_type setB_function_value( &::SireMaths::Vector::setB );
            
            Vector_exposer.def( 
                "setB"
                , setB_function_value
                , ( bp::arg("z") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::setG
        
            typedef void ( ::SireMaths::Vector::*setG_function_type)( double ) ;
            setG_function_type setG_function_value( &::SireMaths::Vector::setG );
            
            Vector_exposer.def( 
                "setG"
                , setG_function_value
                , ( bp::arg("y") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::setMax
        
            typedef void ( ::SireMaths::Vector::*setMax_function_type)( ::SireMaths::Vector const & ) ;
            setMax_function_type setMax_function_value( &::SireMaths::Vector::setMax );
            
            Vector_exposer.def( 
                "setMax"
                , setMax_function_value
                , ( bp::arg("other") )
                , "Set this Vector so that it has the maximum xyz components out of\nthis and other (e.g. this->x = max(this->x(),other.x() etc.)" );
        
        }
        { //::SireMaths::Vector::setMin
        
            typedef void ( ::SireMaths::Vector::*setMin_function_type)( ::SireMaths::Vector const & ) ;
            setMin_function_type setMin_function_value( &::SireMaths::Vector::setMin );
            
            Vector_exposer.def( 
                "setMin"
                , setMin_function_value
                , ( bp::arg("other") )
                , "Set this Vector so that it has the minimum xyz components" );
        
        }
        { //::SireMaths::Vector::setR
        
            typedef void ( ::SireMaths::Vector::*setR_function_type)( double ) ;
            setR_function_type setR_function_value( &::SireMaths::Vector::setR );
            
            Vector_exposer.def( 
                "setR"
                , setR_function_value
                , ( bp::arg("x") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::setX
        
            typedef void ( ::SireMaths::Vector::*setX_function_type)( double ) ;
            setX_function_type setX_function_value( &::SireMaths::Vector::setX );
            
            Vector_exposer.def( 
                "setX"
                , setX_function_value
                , ( bp::arg("x") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::setY
        
            typedef void ( ::SireMaths::Vector::*setY_function_type)( double ) ;
            setY_function_type setY_function_value( &::SireMaths::Vector::setY );
            
            Vector_exposer.def( 
                "setY"
                , setY_function_value
                , ( bp::arg("y") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::setZ
        
            typedef void ( ::SireMaths::Vector::*setZ_function_type)( double ) ;
            setZ_function_type setZ_function_value( &::SireMaths::Vector::setZ );
            
            Vector_exposer.def( 
                "setZ"
                , setZ_function_value
                , ( bp::arg("z") )
                , "Set individual values of the vector" );
        
        }
        { //::SireMaths::Vector::toString
        
            typedef ::QString ( ::SireMaths::Vector::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireMaths::Vector::toString );
            
            Vector_exposer.def( 
                "toString"
                , toString_function_value
                , "Return a QString representation of the vector" );
        
        }
        { //::SireMaths::Vector::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireMaths::Vector::typeName );
            
            Vector_exposer.def( 
                "typeName"
                , typeName_function_value
                , "" );
        
        }
        { //::SireMaths::Vector::what
        
            typedef char const * ( ::SireMaths::Vector::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireMaths::Vector::what );
            
            Vector_exposer.def( 
                "what"
                , what_function_value
                , "" );
        
        }
        { //::SireMaths::Vector::x
        
            typedef double ( ::SireMaths::Vector::*x_function_type)(  ) const;
            x_function_type x_function_value( &::SireMaths::Vector::x );
            
            Vector_exposer.def( 
                "x"
                , x_function_value
                , "" );
        
        }
        { //::SireMaths::Vector::y
        
            typedef double ( ::SireMaths::Vector::*y_function_type)(  ) const;
            y_function_type y_function_value( &::SireMaths::Vector::y );
            
            Vector_exposer.def( 
                "y"
                , y_function_value
                , "" );
        
        }
        { //::SireMaths::Vector::z
        
            typedef double ( ::SireMaths::Vector::*z_function_type)(  ) const;
            z_function_type z_function_value( &::SireMaths::Vector::z );
            
            Vector_exposer.def( 
                "z"
                , z_function_value
                , "" );
        
        }
        Vector_exposer.staticmethod( "angle" );
        Vector_exposer.staticmethod( "cross" );
        Vector_exposer.staticmethod( "dihedral" );
        Vector_exposer.staticmethod( "distance" );
        Vector_exposer.staticmethod( "distance2" );
        Vector_exposer.staticmethod( "dot" );
        Vector_exposer.staticmethod( "fromString" );
        Vector_exposer.staticmethod( "generate" );
        Vector_exposer.staticmethod( "invDistance" );
        Vector_exposer.staticmethod( "invDistance2" );
        Vector_exposer.staticmethod( "realCross" );
        Vector_exposer.staticmethod( "typeName" );
        Vector_exposer.def( bp::self * bp::other< SireMaths::Quaternion >() );
        Vector_exposer.def( bp::self * bp::other< double >() );
        Vector_exposer.def( bp::other< double >() * bp::self );
        Vector_exposer.def( bp::self + bp::self );
        Vector_exposer.def( bp::self - bp::self );
        Vector_exposer.def( bp::self / bp::other< double >() );
        Vector_exposer.def( "__copy__", &__copy__);
        Vector_exposer.def( "__deepcopy__", &__copy__);
        Vector_exposer.def( "clone", &__copy__);
        Vector_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireMaths::Vector >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        Vector_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireMaths::Vector >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        Vector_exposer.def( "__str__", &__str__< ::SireMaths::Vector > );
        Vector_exposer.def( "__repr__", &__str__< ::SireMaths::Vector > );
        Vector_exposer.def( "__len__", &__len_count< ::SireMaths::Vector > );
        Vector_exposer.def( "__getitem__", &::SireMaths::Vector::getitem );
    }

}
