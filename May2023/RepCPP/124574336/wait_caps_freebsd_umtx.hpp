


#ifndef BOOST_ATOMIC_DETAIL_WAIT_CAPS_FREEBSD_UMTX_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_WAIT_CAPS_FREEBSD_UMTX_HPP_INCLUDED_

#include <sys/umtx.h>
#include <boost/atomic/detail/config.hpp>
#include <boost/atomic/detail/int_sizes.hpp>
#include <boost/atomic/detail/capabilities.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif


#if (defined(UMTX_OP_WAIT_UINT) && BOOST_ATOMIC_DETAIL_SIZEOF_INT == 4) ||\
(defined(UMTX_OP_WAIT) && BOOST_ATOMIC_DETAIL_SIZEOF_LONG == 4)
#define BOOST_ATOMIC_HAS_NATIVE_INT32_WAIT_NOTIFY BOOST_ATOMIC_INT32_LOCK_FREE
#define BOOST_ATOMIC_HAS_NATIVE_INT32_IPC_WAIT_NOTIFY BOOST_ATOMIC_INT32_LOCK_FREE
#endif

#if defined(UMTX_OP_WAIT) && BOOST_ATOMIC_DETAIL_SIZEOF_LONG == 8
#define BOOST_ATOMIC_HAS_NATIVE_INT64_WAIT_NOTIFY BOOST_ATOMIC_INT64_LOCK_FREE
#define BOOST_ATOMIC_HAS_NATIVE_INT64_IPC_WAIT_NOTIFY BOOST_ATOMIC_INT64_LOCK_FREE
#endif

#endif 
