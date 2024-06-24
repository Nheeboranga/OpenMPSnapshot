#ifndef BOOST_RANGE_ADAPTOR_INDEXED_HPP_INCLUDED
#define BOOST_RANGE_ADAPTOR_INDEXED_HPP_INCLUDED

#include <boost/range/config.hpp>
#include <boost/range/adaptor/argument_fwd.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/range/traversal.hpp>
#include <boost/range/size.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_convertible.hpp>

#include <boost/iterator/iterator_traits.hpp>
#include <boost/iterator/iterator_facade.hpp>

#include <boost/tuple/tuple.hpp>

namespace boost
{
namespace adaptors
{

struct indexed
{
explicit indexed(std::ptrdiff_t x = 0)
: val(x)
{
}
std::ptrdiff_t val;
};

} 

namespace range
{

template<class T, class Indexable = std::ptrdiff_t>
class index_value
: public tuple<Indexable, T>
{
typedef tuple<Indexable, T> base_t;

template<int N>
struct iv_types
{
typedef typename tuples::element<N, base_t>::type n_type;

typedef typename tuples::access_traits<n_type>::non_const_type non_const_type;
typedef typename tuples::access_traits<n_type>::const_type const_type;
};

public:
typedef typename iv_types<0>::non_const_type index_type;
typedef typename iv_types<0>::const_type const_index_type;
typedef typename iv_types<1>::non_const_type value_type;
typedef typename iv_types<1>::const_type const_value_type;

index_value()
{
}

index_value(typename tuples::access_traits<Indexable>::parameter_type t0,
typename tuples::access_traits<T>::parameter_type t1)
: base_t(t0, t1)
{
}

index_type index()
{
return boost::tuples::get<0>(*this);
}

const_index_type index() const
{
return boost::tuples::get<0>(*this);
}

value_type value()
{
return boost::tuples::get<1>(*this);
}

const_value_type value() const
{
return boost::tuples::get<1>(*this);
}
};

} 

namespace range_detail
{

template<typename Iter>
struct indexed_iterator_value_type
{
typedef ::boost::range::index_value<
typename iterator_reference<Iter>::type,
typename iterator_difference<Iter>::type
> type;
};

template<typename Iter>
struct indexed_traversal
{
private:
typedef typename iterator_traversal<Iter>::type wrapped_traversal;

public:

typedef typename mpl::if_<
is_convertible<wrapped_traversal, random_access_traversal_tag>,
random_access_traversal_tag,
typename mpl::if_<
is_convertible<wrapped_traversal, bidirectional_traversal_tag>,
forward_traversal_tag,
wrapped_traversal
>::type
>::type type;
};

template<typename Iter>
class indexed_iterator
: public iterator_facade<
indexed_iterator<Iter>,
typename indexed_iterator_value_type<Iter>::type,
typename indexed_traversal<Iter>::type,
typename indexed_iterator_value_type<Iter>::type,
typename iterator_difference<Iter>::type
>
{
public:
typedef Iter wrapped;

private:
typedef iterator_facade<
indexed_iterator<wrapped>,
typename indexed_iterator_value_type<wrapped>::type,
typename indexed_traversal<wrapped>::type,
typename indexed_iterator_value_type<wrapped>::type,
typename iterator_difference<wrapped>::type
> base_t;

public:
typedef typename base_t::difference_type difference_type;
typedef typename base_t::reference reference;
typedef typename base_t::difference_type index_type;

indexed_iterator()
: m_it()
, m_index()
{
}

template<typename OtherWrapped>
indexed_iterator(
const indexed_iterator<OtherWrapped>& other,
typename enable_if<is_convertible<OtherWrapped, wrapped> >::type* = 0
)
: m_it(other.get())
, m_index(other.get_index())
{
}

explicit indexed_iterator(wrapped it, index_type index)
: m_it(it)
, m_index(index)
{
}

wrapped get() const
{
return m_it;
}

index_type get_index() const
{
return m_index;
}

private:
friend class boost::iterator_core_access;

reference dereference() const
{
return reference(m_index, *m_it);
}

bool equal(const indexed_iterator& other) const
{
return m_it == other.m_it;
}

void increment()
{
++m_index;
++m_it;
}

void decrement()
{
BOOST_ASSERT_MSG(m_index > 0, "indexed Iterator out of bounds");
--m_index;
--m_it;
}

void advance(index_type n)
{
m_index += n;
BOOST_ASSERT_MSG(m_index >= 0, "indexed Iterator out of bounds");
m_it += n;
}

difference_type distance_to(const indexed_iterator& other) const
{
return other.m_it - m_it;
}

wrapped m_it;
index_type m_index;
};

template<typename SinglePassRange>
struct indexed_range
: iterator_range<
indexed_iterator<
typename range_iterator<SinglePassRange>::type
>
>
{
typedef iterator_range<
indexed_iterator<
typename range_iterator<SinglePassRange>::type
>
> base_t;

BOOST_RANGE_CONCEPT_ASSERT((
boost::SinglePassRangeConcept<SinglePassRange>));
public:
typedef indexed_iterator<
typename range_iterator<SinglePassRange>::type
> iterator;

indexed_range(
typename base_t::difference_type i,
SinglePassRange& r,
single_pass_traversal_tag
)
: base_t(iterator(boost::begin(r), i),
iterator(boost::end(r), i))
{
}

indexed_range(
typename base_t::difference_type i,
SinglePassRange& r,
random_access_traversal_tag
)
: base_t(iterator(boost::begin(r), i),
iterator(boost::end(r), i + boost::size(r)))
{
}
};

} 

using range_detail::indexed_range;

namespace adaptors
{

template<class SinglePassRange>
inline indexed_range<SinglePassRange>
operator|(SinglePassRange& r, indexed e)
{
BOOST_RANGE_CONCEPT_ASSERT((
boost::SinglePassRangeConcept<SinglePassRange>
));
return indexed_range<SinglePassRange>(
e.val, r,
typename range_traversal<SinglePassRange>::type());
}

template<class SinglePassRange>
inline indexed_range<const SinglePassRange>
operator|(const SinglePassRange& r, indexed e)
{
BOOST_RANGE_CONCEPT_ASSERT((
boost::SinglePassRangeConcept<const SinglePassRange>
));
return indexed_range<const SinglePassRange>(
e.val, r,
typename range_traversal<const SinglePassRange>::type());
}

template<class SinglePassRange>
inline indexed_range<SinglePassRange>
index(
SinglePassRange& rng,
typename range_difference<SinglePassRange>::type index_value = 0)
{
BOOST_RANGE_CONCEPT_ASSERT((
boost::SinglePassRangeConcept<SinglePassRange>
));
return indexed_range<SinglePassRange>(
index_value, rng,
typename range_traversal<SinglePassRange>::type());
}

template<class SinglePassRange>
inline indexed_range<const SinglePassRange>
index(
const SinglePassRange& rng,
typename range_difference<const SinglePassRange>::type index_value = 0)
{
BOOST_RANGE_CONCEPT_ASSERT((
boost::SinglePassRangeConcept<SinglePassRange>
));
return indexed_range<const SinglePassRange>(
index_value, rng,
typename range_traversal<const SinglePassRange>::type());
}

} 
} 

#if !defined(BOOST_NO_CXX11_HDR_TUPLE)

namespace std {

#if defined(BOOST_CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmismatched-tags"
#endif

template<size_t N, class T, class Indexable>
struct tuple_element<N, boost::range::index_value<T, Indexable>>:
boost::tuples::element<N, boost::range::index_value<T, Indexable>> {};

template<class T, class Indexable>
struct tuple_size<boost::range::index_value<T, Indexable>>:
std::integral_constant<std::size_t, 2> {};

#if defined(BOOST_CLANG)
#pragma clang diagnostic pop
#endif

} 

#endif 

#endif 
