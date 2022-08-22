// This file has been generated by Py++.

// (C) Christopher Woods, GPL >= 2 License

#include "boost/python.hpp"
#include "DCD.pypp.hpp"

namespace bp = boost::python;

#include "SireBase/booleanproperty.h"

#include "SireBase/generalunitproperty.h"

#include "SireBase/getinstalldir.h"

#include "SireBase/parallel.h"

#include "SireBase/stringproperty.h"

#include "SireBase/timeproperty.h"

#include "SireBase/unittest.h"

#include "SireIO/amberformat.h"

#include "SireIO/dcd.h"

#include "SireIO/errors.h"

#include "SireMol/atomcoords.h"

#include "SireMol/atomforces.h"

#include "SireMol/atomvelocities.h"

#include "SireMol/core.h"

#include "SireMol/mgname.h"

#include "SireMol/molecule.h"

#include "SireMol/moleditor.h"

#include "SireMol/molidx.h"

#include "SireStream/shareddatastream.h"

#include "SireSystem/system.h"

#include "SireUnits/dimensions.h"

#include "SireUnits/units.h"

#include "SireVol/periodicbox.h"

#include "SireVol/triclinicbox.h"

#include "dcd.h"

#include "dcd.h"

SireIO::DCD __copy__(const SireIO::DCD &other){ return SireIO::DCD(other); }

#include "Qt/qdatastream.hpp"

#include "Helpers/str.hpp"

#include "Helpers/release_gil_policy.hpp"

void register_DCD_class(){

    { //::SireIO::DCD
        typedef bp::class_< SireIO::DCD, bp::bases< SireIO::MoleculeParser, SireBase::Property > > DCD_exposer_t;
        DCD_exposer_t DCD_exposer = DCD_exposer_t( "DCD", "This class represents a DCD file reader. Note that this will\nonly read the first frame from the file (it is for loading molecules).\nThe whole trajectory will be added and parsed using\nthe DCDTrajectory class.\n\nThe format is described here\n\nhttps:www.ks.uiuc.eduResearchvmdpluginsmolfiledcdplugin.html\n\nAuthor: Christopher Woods\n", bp::init< >("Constructor") );
        bp::scope DCD_scope( DCD_exposer );
        DCD_exposer.def( bp::init< QString const &, bp::optional< SireBase::PropertyMap const & > >(( bp::arg("filename"), bp::arg("map")=SireBase::PropertyMap() ), "Construct by parsing the passed file") );
        DCD_exposer.def( bp::init< QStringList const &, bp::optional< SireBase::PropertyMap const & > >(( bp::arg("lines"), bp::arg("map")=SireBase::PropertyMap() ), "Construct by parsing the data in the passed text lines") );
        DCD_exposer.def( bp::init< SireSystem::System const &, bp::optional< SireBase::PropertyMap const & > >(( bp::arg("system"), bp::arg("map")=SireBase::PropertyMap() ), "Construct by extracting the necessary data from the passed System") );
        DCD_exposer.def( bp::init< SireIO::DCD const & >(( bp::arg("other") ), "Copy constructor") );
        { //::SireIO::DCD::boxAngles
        
            typedef ::SireMaths::Vector ( ::SireIO::DCD::*boxAngles_function_type)(  ) const;
            boxAngles_function_type boxAngles_function_value( &::SireIO::DCD::boxAngles );
            
            DCD_exposer.def( 
                "boxAngles"
                , boxAngles_function_value
                , bp::release_gil_policy()
                , "Return the parsed box angles, or Vector(0) if there is no space information." );
        
        }
        { //::SireIO::DCD::boxDimensions
        
            typedef ::SireMaths::Vector ( ::SireIO::DCD::*boxDimensions_function_type)(  ) const;
            boxDimensions_function_type boxDimensions_function_value( &::SireIO::DCD::boxDimensions );
            
            DCD_exposer.def( 
                "boxDimensions"
                , boxDimensions_function_value
                , bp::release_gil_policy()
                , "Return the parsed box dimensions, or Vector(0) if there is no space information" );
        
        }
        { //::SireIO::DCD::construct
        
            typedef ::SireIO::MoleculeParserPtr ( ::SireIO::DCD::*construct_function_type)( ::QString const &,::SireBase::PropertyMap const & ) const;
            construct_function_type construct_function_value( &::SireIO::DCD::construct );
            
            DCD_exposer.def( 
                "construct"
                , construct_function_value
                , ( bp::arg("filename"), bp::arg("map") )
                , bp::release_gil_policy()
                , "Return this parser constructed from the passed filename" );
        
        }
        { //::SireIO::DCD::construct
        
            typedef ::SireIO::MoleculeParserPtr ( ::SireIO::DCD::*construct_function_type)( ::QStringList const &,::SireBase::PropertyMap const & ) const;
            construct_function_type construct_function_value( &::SireIO::DCD::construct );
            
            DCD_exposer.def( 
                "construct"
                , construct_function_value
                , ( bp::arg("lines"), bp::arg("map") )
                , bp::release_gil_policy()
                , "Return this parser constructed from the passed set of lines" );
        
        }
        { //::SireIO::DCD::construct
        
            typedef ::SireIO::MoleculeParserPtr ( ::SireIO::DCD::*construct_function_type)( ::SireSystem::System const &,::SireBase::PropertyMap const & ) const;
            construct_function_type construct_function_value( &::SireIO::DCD::construct );
            
            DCD_exposer.def( 
                "construct"
                , construct_function_value
                , ( bp::arg("system"), bp::arg("map") )
                , bp::release_gil_policy()
                , "Return this parser constructed from the passed SireSystem::System" );
        
        }
        { //::SireIO::DCD::coordinates
        
            typedef ::QVector< SireMaths::Vector > ( ::SireIO::DCD::*coordinates_function_type)(  ) const;
            coordinates_function_type coordinates_function_value( &::SireIO::DCD::coordinates );
            
            DCD_exposer.def( 
                "coordinates"
                , coordinates_function_value
                , bp::release_gil_policy()
                , "Return the parsed coordinate data." );
        
        }
        { //::SireIO::DCD::forces
        
            typedef ::QVector< SireMaths::Vector > ( ::SireIO::DCD::*forces_function_type)(  ) const;
            forces_function_type forces_function_value( &::SireIO::DCD::forces );
            
            DCD_exposer.def( 
                "forces"
                , forces_function_value
                , bp::release_gil_policy()
                , "Return the parsed force data." );
        
        }
        { //::SireIO::DCD::formatDescription
        
            typedef ::QString ( ::SireIO::DCD::*formatDescription_function_type)(  ) const;
            formatDescription_function_type formatDescription_function_value( &::SireIO::DCD::formatDescription );
            
            DCD_exposer.def( 
                "formatDescription"
                , formatDescription_function_value
                , bp::release_gil_policy()
                , "Return a description of the file format" );
        
        }
        { //::SireIO::DCD::formatName
        
            typedef ::QString ( ::SireIO::DCD::*formatName_function_type)(  ) const;
            formatName_function_type formatName_function_value( &::SireIO::DCD::formatName );
            
            DCD_exposer.def( 
                "formatName"
                , formatName_function_value
                , bp::release_gil_policy()
                , "Return the format name that is used to identify this file format within Sire" );
        
        }
        { //::SireIO::DCD::formatSuffix
        
            typedef ::QStringList ( ::SireIO::DCD::*formatSuffix_function_type)(  ) const;
            formatSuffix_function_type formatSuffix_function_value( &::SireIO::DCD::formatSuffix );
            
            DCD_exposer.def( 
                "formatSuffix"
                , formatSuffix_function_value
                , bp::release_gil_policy()
                , "Return the suffixes that DCD files will typically use" );
        
        }
        { //::SireIO::DCD::hasCoordinates
        
            typedef bool ( ::SireIO::DCD::*hasCoordinates_function_type)(  ) const;
            hasCoordinates_function_type hasCoordinates_function_value( &::SireIO::DCD::hasCoordinates );
            
            DCD_exposer.def( 
                "hasCoordinates"
                , hasCoordinates_function_value
                , bp::release_gil_policy()
                , "Return whether or not this DCD file provides coordinates" );
        
        }
        { //::SireIO::DCD::hasForces
        
            typedef bool ( ::SireIO::DCD::*hasForces_function_type)(  ) const;
            hasForces_function_type hasForces_function_value( &::SireIO::DCD::hasForces );
            
            DCD_exposer.def( 
                "hasForces"
                , hasForces_function_value
                , bp::release_gil_policy()
                , "Return whether or not this DCD file also provides forces" );
        
        }
        { //::SireIO::DCD::hasVelocities
        
            typedef bool ( ::SireIO::DCD::*hasVelocities_function_type)(  ) const;
            hasVelocities_function_type hasVelocities_function_value( &::SireIO::DCD::hasVelocities );
            
            DCD_exposer.def( 
                "hasVelocities"
                , hasVelocities_function_value
                , bp::release_gil_policy()
                , "Return whether or not this DCD file also provides velocities" );
        
        }
        { //::SireIO::DCD::isTextFile
        
            typedef bool ( ::SireIO::DCD::*isTextFile_function_type)(  ) const;
            isTextFile_function_type isTextFile_function_value( &::SireIO::DCD::isTextFile );
            
            DCD_exposer.def( 
                "isTextFile"
                , isTextFile_function_value
                , bp::release_gil_policy()
                , "This is not a text file" );
        
        }
        { //::SireIO::DCD::nAtoms
        
            typedef int ( ::SireIO::DCD::*nAtoms_function_type)(  ) const;
            nAtoms_function_type nAtoms_function_value( &::SireIO::DCD::nAtoms );
            
            DCD_exposer.def( 
                "nAtoms"
                , nAtoms_function_value
                , bp::release_gil_policy()
                , "Return the number of atoms whose data are contained in this DCD file" );
        
        }
        DCD_exposer.def( bp::self != bp::self );
        { //::SireIO::DCD::operator=
        
            typedef ::SireIO::DCD & ( ::SireIO::DCD::*assign_function_type)( ::SireIO::DCD const & ) ;
            assign_function_type assign_function_value( &::SireIO::DCD::operator= );
            
            DCD_exposer.def( 
                "assign"
                , assign_function_value
                , ( bp::arg("other") )
                , bp::return_self< >()
                , "" );
        
        }
        DCD_exposer.def( bp::self == bp::self );
        { //::SireIO::DCD::parse
        
            typedef ::SireIO::DCD ( *parse_function_type )( ::QString const & );
            parse_function_type parse_function_value( &::SireIO::DCD::parse );
            
            DCD_exposer.def( 
                "parse"
                , parse_function_value
                , ( bp::arg("filename") )
                , bp::release_gil_policy()
                , "Parse from the passed file" );
        
        }
        { //::SireIO::DCD::time
        
            typedef double ( ::SireIO::DCD::*time_function_type)(  ) const;
            time_function_type time_function_value( &::SireIO::DCD::time );
            
            DCD_exposer.def( 
                "time"
                , time_function_value
                , bp::release_gil_policy()
                , "Return the current time of the simulation from which this restart\nfile was written. Returns 0 if there is no time set. If there are\nmultiple frames, then the time of the first frame is returned" );
        
        }
        { //::SireIO::DCD::title
        
            typedef ::QString ( ::SireIO::DCD::*title_function_type)(  ) const;
            title_function_type title_function_value( &::SireIO::DCD::title );
            
            DCD_exposer.def( 
                "title"
                , title_function_value
                , bp::release_gil_policy()
                , "Return the title of the file" );
        
        }
        { //::SireIO::DCD::toString
        
            typedef ::QString ( ::SireIO::DCD::*toString_function_type)(  ) const;
            toString_function_type toString_function_value( &::SireIO::DCD::toString );
            
            DCD_exposer.def( 
                "toString"
                , toString_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireIO::DCD::typeName
        
            typedef char const * ( *typeName_function_type )(  );
            typeName_function_type typeName_function_value( &::SireIO::DCD::typeName );
            
            DCD_exposer.def( 
                "typeName"
                , typeName_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireIO::DCD::velocities
        
            typedef ::QVector< SireMaths::Vector > ( ::SireIO::DCD::*velocities_function_type)(  ) const;
            velocities_function_type velocities_function_value( &::SireIO::DCD::velocities );
            
            DCD_exposer.def( 
                "velocities"
                , velocities_function_value
                , bp::release_gil_policy()
                , "Return the parsed velocity" );
        
        }
        { //::SireIO::DCD::warnings
        
            typedef ::QStringList ( ::SireIO::DCD::*warnings_function_type)(  ) const;
            warnings_function_type warnings_function_value( &::SireIO::DCD::warnings );
            
            DCD_exposer.def( 
                "warnings"
                , warnings_function_value
                , bp::release_gil_policy()
                , "Return any warnings that were triggered during parsing" );
        
        }
        { //::SireIO::DCD::what
        
            typedef char const * ( ::SireIO::DCD::*what_function_type)(  ) const;
            what_function_type what_function_value( &::SireIO::DCD::what );
            
            DCD_exposer.def( 
                "what"
                , what_function_value
                , bp::release_gil_policy()
                , "" );
        
        }
        { //::SireIO::DCD::writeToFile
        
            typedef void ( ::SireIO::DCD::*writeToFile_function_type)( ::QString const & ) const;
            writeToFile_function_type writeToFile_function_value( &::SireIO::DCD::writeToFile );
            
            DCD_exposer.def( 
                "writeToFile"
                , writeToFile_function_value
                , ( bp::arg("filename") )
                , bp::release_gil_policy()
                , "Write this DCD to a file called filename. This will write out\nthe data in this object to the DCD format" );
        
        }
        DCD_exposer.staticmethod( "parse" );
        DCD_exposer.staticmethod( "typeName" );
        DCD_exposer.def( "__copy__", &__copy__);
        DCD_exposer.def( "__deepcopy__", &__copy__);
        DCD_exposer.def( "clone", &__copy__);
        DCD_exposer.def( "__rlshift__", &__rlshift__QDataStream< ::SireIO::DCD >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        DCD_exposer.def( "__rrshift__", &__rrshift__QDataStream< ::SireIO::DCD >,
                            bp::return_internal_reference<1, bp::with_custodian_and_ward<1,2> >() );
        DCD_exposer.def_pickle(sire_pickle_suite< ::SireIO::DCD >());
        DCD_exposer.def( "__str__", &__str__< ::SireIO::DCD > );
        DCD_exposer.def( "__repr__", &__str__< ::SireIO::DCD > );
    }

}
