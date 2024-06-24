

#ifndef BOOST_MULTI_INDEX_DETAIL_ACCESS_SPECIFIER_HPP
#define BOOST_MULTI_INDEX_DETAIL_ACCESS_SPECIFIER_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/config.hpp>
#include <boost/detail/workaround.hpp>



#if defined(BOOST_NO_MEMBER_TEMPLATE_FRIENDS)
#define BOOST_MULTI_INDEX_PROTECTED_IF_MEMBER_TEMPLATE_FRIENDS public
#define BOOST_MULTI_INDEX_PRIVATE_IF_MEMBER_TEMPLATE_FRIENDS public
#else
#define BOOST_MULTI_INDEX_PROTECTED_IF_MEMBER_TEMPLATE_FRIENDS protected
#define BOOST_MULTI_INDEX_PRIVATE_IF_MEMBER_TEMPLATE_FRIENDS private
#endif



#if BOOST_WORKAROUND(__GNUC__,==3)&&(__GNUC_MINOR__<4)||\
BOOST_WORKAROUND(BOOST_MSVC,==1310)||\
BOOST_WORKAROUND(BOOST_MSVC,==1400)||\
BOOST_WORKAROUND(__SUNPRO_CC,BOOST_TESTED_AT(0x590))
#define BOOST_MULTI_INDEX_PRIVATE_IF_USING_DECL_FOR_TEMPL_FUNCTIONS public
#else
#define BOOST_MULTI_INDEX_PRIVATE_IF_USING_DECL_FOR_TEMPL_FUNCTIONS private
#endif

#endif