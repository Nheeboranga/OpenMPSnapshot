
#pragma once

#include "../mat2x2.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_EXT_matrix_uint2x2 extension included")
#endif

namespace glm
{

typedef mat<2, 2, uint, defaultp>	umat2x2;

typedef mat<2, 2, uint, defaultp>	umat2;

}
