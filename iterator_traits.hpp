#ifndef __ITERATOR_TRAITS__
# define __ITERATOR_TRAITS__

#include <iterator>

/* iterators per container
vector: random acess
map: bidirectional
stack: none

It				Properties
bidirectional	= *it ,  *it = , ++ , -- , == , !=
random_access	-> , [] , = *it ,  *it = , ++ , -- , += , -= , + , - , == , != , < , > , <= , >=
*/

namespace ft
{

template <class T> class iterator_traits<const T*>;

template<class Iterator>
struct iterator_traits
{
    typedef typename Iterator::difference_type		difference_type;
    typedef typename Iterator::value_type			value_type;
    typedef typename Iterator::pointer				pointer;
    typedef typename Iterator::reference			reference;
    typedef typename Iterator::iterator_category	iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef ptrdiff_t					difference_type;
    typedef T							value_type;
    typedef T*							pointer;
    typedef T&							reference;
    typedef random_access_iterator_tag	iterator_category;
};

// -------- ENABLE IF
template<bool, class T>
struct enable_if {};
template<class T>
struct enable_if<true, T> { typedef T type; };

// -------- IS INTEGRAL
template <class T>
struct is_integral {
	const static bool value = false;
};
template <>
struct is_integral<int> {
	const static bool value = true;
};

}

#endif