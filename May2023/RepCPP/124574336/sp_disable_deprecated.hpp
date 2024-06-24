#ifndef BOOST_SMART_PTR_DETAIL_SP_DISABLE_DEPRECATED_HPP_INCLUDED
#define BOOST_SMART_PTR_DETAIL_SP_DISABLE_DEPRECATED_HPP_INCLUDED


#if defined(_MSC_VER) && (_MSC_VER >= 1020)
# pragma once
#endif


#include <boost/config.hpp>

#if defined( __GNUC__ ) && ( defined( __GXX_EXPERIMENTAL_CXX0X__ ) || ( __cplusplus >= 201103L ) )

# if defined( BOOST_GCC )

#  if BOOST_GCC >= 40600
#   define BOOST_SP_DISABLE_DEPRECATED
#  endif

# elif defined( __clang__ ) && defined( __has_warning )

#  if __has_warning( "-Wdeprecated-declarations" )
#   define BOOST_SP_DISABLE_DEPRECATED
#  endif

# endif

#endif

#endif 