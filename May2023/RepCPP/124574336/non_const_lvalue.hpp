
#ifndef BOOST_ASIO_DETAIL_NON_CONST_LVALUE_HPP
#define BOOST_ASIO_DETAIL_NON_CONST_LVALUE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/type_traits.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

template <typename T>
struct non_const_lvalue
{
#if defined(BOOST_ASIO_HAS_MOVE)
explicit non_const_lvalue(T& t)
: value(static_cast<typename conditional<
is_same<T, typename decay<T>::type>::value,
typename decay<T>::type&, T&&>::type>(t))
{
}

typename conditional<is_same<T, typename decay<T>::type>::value,
typename decay<T>::type&, typename decay<T>::type>::type value;
#else 
explicit non_const_lvalue(const typename decay<T>::type& t)
: value(t)
{
}

typename decay<T>::type value;
#endif 
};

} 
} 
} 

#include <boost/asio/detail/pop_options.hpp>

#endif 
