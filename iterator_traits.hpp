#ifndef __ITERATOR_TRAITS__
# define __ITERATOR_TRAITS__

#include <iterator>

namespace ft
{

template <class T>
class iterator_traits {
	public:
		typedef T							value_type;
		typedef std::ptrdiff_t				difference_type;
		typedef	T*							pointer;
		typedef	T&							reference;
		typedef random_access_iterator_tag	iterator_category;
}

}

#endif