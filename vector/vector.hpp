#ifndef __VECTOR_H__
# define __VECTOR_H__

# include <iostream>

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		typedef T								value_type;
		typedef Alloc							allocator_type;
		typedef allocator_type::reference		reference;
		typedef allocator_type::const_reference	const_reference;
		typedef allocator_type::pointer			pointer;
		typedef allocator_type::const_pointer	const_pointer;

		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
copy (4)
vector (const vector& x);
	private:
		value_type*	val;
		allocator_type	alloc;

};

}

#endif