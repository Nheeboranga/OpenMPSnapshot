




#pragma once

#include <hydra/detail/external/hydra_thrust/tuple.h>
#include <hydra/detail/external/hydra_thrust/iterator/iterator_traits.h>
#include <hydra/detail/external/hydra_thrust/detail/type_traits.h>
#include <hydra/detail/external/hydra_thrust/iterator/detail/tuple_of_iterator_references.h>
#include <hydra/detail/external/hydra_thrust/detail/raw_reference_cast.h>
#include <memory> 

namespace hydra_thrust
{
namespace detail
{

template<typename Predicate>
struct unary_negate
{
typedef bool result_type;

Predicate pred;

__host__ __device__
explicit unary_negate(const Predicate& pred) : pred(pred) {}

template <typename T>
__host__ __device__
bool operator()(const T& x)
{
return !bool(pred(x));
}
};

template<typename Predicate>
struct binary_negate
{
typedef bool result_type;

Predicate pred;

__host__ __device__
explicit binary_negate(const Predicate& pred) : pred(pred) {}

template <typename T1, typename T2>
__host__ __device__
bool operator()(const T1& x, const T2& y)
{
return !bool(pred(x,y));
}
};

template<typename Predicate>
__host__ __device__
hydra_thrust::detail::unary_negate<Predicate> not1(const Predicate &pred)
{
return hydra_thrust::detail::unary_negate<Predicate>(pred);
}

template<typename Predicate>
__host__ __device__
hydra_thrust::detail::binary_negate<Predicate> not2(const Predicate &pred)
{
return hydra_thrust::detail::binary_negate<Predicate>(pred);
}


template<typename Predicate, typename IntegralType>
struct predicate_to_integral
{
Predicate pred;

__host__ __device__
explicit predicate_to_integral(const Predicate& pred) : pred(pred) {}

template <typename T>
__host__ __device__
bool operator()(const T& x)
{
return pred(x) ? IntegralType(1) : IntegralType(0);
}
};


template<typename T1>
struct equal_to
{
typedef bool result_type;

template <typename T2>
__host__ __device__
bool operator()(const T1& lhs, const T2& rhs) const
{
return lhs == rhs;
}
};

template<typename T2>
struct equal_to_value
{
T2 rhs;

__host__ __device__
equal_to_value(const T2& rhs) : rhs(rhs) {}

template <typename T1>
__host__ __device__
bool operator()(const T1& lhs) const
{
return lhs == rhs;
}
};

template<typename Predicate>
struct tuple_binary_predicate
{
typedef bool result_type;

__host__ __device__
tuple_binary_predicate(const Predicate& p) : pred(p) {}

template<typename Tuple>
__host__ __device__
bool operator()(const Tuple& t) const
{
return pred(hydra_thrust::get<0>(t), hydra_thrust::get<1>(t));
}

mutable Predicate pred;
};

template<typename Predicate>
struct tuple_not_binary_predicate
{
typedef bool result_type;

__host__ __device__
tuple_not_binary_predicate(const Predicate& p) : pred(p) {}

template<typename Tuple>
__host__ __device__
bool operator()(const Tuple& t) const
{
return !pred(hydra_thrust::get<0>(t), hydra_thrust::get<1>(t));
}

mutable Predicate pred;
};

template<typename Generator>
struct host_generate_functor
{
typedef void result_type;

__hydra_thrust_exec_check_disable__
__host__ __device__
host_generate_functor(Generator g)
: gen(g) {}

template<typename T>
__host__
void operator()(const T &x)
{
T &lvalue = const_cast<T&>(x);

lvalue = gen();
}

Generator gen;
};

template<typename Generator>
struct device_generate_functor
{
typedef void result_type;

__hydra_thrust_exec_check_disable__
__host__ __device__
device_generate_functor(Generator g)
: gen(g) {}

template<typename T>
__host__ __device__
void operator()(const T &x)
{
T &lvalue = const_cast<T&>(x);

lvalue = gen();
}

Generator gen;
};

template<typename System, typename Generator>
struct generate_functor
: hydra_thrust::detail::eval_if<
hydra_thrust::detail::is_convertible<System, hydra_thrust::host_system_tag>::value,
hydra_thrust::detail::identity_<host_generate_functor<Generator> >,
hydra_thrust::detail::identity_<device_generate_functor<Generator> >
>
{};


template<typename ResultType, typename BinaryFunction>
struct zipped_binary_op
{
typedef ResultType result_type;

__host__ __device__
zipped_binary_op(BinaryFunction binary_op)
: m_binary_op(binary_op) {}

template<typename Tuple>
__host__ __device__
inline result_type operator()(Tuple t)
{
return m_binary_op(hydra_thrust::get<0>(t), hydra_thrust::get<1>(t));
}

BinaryFunction m_binary_op;
};


template<typename T>
struct is_non_const_reference
: hydra_thrust::detail::and_<
hydra_thrust::detail::not_<hydra_thrust::detail::is_const<T> >,
hydra_thrust::detail::or_<hydra_thrust::detail::is_reference<T>,
hydra_thrust::detail::is_proxy_reference<T> >
>
{};

#ifdef HYDRA_THRUST_VARIADIC_TUPLE
template<typename T> struct is_tuple_of_iterator_references : hydra_thrust::detail::false_type {};

template<typename... Types>
struct is_tuple_of_iterator_references<
hydra_thrust::detail::tuple_of_iterator_references<
Types...
>
>
: hydra_thrust::detail::true_type
{};

template<typename T>
struct enable_if_non_const_reference_or_tuple_of_iterator_references
: hydra_thrust::detail::enable_if<
is_non_const_reference<T>::value || is_tuple_of_iterator_references<T>::value
>
{};
#else

template<typename T> struct is_tuple_of_iterator_references : hydra_thrust::detail::false_type {};

template<typename T1, typename T2, typename T3,
typename T4, typename T5, typename T6,
typename T7, typename T8, typename T9,
typename T10>
struct is_tuple_of_iterator_references<
hydra_thrust::detail::tuple_of_iterator_references<
T1,T2,T3,T4,T5,T6,T7,T8,T9,T10
>
>
: hydra_thrust::detail::true_type
{};

template<typename T>
struct enable_if_non_const_reference_or_tuple_of_iterator_references
: hydra_thrust::detail::enable_if<
is_non_const_reference<T>::value || is_tuple_of_iterator_references<T>::value
>
{};

#endif

template<typename UnaryFunction>
struct unary_transform_functor
{
typedef void result_type;

UnaryFunction f;

__host__ __device__
unary_transform_functor(UnaryFunction f)
: f(f)
{}

__hydra_thrust_exec_check_disable__
template<typename Tuple>
inline __host__ __device__
typename enable_if_non_const_reference_or_tuple_of_iterator_references<
typename hydra_thrust::tuple_element<1,Tuple>::type
>::type
operator()(Tuple t)
{
hydra_thrust::get<1>(t) = f(hydra_thrust::get<0>(t));
}
};


template<typename BinaryFunction>
struct binary_transform_functor
{
BinaryFunction f;

__host__ __device__
binary_transform_functor(BinaryFunction f)
: f(f)
{}

__hydra_thrust_exec_check_disable__
template<typename Tuple>
inline __host__ __device__
typename enable_if_non_const_reference_or_tuple_of_iterator_references<
typename hydra_thrust::tuple_element<2,Tuple>::type
>::type
operator()(Tuple t)
{
hydra_thrust::get<2>(t) = f(hydra_thrust::get<0>(t), hydra_thrust::get<1>(t));
}
};


template<typename UnaryFunction, typename Predicate>
struct unary_transform_if_functor
{
UnaryFunction unary_op;
Predicate pred;

__host__ __device__
unary_transform_if_functor(UnaryFunction unary_op, Predicate pred)
: unary_op(unary_op), pred(pred)
{}

__hydra_thrust_exec_check_disable__
template<typename Tuple>
inline __host__ __device__
typename enable_if_non_const_reference_or_tuple_of_iterator_references<
typename hydra_thrust::tuple_element<1,Tuple>::type
>::type
operator()(Tuple t)
{
if(pred(hydra_thrust::get<0>(t)))
{
hydra_thrust::get<1>(t) = unary_op(hydra_thrust::get<0>(t));
}
}
}; 


template<typename UnaryFunction, typename Predicate>
struct unary_transform_if_with_stencil_functor
{
UnaryFunction unary_op;
Predicate pred;

__host__ __device__
unary_transform_if_with_stencil_functor(UnaryFunction unary_op, Predicate pred)
: unary_op(unary_op), pred(pred)
{}

__hydra_thrust_exec_check_disable__
template<typename Tuple>
inline __host__ __device__
typename enable_if_non_const_reference_or_tuple_of_iterator_references<
typename hydra_thrust::tuple_element<2,Tuple>::type
>::type
operator()(Tuple t)
{
if(pred(hydra_thrust::get<1>(t)))
hydra_thrust::get<2>(t) = unary_op(hydra_thrust::get<0>(t));
}
}; 


template<typename BinaryFunction, typename Predicate>
struct binary_transform_if_functor
{
BinaryFunction binary_op;
Predicate pred;

__host__ __device__
binary_transform_if_functor(BinaryFunction binary_op, Predicate pred)
: binary_op(binary_op), pred(pred) {}

__hydra_thrust_exec_check_disable__
template<typename Tuple>
inline __host__ __device__
typename enable_if_non_const_reference_or_tuple_of_iterator_references<
typename hydra_thrust::tuple_element<3,Tuple>::type
>::type
operator()(Tuple t)
{
if(pred(hydra_thrust::get<2>(t)))
hydra_thrust::get<3>(t) = binary_op(hydra_thrust::get<0>(t), hydra_thrust::get<1>(t));
}
}; 


template<typename T>
struct host_destroy_functor
{
__host__
void operator()(T &x) const
{
x.~T();
} 
}; 


template<typename T>
struct device_destroy_functor
{
__host__ __device__
void operator()(T &x) const
{
x.~T();
} 
}; 


template<typename System, typename T>
struct destroy_functor
: hydra_thrust::detail::eval_if<
hydra_thrust::detail::is_convertible<System, hydra_thrust::host_system_tag>::value,
hydra_thrust::detail::identity_<host_destroy_functor<T> >,
hydra_thrust::detail::identity_<device_destroy_functor<T> >
>
{};


template <typename T>
struct fill_functor
{
T exemplar;

__hydra_thrust_exec_check_disable__
__host__ __device__
fill_functor(const T& _exemplar)
: exemplar(_exemplar) {}

__hydra_thrust_exec_check_disable__
__host__ __device__
fill_functor(const fill_functor & other)
:exemplar(other.exemplar){}

__hydra_thrust_exec_check_disable__
__host__ __device__
~fill_functor() {}

__hydra_thrust_exec_check_disable__
__host__ __device__
T operator()(void) const
{
return exemplar;
}
};


template<typename T>
struct uninitialized_fill_functor
{
T exemplar;

__hydra_thrust_exec_check_disable__
__host__ __device__
uninitialized_fill_functor(T x):exemplar(x){}

__hydra_thrust_exec_check_disable__
__host__ __device__
uninitialized_fill_functor(const uninitialized_fill_functor & other)
:exemplar(other.exemplar){}

__hydra_thrust_exec_check_disable__
__host__ __device__
~uninitialized_fill_functor() {}

__hydra_thrust_exec_check_disable__
__host__ __device__
void operator()(T &x)
{
::new(static_cast<void*>(&x)) T(exemplar);
} 
}; 


template<typename Compare>
struct compare_first_less_second
{
compare_first_less_second(Compare c)
: comp(c) {}

template<typename T1, typename T2>
__host__ __device__
bool operator()(T1 lhs, T2 rhs)
{
return comp(hydra_thrust::get<0>(lhs), hydra_thrust::get<0>(rhs)) || (!comp(hydra_thrust::get<0>(rhs), hydra_thrust::get<0>(lhs)) && hydra_thrust::get<1>(lhs) < hydra_thrust::get<1>(rhs));
}

Compare comp;
}; 


template<typename Compare>
struct compare_first
{
Compare comp;

__host__ __device__
compare_first(Compare comp)
: comp(comp)
{}

template<typename Tuple1, typename Tuple2>
__host__ __device__
bool operator()(const Tuple1 &x, const Tuple2 &y)
{
return comp(hydra_thrust::raw_reference_cast(hydra_thrust::get<0>(x)), hydra_thrust::raw_reference_cast(hydra_thrust::get<0>(y)));
}
}; 


} 
} 

