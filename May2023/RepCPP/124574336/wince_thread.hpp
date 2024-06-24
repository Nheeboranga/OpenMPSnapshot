
#ifndef BOOST_ASIO_DETAIL_WINCE_THREAD_HPP
#define BOOST_ASIO_DETAIL_WINCE_THREAD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_WINDOWS) && defined(UNDER_CE)

#include <boost/asio/detail/noncopyable.hpp>
#include <boost/asio/detail/scoped_ptr.hpp>
#include <boost/asio/detail/socket_types.hpp>
#include <boost/asio/detail/throw_error.hpp>
#include <boost/asio/error.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

DWORD WINAPI wince_thread_function(LPVOID arg);

class wince_thread
: private noncopyable
{
public:
template <typename Function>
wince_thread(Function f, unsigned int = 0)
{
scoped_ptr<func_base> arg(new func<Function>(f));
DWORD thread_id = 0;
thread_ = ::CreateThread(0, 0, wince_thread_function,
arg.get(), 0, &thread_id);
if (!thread_)
{
DWORD last_error = ::GetLastError();
boost::system::error_code ec(last_error,
boost::asio::error::get_system_category());
boost::asio::detail::throw_error(ec, "thread");
}
arg.release();
}

~wince_thread()
{
::CloseHandle(thread_);
}

void join()
{
::WaitForSingleObject(thread_, INFINITE);
}

static std::size_t hardware_concurrency()
{
SYSTEM_INFO system_info;
::GetSystemInfo(&system_info);
return system_info.dwNumberOfProcessors;
}

private:
friend DWORD WINAPI wince_thread_function(LPVOID arg);

class func_base
{
public:
virtual ~func_base() {}
virtual void run() = 0;
};

template <typename Function>
class func
: public func_base
{
public:
func(Function f)
: f_(f)
{
}

virtual void run()
{
f_();
}

private:
Function f_;
};

::HANDLE thread_;
};

inline DWORD WINAPI wince_thread_function(LPVOID arg)
{
scoped_ptr<wince_thread::func_base> func(
static_cast<wince_thread::func_base*>(arg));
func->run();
return 0;
}

} 
} 
} 

#include <boost/asio/detail/pop_options.hpp>

#endif 

#endif 
