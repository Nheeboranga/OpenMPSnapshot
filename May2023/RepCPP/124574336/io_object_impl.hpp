
#ifndef BOOST_ASIO_DETAIL_IO_OBJECT_IMPL_HPP
#define BOOST_ASIO_DETAIL_IO_OBJECT_IMPL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include <new>
#include <boost/asio/detail/config.hpp>
#include <boost/asio/detail/type_traits.hpp>
#include <boost/asio/execution/executor.hpp>
#include <boost/asio/execution/context.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/query.hpp>

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

template <typename IoObjectService,
typename Executor = io_context::executor_type>
class io_object_impl
{
public:
typedef IoObjectService service_type;

typedef typename service_type::implementation_type implementation_type;

typedef Executor executor_type;

explicit io_object_impl(const executor_type& ex)
: service_(&boost::asio::use_service<IoObjectService>(
io_object_impl::get_context(ex))),
executor_(ex)
{
service_->construct(implementation_);
}

template <typename ExecutionContext>
explicit io_object_impl(ExecutionContext& context,
typename enable_if<is_convertible<
ExecutionContext&, execution_context&>::value>::type* = 0)
: service_(&boost::asio::use_service<IoObjectService>(context)),
executor_(context.get_executor())
{
service_->construct(implementation_);
}

#if defined(BOOST_ASIO_HAS_MOVE)
io_object_impl(io_object_impl&& other)
: service_(&other.get_service()),
executor_(other.get_executor())
{
service_->move_construct(implementation_, other.implementation_);
}

template <typename IoObjectService1, typename Executor1>
io_object_impl(io_object_impl<IoObjectService1, Executor1>&& other)
: service_(&boost::asio::use_service<IoObjectService>(
io_object_impl::get_context(other.get_executor()))),
executor_(other.get_executor())
{
service_->converting_move_construct(implementation_,
other.get_service(), other.get_implementation());
}
#endif 

~io_object_impl()
{
service_->destroy(implementation_);
}

#if defined(BOOST_ASIO_HAS_MOVE)
io_object_impl& operator=(io_object_impl&& other)
{
if (this != &other)
{
service_->move_assign(implementation_,
*other.service_, other.implementation_);
executor_.~executor_type();
new (&executor_) executor_type(
std::move(other.executor_));
service_ = other.service_;
}
return *this;
}
#endif 

const executor_type& get_executor() BOOST_ASIO_NOEXCEPT
{
return executor_;
}

service_type& get_service()
{
return *service_;
}

const service_type& get_service() const
{
return *service_;
}

implementation_type& get_implementation()
{
return implementation_;
}

const implementation_type& get_implementation() const
{
return implementation_;
}

private:
template <typename T>
static execution_context& get_context(const T& t,
typename enable_if<execution::is_executor<T>::value>::type* = 0)
{
return boost::asio::query(t, execution::context);
}

template <typename T>
static execution_context& get_context(const T& t,
typename enable_if<!execution::is_executor<T>::value>::type* = 0)
{
return t.context();
}

io_object_impl(const io_object_impl&);
io_object_impl& operator=(const io_object_impl&);

service_type* service_;

implementation_type implementation_;

executor_type executor_;
};

} 
} 
} 

#include <boost/asio/detail/pop_options.hpp>

#endif 