

#ifndef BOOST_BIMAP_RELATION_SUPPORT_DATA_EXTRACTOR_HPP
#define BOOST_BIMAP_RELATION_SUPPORT_DATA_EXTRACTOR_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/config.hpp>

#include <boost/bimap/relation/detail/metadata_access_builder.hpp>



#ifndef BOOST_BIMAP_DOXYGEN_WILL_NOT_PROCESS_THE_FOLLOWING_LINES

namespace boost {
namespace bimaps {
namespace relation {
namespace support {

template< class Tag, class Relation >
struct data_extractor_implementation;

template< class Relation >
struct data_extractor_implementation< member_at::left, Relation >
{
typedef Relation argument_type;
typedef BOOST_DEDUCED_TYPENAME Relation::left_value_type result_type;

BOOST_DEDUCED_TYPENAME Relation::left_value_type const &
operator()(Relation const & rel) const
{
return rel.left;
}

BOOST_DEDUCED_TYPENAME Relation::left_value_type &
operator()(Relation       & rel) const
{
return rel.left;
}
};

template< class Relation >
struct data_extractor_implementation< member_at::right, Relation >
{
typedef Relation argument_type;
typedef BOOST_DEDUCED_TYPENAME Relation::right_value_type result_type;

BOOST_DEDUCED_TYPENAME Relation::right_value_type const & 
operator()(Relation const & rel) const
{
return rel.right;
}

BOOST_DEDUCED_TYPENAME Relation::right_value_type & 
operator()(Relation       & rel) const
{
return rel.right;
}
};

template< class Tag, class Relation >
struct data_extractor
{
typedef data_extractor_implementation
<
BOOST_DEDUCED_TYPENAME member_with_tag<Tag,Relation>::type,
Relation

> type;
};

template< class Relation >
struct both_keys_extractor
{
typedef BOOST_DEDUCED_TYPENAME Relation::storage_base result_type;

const result_type & operator()(const Relation & rel) const
{
return rel;
}

result_type & operator()( Relation & rel) const
{
return rel;
}
};

} 
} 
} 
} 

#endif 

#endif 

