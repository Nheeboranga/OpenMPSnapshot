
#pragma once

#include "../detail/setup.hpp"

#if GLM_MESSAGES == GLM_ENABLE && !defined(GLM_EXT_INCLUDED)
#	ifndef GLM_ENABLE_EXPERIMENTAL
#		pragma message("GLM: GLM_GTX_scalar_multiplication is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it.")
#	else
#		pragma message("GLM: GLM_GTX_scalar_multiplication extension included")
#	endif
#endif

#include "../vec2.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"
#include "../mat2x2.hpp"
#include <type_traits>

namespace glm
{
template<typename T, typename Vec>
using return_type_scalar_multiplication = typename std::enable_if<
!std::is_same<T, float>::value       
&& std::is_arithmetic<T>::value, Vec 
>::type;

#define GLM_IMPLEMENT_SCAL_MULT(Vec) \
template<typename T> \
return_type_scalar_multiplication<T, Vec> \
operator*(T const& s, Vec rh){ \
return rh *= static_cast<float>(s); \
} \
\
template<typename T> \
return_type_scalar_multiplication<T, Vec> \
operator*(Vec lh, T const& s){ \
return lh *= static_cast<float>(s); \
} \
\
template<typename T> \
return_type_scalar_multiplication<T, Vec> \
operator/(Vec lh, T const& s){ \
return lh *= 1.0f / static_cast<float>(s); \
}

GLM_IMPLEMENT_SCAL_MULT(vec2)
GLM_IMPLEMENT_SCAL_MULT(vec3)
GLM_IMPLEMENT_SCAL_MULT(vec4)

GLM_IMPLEMENT_SCAL_MULT(mat2)
GLM_IMPLEMENT_SCAL_MULT(mat2x3)
GLM_IMPLEMENT_SCAL_MULT(mat2x4)
GLM_IMPLEMENT_SCAL_MULT(mat3x2)
GLM_IMPLEMENT_SCAL_MULT(mat3)
GLM_IMPLEMENT_SCAL_MULT(mat3x4)
GLM_IMPLEMENT_SCAL_MULT(mat4x2)
GLM_IMPLEMENT_SCAL_MULT(mat4x3)
GLM_IMPLEMENT_SCAL_MULT(mat4)

#undef GLM_IMPLEMENT_SCAL_MULT
} 