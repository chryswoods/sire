
// (C) Christopher Woods, GPL >= 3 License

#include "boost/python.hpp"

#include "sire_openmm.h"

#include "lambdalever.h"

#include "openmmminimise.h"

#include "Helpers/convertlist.hpp"

#include <QDebug>

namespace bp = boost::python;

using namespace SireOpenMM;

/** Thanks to this page for instructions on how to convert from SWIG to Boost
 *  https://wiki.python.org/moin/boost.python/HowTo
 */
struct PySwigObject
{
    PyObject_HEAD void *ptr;
    const char *desc;
};

void *extract_swig_wrapped_pointer(PyObject *obj)
{
    char thisStr[] = "this";

    // first we need to get the this attribute from the Python Object
    if (!PyObject_HasAttrString(obj, thisStr))
        return NULL;

    PyObject *thisAttr = PyObject_GetAttrString(obj, thisStr);
    if (thisAttr == NULL)
        return NULL;

    // This Python Object is a SWIG Wrapper and contains our pointer
    void *pointer = ((PySwigObject *)thisAttr)->ptr;
    Py_DECREF(thisAttr);
    return pointer;
}

BOOST_PYTHON_MODULE(_SireOpenMM)
{
    bp::class_<OpenMMMetaData> OpenMMMetaData_exposer_t("OpenMMMetaData",
                                                        "Internal class used to hold OpenMM coordinates and velocities data");

    OpenMMMetaData_exposer_t.def(
        "index", &OpenMMMetaData::index,
        "Return the index used to locate atoms in the OpenMM system");

    OpenMMMetaData_exposer_t.def(
        "lambdaLever", &OpenMMMetaData::lambdaLever,
        "Return the lambda lever used to update the parameters in the "
        "OpenMM system according to lambda");

    bp::class_<LambdaLever, bp::bases<SireBase::Property>> LambdaLever_exposer_t(
        "LambdaLever",
        "A lever that can be used to change the parameters in an OpenMM system "
        "based on a lambda value (or collection of lambda values)");

    LambdaLever_exposer_t.def(
        "set_lambda", &LambdaLever::setLambda,
        (bp::arg("system"), bp::arg("lambda_value")),
        "Update the parameters in the passed context using this lambda lever "
        "so that the parameters represent the system at the specified "
        "lambda value");

    LambdaLever_exposer_t.def(
        "schedule", &LambdaLever::getSchedule,
        "Return the LambdaSchedule used to control the parameters by lambda");

    LambdaLever_exposer_t.def(
        "set_schedule", &LambdaLever::setSchedule,
        "Set the LambdaSchedule used to control the parameters by lambda");

    LambdaLever_exposer_t.def(
        "get_perturbable_molecule_maps", &LambdaLever::getPerturbableMoleculeMaps,
        "Return the perturbable molecule maps for all of the perturbable molecules");

    bp::def("_openmm_system_to_sire",
            &openmm_system_to_sire,
            (bp::arg("system"), bp::arg("map")),
            "Convert an OpenMM::System to a set of sire molecules.");

    bp::def("_sire_to_openmm_system",
            &sire_to_openmm_system,
            (bp::arg("system"), bp::arg("mols"), bp::arg("map")),
            "Convert sire molecules to an OpenMM::System");

    bp::def("_set_openmm_coordinates_and_velocities",
            &set_openmm_coordinates_and_velocities,
            (bp::arg("context"), bp::arg("coords_and_velocities")),
            "Set the coordinates and velocities in a context");

    bp::def("_openmm_extract_coordinates",
            &extract_coordinates,
            (bp::arg("state"), bp::arg("mols"), bp::arg("perturbable_maps"), bp::arg("map")),
            "Extract the coordinates from 'state' and copy then into the passed 'mols'");

    bp::def("_openmm_extract_coordinates_and_velocities",
            &extract_coordinates_and_velocities,
            (bp::arg("state"), bp::arg("mols"), bp::arg("perturbable_maps"), bp::arg("map")),
            "Extract the coordinates and velocities from 'state' and copy then into the passed 'mols'");

    bp::def("_openmm_extract_space",
            &extract_space,
            (bp::arg("state")),
            "Extract and return the space from 'state'");

    bp::def("_openmm_set_context_platform_property",
            &set_context_platform_property,
            (bp::arg("context"), bp::arg("key"), bp::arg("value")),
            "Set the Platform property for the passed context.");

    bp::def("_minimise_openmm_context",
            &minimise_openmm_context,
            (bp::arg("context"), bp::arg("tolerance") = 10, bp::arg("max_iterations") = -1),
            "Minimise the passed context");

    bp::converter::registry::insert(&extract_swig_wrapped_pointer, bp::type_id<OpenMM::System>());
    bp::converter::registry::insert(&extract_swig_wrapped_pointer, bp::type_id<OpenMM::Context>());
    bp::converter::registry::insert(&extract_swig_wrapped_pointer, bp::type_id<OpenMM::State>());
    bp::converter::registry::insert(&extract_swig_wrapped_pointer, bp::type_id<OpenMM::Integrator>());
}
