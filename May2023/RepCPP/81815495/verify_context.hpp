
#ifndef ASIO_SSL_VERIFY_CONTEXT_HPP
#define ASIO_SSL_VERIFY_CONTEXT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include "asio/detail/config.hpp"

#include "asio/detail/noncopyable.hpp"
#include "asio/ssl/detail/openssl_types.hpp"

#include "asio/detail/push_options.hpp"

namespace asio {
namespace ssl {


class verify_context
: private noncopyable
{
public:
typedef X509_STORE_CTX* native_handle_type;

explicit verify_context(native_handle_type handle)
: handle_(handle)
{
}


native_handle_type native_handle()
{
return handle_;
}

private:
native_handle_type handle_;
};

} 
} 

#include "asio/detail/pop_options.hpp"

#endif 
