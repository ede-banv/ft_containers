#ifndef __VECTOR_F_H__
# define __VECTOR_F_H__

# include "vector.hpp"

namespace ft {

// ** CAPACITY **

template < class T, class Alloc>
vector<T, Alloc>::size_type	vector<T, Alloc>::size() const
{	return this->_size;	}

template < class T, class Alloc>
vector<T, Alloc>::size_type	vector<T, Alloc>::max_size() const
{	this->_max_size;	}

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
vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const
{	return this->_capacity;	}

template < class T, class Alloc>
bool		vector<T, Alloc>::empty() const
{	return (this->_size == 0 ? true : false);	}

template < class T, class Alloc>
void		vector<T, Alloc>::reserve(size_type n)
{
	if (n <= this->_capacity)
		return;
	value_type*	tmp = this->_alloc.allocate(n);
	for(int i = 0; i < this->_size; ++i)
	{
		this->_alloc.contruct(&tmp[i], this->_data[i]);
		this->pop_back();
	}
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_data = tmp;
	this->_capacity = n;
}

// ** MODIFIERS **

template < class T, class Alloc>
void		vector<T, Alloc>::push_back(const value_type& val)
{	this->resize(this->_size + 1, val);	}

template < class T, class Alloc>
void		vector<T, Alloc>::pop_back()
{	this->_alloc.destroy(&this->_data[this->_size - 1]);	}

}
#endif