
#ifndef BOOST_ASIO_DETAIL_RESOLVER_SERVICE_BASE_HPP
#define BOOST_ASIO_DETAIL_RESOLVER_SERVICE_BASE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include <boost/asio/detail/config.hpp>
#include <boost/asio/error.hpp>
#include <boost/asio/execution_context.hpp>
#include <boost/asio/detail/mutex.hpp>
#include <boost/asio/detail/noncopyable.hpp>
#include <boost/asio/detail/resolve_op.hpp>
#include <boost/asio/detail/socket_ops.hpp>
#include <boost/asio/detail/socket_types.hpp>
#include <boost/asio/detail/scoped_ptr.hpp>
#include <boost/asio/detail/thread.hpp>

#if defined(BOOST_ASIO_HAS_IOCP)
# include <boost/asio/detail/win_iocp_io_context.hpp>
#else 
# include <boost/asio/detail/scheduler.hpp>
#endif 

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

class resolver_service_base
{
public:
typedef socket_ops::shared_cancel_token_type implementation_type;

BOOST_ASIO_DECL resolver_service_base(execution_context& context);

BOOST_ASIO_DECL ~resolver_service_base();

BOOST_ASIO_DECL void base_shutdown();

BOOST_ASIO_DECL void base_notify_fork(
execution_context::fork_event fork_ev);

BOOST_ASIO_DECL void construct(implementation_type& impl);

BOOST_ASIO_DECL void destroy(implementation_type&);

BOOST_ASIO_DECL void move_construct(implementation_type& impl,
implementation_type& other_impl);

BOOST_ASIO_DECL void move_assign(implementation_type& impl,
resolver_service_base& other_service,
implementation_type& other_impl);

void converting_move_construct(implementation_type& impl,
resolver_service_base&, implementation_type& other_impl)
{
move_construct(impl, other_impl);
}

void converting_move_assign(implementation_type& impl,
resolver_service_base& other_service,
implementation_type& other_impl)
{
move_assign(impl, other_service, other_impl);
}

BOOST_ASIO_DECL void cancel(implementation_type& impl);

protected:
BOOST_ASIO_DECL void start_resolve_op(resolve_op* op);

#if !defined(BOOST_ASIO_WINDOWS_RUNTIME)
class auto_addrinfo
: private boost::asio::detail::noncopyable
{
public:
explicit auto_addrinfo(boost::asio::detail::addrinfo_type* ai)
: ai_(ai)
{
}

~auto_addrinfo()
{
if (ai_)
socket_ops::freeaddrinfo(ai_);
}

operator boost::asio::detail::addrinfo_type*()
{
return ai_;
}

private:
boost::asio::detail::addrinfo_type* ai_;
};
#endif 

class work_scheduler_runner;

BOOST_ASIO_DECL void start_work_thread();

#if defined(BOOST_ASIO_HAS_IOCP)
typedef class win_iocp_io_context scheduler_impl;
#else
typedef class scheduler scheduler_impl;
#endif
scheduler_impl& scheduler_;

private:
boost::asio::detail::mutex mutex_;

boost::asio::detail::scoped_ptr<scheduler_impl> work_scheduler_;

boost::asio::detail::scoped_ptr<boost::asio::detail::thread> work_thread_;
};

} 
} 
} 

#include <boost/asio/detail/pop_options.hpp>

#if defined(BOOST_ASIO_HEADER_ONLY)
# include <boost/asio/detail/impl/resolver_service_base.ipp>
#endif 

#endif 