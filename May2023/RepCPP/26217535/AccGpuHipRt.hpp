

#pragma once

#ifdef ALPAKA_ACC_GPU_HIP_ENABLED

#    include <alpaka/acc/AccGpuUniformCudaHipRt.hpp>
#    include <alpaka/acc/Tag.hpp>
#    include <alpaka/core/ApiHipRt.hpp>

namespace alpaka
{
template<typename TDim, typename TIdx>
using AccGpuHipRt = AccGpuUniformCudaHipRt<ApiHipRt, TDim, TIdx>;

namespace trait
{
template<typename TDim, typename TIdx>
struct AccToTag<alpaka::AccGpuHipRt<TDim, TIdx>>
{
using type = alpaka::TagGpuHipRt;
};

template<typename TDim, typename TIdx>
struct TagToAcc<alpaka::TagGpuHipRt, TDim, TIdx>
{
using type = alpaka::AccGpuHipRt<TDim, TIdx>;
};
} 
} 

#endif 