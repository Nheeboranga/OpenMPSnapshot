


#pragma once

#if defined(ALPAKA_ACC_SYCL_ENABLED) && defined(ALPAKA_SYCL_BACKEND_ONEAPI) && defined(ALPAKA_SYCL_ONEAPI_FPGA)

#    include <alpaka/dev/DevFpgaSyclIntel.hpp>
#    include <alpaka/queue/QueueGenericSyclBlocking.hpp>

namespace alpaka
{
using QueueFpgaSyclIntelBlocking = QueueGenericSyclBlocking<DevFpgaSyclIntel>;
}

#endif