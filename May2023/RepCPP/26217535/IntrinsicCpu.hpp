

#pragma once

#include <alpaka/core/BoostPredef.hpp>
#include <alpaka/intrinsic/IntrinsicFallback.hpp>
#include <alpaka/intrinsic/Traits.hpp>

#include <bitset>
#include <climits>
#if __has_include(<bit>)
#    include <bit>
#endif

#if BOOST_COMP_MSVC
#    include <intrin.h>
#endif

namespace alpaka
{
class IntrinsicCpu : public concepts::Implements<ConceptIntrinsic, IntrinsicCpu>
{
};

namespace trait
{
template<>
struct Popcount<IntrinsicCpu>
{
template<typename UnsignedIntegral>
static auto popcount(IntrinsicCpu const& , UnsignedIntegral value) -> std::int32_t
{
#ifdef __cpp_lib_bitops
return std::popcount(value);
#elif BOOST_COMP_GNUC || BOOST_COMP_CLANG
if constexpr(sizeof(UnsignedIntegral) == 8)
return __builtin_popcountll(value);
else
return __builtin_popcount(value);
#elif BOOST_COMP_MSVC
if constexpr(sizeof(UnsignedIntegral) == 8)
return static_cast<std::int32_t>(__popcnt64(value));
else
return __popcnt(value);
#else
return static_cast<std::int32_t>(std::bitset<sizeof(UnsignedIntegral) * CHAR_BIT>(value).count());
#endif
}
};

template<>
struct Ffs<IntrinsicCpu>
{
template<typename Integral>
static auto ffs(IntrinsicCpu const& , Integral value) -> std::int32_t
{
#ifdef __cpp_lib_bitops
return value == 0 ? 0 : std::countr_zero(static_cast<std::make_unsigned_t<Integral>>(value)) + 1;
#elif BOOST_COMP_GNUC || BOOST_COMP_CLANG
if constexpr(sizeof(Integral) == 8)
return __builtin_ffsll(value);
else
return __builtin_ffs(value);
#elif BOOST_COMP_MSVC
unsigned long index = 0u;
if constexpr(sizeof(Integral) == 8)
return _BitScanForward64(&index, value) == 0 ? 0 : static_cast<std::int32_t>(index + 1u);
else
return _BitScanForward(&index, value) == 0 ? 0 : static_cast<std::int32_t>(index + 1u);
#else
return alpaka::detail::ffsFallback(value);
#endif
}
};
} 
} 