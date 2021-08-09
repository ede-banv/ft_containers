#ifndef __ITERATOR_TRAITS__
# define __ITERATOR_TRAITS__

#include <iterator>

/* iterators per container
vector: random acess
map: nodorectional
stack: none

It				Properties
bidirectional	= *it ,  *it = , ++ , -- , == , !=
random_access	-> , [] , = *it ,  *it = , ++ , -- , += , -= , + , - , == , != , < , > , <= , >=
*/

namespace ft
{

template <class Iterator> class iterator_traits;
template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;

template <class T>
class iterator_traits {
	public:
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef	T*							pointer;
		typedef	T&							reference;
		typedef std::random_access_iterator_tag	iterator_category;
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