
#ifndef ASIO_EXECUTION_SET_DONE_HPP
#define ASIO_EXECUTION_SET_DONE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include "asio/detail/config.hpp"
#include "asio/detail/type_traits.hpp"
#include "asio/traits/set_done_member.hpp"
#include "asio/traits/set_done_free.hpp"

#include "asio/detail/push_options.hpp"

#if defined(GENERATING_DOCUMENTATION)

namespace asio {
namespace execution {


inline constexpr unspecified set_done = unspecified;


template <typename R>
struct can_set_done :
integral_constant<bool, automatically_determined>
{
};

} 
} 

#else 

namespace asio_execution_set_done_fn {

using asio::decay;
using asio::declval;
using asio::enable_if;
using asio::traits::set_done_free;
using asio::traits::set_done_member;

void set_done();

enum overload_type
{
call_member,
call_free,
ill_formed
};

template <typename R, typename = void, typename = void>
struct call_traits
{
ASIO_STATIC_CONSTEXPR(overload_type, overload = ill_formed);
ASIO_STATIC_CONSTEXPR(bool, is_noexcept = false);
typedef void result_type;
};

template <typename R>
struct call_traits<R,
typename enable_if<
set_done_member<R>::is_valid
>::type> :
set_done_member<R>
{
ASIO_STATIC_CONSTEXPR(overload_type, overload = call_member);
};

template <typename R>
struct call_traits<R,
typename enable_if<
!set_done_member<R>::is_valid
>::type,
typename enable_if<
set_done_free<R>::is_valid
>::type> :
set_done_free<R>
{
ASIO_STATIC_CONSTEXPR(overload_type, overload = call_free);
};

struct impl
{
#if defined(ASIO_HAS_MOVE)
template <typename R>
ASIO_CONSTEXPR typename enable_if<
call_traits<R>::overload == call_member,
typename call_traits<R>::result_type
>::type
operator()(R&& r) const
ASIO_NOEXCEPT_IF((
call_traits<R>::is_noexcept))
{
return ASIO_MOVE_CAST(R)(r).set_done();
}

template <typename R>
ASIO_CONSTEXPR typename enable_if<
call_traits<R>::overload == call_free,
typename call_traits<R>::result_type
>::type
operator()(R&& r) const
ASIO_NOEXCEPT_IF((
call_traits<R>::is_noexcept))
{
return set_done(ASIO_MOVE_CAST(R)(r));
}
#else 
template <typename R>
ASIO_CONSTEXPR typename enable_if<
call_traits<R&>::overload == call_member,
typename call_traits<R&>::result_type
>::type
operator()(R& r) const
ASIO_NOEXCEPT_IF((
call_traits<R&>::is_noexcept))
{
return r.set_done();
}

template <typename R>
ASIO_CONSTEXPR typename enable_if<
call_traits<const R&>::overload == call_member,
typename call_traits<const R&>::result_type
>::type
operator()(const R& r) const
ASIO_NOEXCEPT_IF((
call_traits<const R&>::is_noexcept))
{
return r.set_done();
}

template <typename R>
ASIO_CONSTEXPR typename enable_if<
call_traits<R&>::overload == call_free,
typename call_traits<R&>::result_type
>::type
operator()(R& r) const
ASIO_NOEXCEPT_IF((
call_traits<R&>::is_noexcept))
{
return set_done(r);
}

template <typename R>
ASIO_CONSTEXPR typename enable_if<
call_traits<const R&>::overload == call_free,
typename call_traits<const R&>::result_type
>::type
operator()(const R& r) const
ASIO_NOEXCEPT_IF((
call_traits<const R&>::is_noexcept))
{
return set_done(r);
}
#endif 
};

template <typename T = impl>
struct static_instance
{
static const T instance;
};

template <typename T>
const T static_instance<T>::instance = {};

} 
namespace asio {
namespace execution {
namespace {

static ASIO_CONSTEXPR const asio_execution_set_done_fn::impl&
set_done = asio_execution_set_done_fn::static_instance<>::instance;

} 

template <typename R>
struct can_set_done :
integral_constant<bool,
asio_execution_set_done_fn::call_traits<R>::overload !=
asio_execution_set_done_fn::ill_formed>
{
};

#if defined(ASIO_HAS_VARIABLE_TEMPLATES)

template <typename R>
constexpr bool can_set_done_v = can_set_done<R>::value;

#endif 

template <typename R>
struct is_nothrow_set_done :
integral_constant<bool,
asio_execution_set_done_fn::call_traits<R>::is_noexcept>
{
};

#if defined(ASIO_HAS_VARIABLE_TEMPLATES)

template <typename R>
constexpr bool is_nothrow_set_done_v
= is_nothrow_set_done<R>::value;

#endif 

} 
} 

#endif 

#include "asio/detail/pop_options.hpp"

#endif 