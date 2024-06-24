

#pragma once

#if defined(ALPAKA_ACC_GPU_CUDA_ENABLED) || defined(ALPAKA_ACC_GPU_HIP_ENABLED)

#    include <alpaka/core/BoostPredef.hpp>
#    include <alpaka/core/Concepts.hpp>
#    include <alpaka/intrinsic/Traits.hpp>

namespace alpaka
{
class IntrinsicUniformCudaHipBuiltIn
: public concepts::Implements<ConceptIntrinsic, IntrinsicUniformCudaHipBuiltIn>
{
};

#    if !defined(ALPAKA_HOST_ONLY)

#        if defined(ALPAKA_ACC_GPU_CUDA_ENABLED) && !BOOST_LANG_CUDA
#            error If ALPAKA_ACC_GPU_CUDA_ENABLED is set, the compiler has to support CUDA!
#        endif

#        if defined(ALPAKA_ACC_GPU_HIP_ENABLED) && !BOOST_LANG_HIP
#            error If ALPAKA_ACC_GPU_HIP_ENABLED is set, the compiler has to support HIP!
#        endif

namespace trait
{
template<>
struct Popcount<IntrinsicUniformCudaHipBuiltIn>
{
__device__ static auto popcount(IntrinsicUniformCudaHipBuiltIn const& , std::uint32_t value)
-> std::int32_t
{
#        if BOOST_COMP_CLANG && BOOST_LANG_CUDA
return __popc(static_cast<int>(value));
#        else
return static_cast<std::int32_t>(__popc(static_cast<unsigned int>(value)));
#        endif
}

__device__ static auto popcount(IntrinsicUniformCudaHipBuiltIn const& , std::uint64_t value)
-> std::int32_t
{
#        if BOOST_COMP_CLANG && BOOST_LANG_CUDA
return __popcll(static_cast<long long>(value));
#        else
return static_cast<std::int32_t>(__popcll(static_cast<unsigned long long>(value)));
#        endif
}
};

template<>
struct Ffs<IntrinsicUniformCudaHipBuiltIn>
{
__device__ static auto ffs(IntrinsicUniformCudaHipBuiltIn const& , std::int32_t value)
-> std::int32_t
{
return static_cast<std::int32_t>(__ffs(static_cast<int>(value)));
}

__device__ static auto ffs(IntrinsicUniformCudaHipBuiltIn const& , std::int64_t value)
-> std::int32_t
{
return static_cast<std::int32_t>(__ffsll(static_cast<long long>(value)));
}
};
} 

#    endif

} 

#endif