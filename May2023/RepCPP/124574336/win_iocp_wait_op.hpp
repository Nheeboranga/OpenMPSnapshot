
#ifndef BOOST_ASIO_DETAIL_WIN_IOCP_WAIT_OP_HPP
#define BOOST_ASIO_DETAIL_WIN_IOCP_WAIT_OP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_IOCP)

#include <boost/asio/detail/bind_handler.hpp>
#include <boost/asio/detail/buffer_sequence_adapter.hpp>
#include <boost/asio/detail/fenced_block.hpp>
#include <boost/asio/detail/handler_alloc_helpers.hpp>
#include <boost/asio/detail/handler_invoke_helpers.hpp>
#include <boost/asio/detail/handler_work.hpp>
#include <boost/asio/detail/memory.hpp>
#include <boost/asio/detail/reactor_op.hpp>
#include <boost/asio/detail/socket_ops.hpp>
#include <boost/asio/error.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

template <typename Handler, typename IoExecutor>
class win_iocp_wait_op : public reactor_op
{
public:
BOOST_ASIO_DEFINE_HANDLER_PTR(win_iocp_wait_op);

win_iocp_wait_op(socket_ops::weak_cancel_token_type cancel_token,
Handler& handler, const IoExecutor& io_ex)
: reactor_op(boost::system::error_code(),
&win_iocp_wait_op::do_perform,
&win_iocp_wait_op::do_complete),
cancel_token_(cancel_token),
handler_(BOOST_ASIO_MOVE_CAST(Handler)(handler)),
work_(handler_, io_ex)
{
}

static status do_perform(reactor_op*)
{
return done;
}

static void do_complete(void* owner, operation* base,
const boost::system::error_code& result_ec,
std::size_t )
{
boost::system::error_code ec(result_ec);

win_iocp_wait_op* o(static_cast<win_iocp_wait_op*>(base));
ptr p = { boost::asio::detail::addressof(o->handler_), o, o };

BOOST_ASIO_HANDLER_COMPLETION((*o));

handler_work<Handler, IoExecutor> w(
BOOST_ASIO_MOVE_CAST2(handler_work<Handler, IoExecutor>)(
o->work_));

if (o->ec_)
ec = o->ec_;

if (ec.value() == ERROR_NETNAME_DELETED)
{
if (o->cancel_token_.expired())
ec = boost::asio::error::operation_aborted;
else
ec = boost::asio::error::connection_reset;
}
else if (ec.value() == ERROR_PORT_UNREACHABLE)
{
ec = boost::asio::error::connection_refused;
}

detail::binder1<Handler, boost::system::error_code>
handler(o->handler_, ec);
p.h = boost::asio::detail::addressof(handler.handler_);
p.reset();

if (owner)
{
fenced_block b(fenced_block::half);
BOOST_ASIO_HANDLER_INVOCATION_BEGIN((handler.arg1_));
w.complete(handler, handler.handler_);
BOOST_ASIO_HANDLER_INVOCATION_END;
}
}

private:
socket_ops::weak_cancel_token_type cancel_token_;
Handler handler_;
handler_work<Handler, IoExecutor> work_;
};

} 
} 
} 

#include <boost/asio/detail/pop_options.hpp>

#endif 

#endif 