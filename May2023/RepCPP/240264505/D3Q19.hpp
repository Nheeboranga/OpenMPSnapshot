

#ifndef LBT_D3Q19
#define LBT_D3Q19
#pragma once

#include <cstdint>
#include <type_traits>

#include "../constexpr_math/constexpr_math.hpp"
#include "../general/type_definitions.hpp"


namespace lbt {
namespace lattice {


template <typename T, typename std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
class D3Q19P20 final {
public:
using type = T;

static constexpr std::int32_t    DIM =  3;
static constexpr std::int32_t SPEEDS = 19;
static constexpr std::int32_t HSPEED = (SPEEDS + 1)/2;

static constexpr std::int32_t PAD = 1;
static constexpr std::int32_t  ND = SPEEDS + PAD;
static constexpr std::int32_t OFF = ND/2;

LBT_ALIGN static constexpr lbt::StackArray<T, ND> DX =
{ 0,  1,  0,  0,  1,  1,  1,  1,  0,  0,   
0, -1,  0,  0, -1, -1, -1, -1,  0,  0 }; 
LBT_ALIGN static constexpr lbt::StackArray<T, ND> DY =
{ 0,  0,  1,  0,  1, -1,  0,  0,  1,  1,
0,  0, -1,  0, -1,  1,  0,  0, -1, -1 };
LBT_ALIGN static constexpr lbt::StackArray<T, ND> DZ =
{ 0,  0,  0,  1,  0,  0,  1, -1,  1, -1,
0,  0,  0, -1,  0,  0, -1,  1, -1,  1 };

LBT_ALIGN static constexpr lbt::StackArray<T, ND> W =
{ 1.0/3.0,                        
1.0/18.0, 1.0/18.0, 1.0/18.0,
1.0/36.0, 1.0/36.0, 1.0/36.0,
1.0/36.0, 1.0/36.0, 1.0/36.0,
1.0/3.0,                        
1.0/18.0, 1.0/18.0, 1.0/18.0,
1.0/36.0, 1.0/36.0, 1.0/36.0,
1.0/36.0, 1.0/36.0, 1.0/36.0 };

LBT_ALIGN static constexpr lbt::StackArray<T, ND> MASK =
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

static constexpr T CS = 1.0/cem::sqrt(3.0);
};

template<typename T> using D3Q19 = D3Q19P20<T>;

}
}

#endif 
