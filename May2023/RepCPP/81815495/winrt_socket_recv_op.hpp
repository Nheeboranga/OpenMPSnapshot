
#ifndef ASIO_DETAIL_WINRT_SOCKET_RECV_OP_HPP
#define ASIO_DETAIL_WINRT_SOCKET_RECV_OP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include "asio/detail/config.hpp"

#if defined(ASIO_WINDOWS_RUNTIME)

#include "asio/detail/bind_handler.hpp"
#include "asio/detail/buffer_sequence_adapter.hpp"
#include "asio/detail/fenced_block.hpp"
#include "asio/detail/handler_alloc_helpers.hpp"
#include "asio/detail/handler_invoke_helpers.hpp"
#include "asio/detail/handler_work.hpp"
#include "asio/detail/memory.hpp"
#include "asio/detail/winrt_async_op.hpp"
#include "asio/error.hpp"

#include "asio/detail/push_options.hpp"

namespace asio {
namespace detail {

template <typename MutableBufferSequence, typename Handler, typename IoExecutor>
class winrt_socket_recv_op :
public winrt_async_op<Windows::Storage::Streams::IBuffer^>
{
public:
ASIO_DEFINE_HANDLER_PTR(winrt_socket_recv_op);

winrt_socket_recv_op(const MutableBufferSequence& buffers,
Handler& handler, const IoExecutor& io_ex)
: winrt_async_op<Windows::Storage::Streams::IBuffer^>(
&winrt_socket_recv_op::do_complete),
buffers_(buffers),
handler_(ASIO_MOVE_CAST(Handler)(handler)),
work_(handler_, io_ex)
{
}

static void do_complete(void* owner, operation* base,
const asio::error_code&, std::size_t)
{
winrt_socket_recv_op* o(static_cast<winrt_socket_recv_op*>(base));
ptr p = { asio::detail::addressof(o->handler_), o, o };

ASIO_HANDLER_COMPLETION((*o));

handler_work<Handler, IoExecutor> w(
ASIO_MOVE_CAST2(handler_work<Handler, IoExecutor>)(
o->work_));

#if defined(ASIO_ENABLE_BUFFER_DEBUGGING)
if (owner)
{
buffer_sequence_adapter<asio::mutable_buffer,
MutableBufferSequence>::validate(o->buffers_);
}
#endif 

std::size_t bytes_transferred = o->result_ ? o->result_->Length : 0;
if (bytes_transferred == 0 && !o->ec_ &&
!buffer_sequence_adapter<asio::mutable_buffer,
MutableBufferSequence>::all_empty(o->buffers_))
{
o->ec_ = asio::error::eof;
}

detail::binder2<Handler, asio::error_code, std::size_t>
handler(o->handler_, o->ec_, bytes_transferred);
p.h = asio::detail::addressof(handler.handler_);
p.reset();

if (owner)
{
fenced_block b(fenced_block::half);
ASIO_HANDLER_INVOCATION_BEGIN((handler.arg1_, handler.arg2_));
w.complete(handler, handler.handler_);
ASIO_HANDLER_INVOCATION_END;
}
}

private:
MutableBufferSequence buffers_;
Handler handler_;
handler_work<Handler, IoExecutor> executor_;
};

} 
} 

#include "asio/detail/pop_options.hpp"

#endif 

#endif 
