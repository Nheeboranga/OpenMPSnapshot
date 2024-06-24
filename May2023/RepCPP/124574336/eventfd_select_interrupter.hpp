
#ifndef BOOST_ASIO_DETAIL_EVENTFD_SELECT_INTERRUPTER_HPP
#define BOOST_ASIO_DETAIL_EVENTFD_SELECT_INTERRUPTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif 

#include <boost/asio/detail/config.hpp>

#if defined(BOOST_ASIO_HAS_EVENTFD)

#include <boost/asio/detail/push_options.hpp>

namespace boost {
namespace asio {
namespace detail {

class eventfd_select_interrupter
{
public:
BOOST_ASIO_DECL eventfd_select_interrupter();

BOOST_ASIO_DECL ~eventfd_select_interrupter();

BOOST_ASIO_DECL void recreate();

BOOST_ASIO_DECL void interrupt();

BOOST_ASIO_DECL bool reset();

int read_descriptor() const
{
return read_descriptor_;
}

private:
BOOST_ASIO_DECL void open_descriptors();

BOOST_ASIO_DECL void close_descriptors();

int read_descriptor_;

int write_descriptor_;
};

} 
} 
} 

#include <boost/asio/detail/pop_options.hpp>

#if defined(BOOST_ASIO_HEADER_ONLY)
# include <boost/asio/detail/impl/eventfd_select_interrupter.ipp>
#endif 

#endif 

#endif 