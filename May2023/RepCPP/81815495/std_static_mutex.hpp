
#ifndef ASIO_DETAIL_STD_STATIC_MUTEX_HPP
#define ASIO_DETAIL_STD_STATIC_MUTEX_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include "asio/detail/config.hpp"

#if defined(ASIO_HAS_STD_MUTEX_AND_CONDVAR)

#include <mutex>
#include "asio/detail/noncopyable.hpp"
#include "asio/detail/scoped_lock.hpp"

#include "asio/detail/push_options.hpp"

namespace asio {
namespace detail {

class std_event;

class std_static_mutex
: private noncopyable
{
public:
typedef asio::detail::scoped_lock<std_static_mutex> scoped_lock;

std_static_mutex(int)
{
}

~std_static_mutex()
{
}

void init()
{
}

void lock()
{
mutex_.lock();
}

void unlock()
{
mutex_.unlock();
}

private:
friend class std_event;
std::mutex mutex_;
};

#define ASIO_STD_STATIC_MUTEX_INIT 0

} 
} 

#include "asio/detail/pop_options.hpp"

#endif 

#endif 
