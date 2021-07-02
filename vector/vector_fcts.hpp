#ifndef __VECTOR_F_H__
# define __VECTOR_F_H__

# include "vector.hpp"

namespace ft {


template < class T, class Alloc>
void		vector<T, Alloc>::resize(size_type n, value_type val)
{
	if (n < this->_size)
	{
		while (n < this->_size)
			this->_alloc.destroy(&this->_data[n++]);
		this->_size = n;
	}
	else if (n > this->_size)
	{
		size_type	dcap = this->_capacity * 2;
		this->reserve(this->_size <= dcap ? dcap : n);
		for(int i = this->_size; i < n; ++i)
			this->_alloc.construct(&this->_data[i], val);
		this->_size = n;
	}
}

template < class T, class Alloc>
void		vector<T, Alloc>::reserve(size_type n)
{
	if (n <= this->_capacity)
		return;
	value_type*	tmp = this->_alloc.allocate(n);
	for(int i = 0; i < this->_size; ++i)
	{
		this->_alloc.contruct(&tmp[i], this->_data[i]);
		this->_alloc.destroy(&this->_data[i]);
	}
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_data = tmp;
	this->_capacity = n;
}

template < class T, class Alloc>
void		vector<T, Alloc>::push_back(const value_type& val)
{
	this->resize(this->_size + 1, val);
}

template < class T, class Alloc>
void		vector<T, Alloc>::pop_back()
{
	this->resize(this->_size, NULL); //what to set val as? consider as value_type;
}

}
#endif