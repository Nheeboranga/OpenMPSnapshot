

#pragma once

#include <hydra/detail/external/hydra_thrust/detail/config.h>
#include <hydra/detail/external/hydra_thrust/system/tbb/detail/execution_policy.h>
#include <hydra/detail/external/hydra_thrust/detail/seq.h>

#include <tbb/parallel_for.h>
#include <hydra/detail/external/hydra_thrust/iterator/iterator_traits.h>
#include <hydra/detail/external/hydra_thrust/detail/minmax.h>
#include <hydra/detail/external/hydra_thrust/system/cpp/memory.h>
#include <hydra/detail/external/hydra_thrust/reduce.h>
#include <cassert>

namespace hydra_thrust
{
namespace system
{
namespace tbb
{
namespace detail
{
namespace reduce_intervals_detail
{


template<typename L, typename R>
inline L divide_ri(const L x, const R y)
{
return (x + (y - 1)) / y;
}


template<typename RandomAccessIterator1, typename RandomAccessIterator2, typename Size, typename BinaryFunction>
struct body
{
RandomAccessIterator1 first;
RandomAccessIterator2 result;
Size n, interval_size;
BinaryFunction binary_op;

body(RandomAccessIterator1 first, RandomAccessIterator2 result, Size n, Size interval_size, BinaryFunction binary_op)
: first(first), result(result), n(n), interval_size(interval_size), binary_op(binary_op)
{}

void operator()(const ::tbb::blocked_range<Size> &r) const
{
assert(r.size() == 1);

Size interval_idx = r.begin();

Size offset_to_first = interval_size * interval_idx;
Size offset_to_last = hydra_thrust::min(n, offset_to_first + interval_size);

RandomAccessIterator1 my_first = first + offset_to_first;
RandomAccessIterator1 my_last  = first + offset_to_last;

typedef typename BinaryFunction::result_type sum_type;
result[interval_idx] =
hydra_thrust::reduce(hydra_thrust::seq, my_first + 1, my_last, sum_type(hydra_thrust::raw_reference_cast(*my_first)), binary_op);
}
};


template<typename RandomAccessIterator1, typename RandomAccessIterator2, typename Size, typename BinaryFunction>
body<RandomAccessIterator1,RandomAccessIterator2,Size,BinaryFunction>
make_body(RandomAccessIterator1 first, RandomAccessIterator2 result, Size n, Size interval_size, BinaryFunction binary_op)
{
return body<RandomAccessIterator1,RandomAccessIterator2,Size,BinaryFunction>(first, result, n, interval_size, binary_op);
}


} 


template<typename DerivedPolicy, typename RandomAccessIterator1, typename Size, typename RandomAccessIterator2, typename BinaryFunction>
void reduce_intervals(hydra_thrust::tbb::execution_policy<DerivedPolicy> &,
RandomAccessIterator1 first,
RandomAccessIterator1 last,
Size interval_size,
RandomAccessIterator2 result,
BinaryFunction binary_op)
{
typename hydra_thrust::iterator_difference<RandomAccessIterator1>::type n = last - first;

Size num_intervals = reduce_intervals_detail::divide_ri(n, interval_size);

::tbb::parallel_for(::tbb::blocked_range<Size>(0, num_intervals, 1), reduce_intervals_detail::make_body(first, result, Size(n), interval_size, binary_op), ::tbb::simple_partitioner());
}


template<typename DerivedPolicy, typename RandomAccessIterator1, typename Size, typename RandomAccessIterator2>
void reduce_intervals(hydra_thrust::tbb::execution_policy<DerivedPolicy> &exec,
RandomAccessIterator1 first,
RandomAccessIterator1 last,
Size interval_size,
RandomAccessIterator2 result)
{
typedef typename hydra_thrust::iterator_value<RandomAccessIterator1>::type value_type;

return hydra_thrust::system::tbb::detail::reduce_intervals(exec, first, last, interval_size, result, hydra_thrust::plus<value_type>());
}


} 
} 
} 
} 

