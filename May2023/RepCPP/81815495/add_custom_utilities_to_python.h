
#pragma once

#include <pybind11/pybind11.h>


#include "includes/define_python.h"

namespace Kratos::Python
{
void  AddCustomUtilitiesToPython(pybind11::module& m);
}  