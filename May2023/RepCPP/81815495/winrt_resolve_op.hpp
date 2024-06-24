
#ifndef ASIO_DETAIL_WINRT_RESOLVE_OP_HPP
#define ASIO_DETAIL_WINRT_RESOLVE_OP_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include "asio/detail/config.hpp"

#if defined(ASIO_WINDOWS_RUNTIME)

#include "asio/detail/bind_handler.hpp"
#include "asio/detail/fenced_block.hpp"
#include "asio/detail/handler_alloc_helpers.hpp"
#include "asio/detail/handler_invoke_helpers.hpp"
#include "asio/detail/handler_work.hpp"
#include "asio/detail/memory.hpp"
#include "asio/detail/winrt_async_op.hpp"
#include "asio/ip/basic_resolver_results.hpp"
#include "asio/error.hpp"

#include "asio/detail/push_options.hpp"

namespace asio {
namespace detail {

template <typename Protocol, typename Handler, typename IoExecutor>
class winrt_resolve_op :
public winrt_async_op<
Windows::Foundation::Collections::IVectorView<
Windows::Networking::EndpointPair^>^>
{
public:
ASIO_DEFINE_HANDLER_PTR(winrt_resolve_op);

typedef typename Protocol::endpoint endpoint_type;
typedef asio::ip::basic_resolver_query<Protocol> query_type;
typedef asio::ip::basic_resolver_results<Protocol> results_type;

winrt_resolve_op(const query_type& query,
Handler& handler, const IoExecutor& io_ex)
: winrt_async_op<
Windows::Foundation::Collections::IVectorView<
Windows::Networking::EndpointPair^>^>(
&winrt_resolve_op::do_complete),
query_(query),
handler_(ASIO_MOVE_CAST(Handler)(handler)),
work_(handler_, io_ex)
{
}

static void do_complete(void* owner, operation* base,
const asio::error_code&, std::size_t)
{
winrt_resolve_op* o(static_cast<winrt_resolve_op*>(base));
ptr p = { asio::detail::addressof(o->handler_), o, o };

ASIO_HANDLER_COMPLETION((*o));

handler_work<Handler, IoExecutor> w(
ASIO_MOVE_CAST2(handler_work<Handler, IoExecutor>)(
o->work_));

results_type results = results_type();
if (!o->ec_)
{
try
{
results = results_type::create(o->result_, o->query_.hints(),
o->query_.host_name(), o->query_.service_name());
}
catch (Platform::Exception^ e)
{
o->ec_ = asio::error_code(e->HResult,
asio::system_category());
}
}

detail::binder2<Handler, asio::error_code, results_type>
handler(o->handler_, o->ec_, results);
p.h = asio::detail::addressof(handler.handler_);
p.reset();

if (owner)
{
fenced_block b(fenced_block::half);
ASIO_HANDLER_INVOCATION_BEGIN((handler.arg1_, "..."));
w.complete(handler, handler.handler_);
ASIO_HANDLER_INVOCATION_END;
}
}

private:
query_type query_;
Handler handler_;
handler_work<Handler, IoExecutor> executor_;
};

} 
} 

#include "asio/detail/pop_options.hpp"

#endif 

#endif 