

#pragma once

#ifdef ALPAKA_ACC_GPU_CUDA_ENABLED

#    include <alpaka/core/ApiCudaRt.hpp>
#    include <alpaka/kernel/TaskKernelGpuUniformCudaHipRt.hpp>

namespace alpaka
{
template<typename TAcc, typename TDim, typename TIdx, typename TKernelFnObj, typename... TArgs>
using TaskKernelGpuCudaRt = TaskKernelGpuUniformCudaHipRt<ApiCudaRt, TAcc, TDim, TIdx, TKernelFnObj, TArgs...>;
}

#endif 
