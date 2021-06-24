#ifndef __VECTOR_H__
# define __VECTOR_H__

# include <iostream>

template < class T, class Alloc = allocator<T> >
class vector
{
	public:
		typedef T	value_type;
		typedef Alloc	allocator_type;
		typedef allocator_type::reference	reference;
		typedef allocator_type::const_reference	const_reference;
		typedef allocator_type::pointer	pointer;
		typedef allocator_type::const_pointer	const_pointer;
};

#endif