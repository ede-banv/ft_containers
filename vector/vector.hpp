#ifndef __VECTOR_F_H__
# define __VECTOR_F_H__

# include "vector_class.hpp"

namespace ft {

template < class T, class Alloc>
vector<T, Alloc>&	vector<T, Alloc>::operator=(const vector& rhs)
{
	if (this == &rhs)
		return *this;
	this->clear();
	//this->assign(rhs.begin(), rhs.end());
	this->insert(this->begin(), rhs.begin(), rhs.end());
	printf("\nCOPY size: %lu, capacity: %lu, max_size: %lu\n", rhs.size(), rhs.capacity(), rhs.max_size());
	printf("\nNEW size: %lu, capacity: %lu, max_size: %lu\n", this->_size, this->_capacity, this->_max_size);
	return (*this);
}

// **************
// ** CAPACITY ** : Done
// **************

template < class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::size() const
{	return (this->_size);	}

template < class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size() const
{	return (this->_max_size);	}

template < class T, class Alloc>
void		vector<T, Alloc>::resize(size_type n, value_type val) {
	if (n < this->_size)
	{
		size_type tmp = n;
		while (n < this->_size)
			this->_alloc.destroy(&this->_data[n++]);
		this->_size = tmp;
	}
	else if (n > this->_size)
	{
		size_type	dcap = this->_capacity * 2;
		this->reserve(this->_size <= dcap && n > this->_capacity ? dcap : n);
		for(size_type i = this->_size; i < n; i++)
			this->_alloc.construct(&this->_data[i], val);
		this->_size = n;
	}
}

template < class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const
{	return (this->_capacity);	}

template < class T, class Alloc>
bool		vector<T, Alloc>::empty() const
{	return (this->_size == 0 ? true : false);	}

template < class T, class Alloc>
void		vector<T, Alloc>::reserve(size_type n) {
	if (n <= this->_capacity)
		return;
	value_type*	tmp = this->_alloc.allocate(n);
	for(size_type i = 0; i < this->_size; i++)
	{
		this->_alloc.construct(&tmp[i], this->_data[i]);
		this->pop_back();
	}
	this->_alloc.deallocate(this->_data, this->_capacity);
	this->_data = tmp;
	this->_capacity = n;
}

// ***************
// ** MODIFIERS ** : assign, swap
// ***************

template < class T, class Alloc>
template <class InputIterator>
void		vector<T, Alloc>::assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
	this->reserve(last - first);
	iterator	it = this->begin();
	while (first != last)
	{
		*it = *first;
		first++;
		it++;
	}

}

template < class T, class Alloc>
void		vector<T, Alloc>::assign(size_type n, const value_type& val) {
	this->reserve(n);
	for (size_type i = 0; i < n; i++)
		this->_data[i] = val;
}

template < class T, class Alloc>
void		vector<T, Alloc>::push_back(const value_type& val)
{	this->resize(this->_size + 1, val);	}

template < class T, class Alloc>
void		vector<T, Alloc>::pop_back()
{	this->_alloc.destroy(&this->_data[this->_size - 1]);	}

template < class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type& val) {
	this->reserve(this->_size + 1);
	*(position + 1) = *position;
	*position = val;
	return position;
} //grosse merde

template < class T, class Alloc>
void		vector<T, Alloc>::insert(iterator position, size_type	n, const value_type& val) {
	while (n > 0)
	{
		this->insert(position, val);
		--n;
	}
}

template < class T, class Alloc>
template < class InputIterator>
void		vector<T, Alloc>::insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
	size_type diff = position - this->begin();
	this->resize(this->size() + (last - first));
	position = this->begin() + diff;
	iterator ite = this->end();
	while (first != last && position + 1 != ite)
	{
		*(position + 1) = *position;
		*position = *first;
		++first;
		++position;
	}
}

template < class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator position) {
	this->erase(position, position + 1);
	return (position);
}

template < class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last) {
	size_type n = 0;
	while (first + n != last)
		n++;
	for (size_type i = 0; (last + i) != this->end(); i++)
		*(first + i) = *(last + i);
	this->resize(this->_size - n);
	return (first);
}

template < class T, class Alloc>
void		vector<T, Alloc>::swap(vector& x)
{
	(void)x;
}

template < class T, class Alloc>
void		vector<T, Alloc>::clear() {
	if (!this->empty())
		this->resize(0);
}

}
#endif