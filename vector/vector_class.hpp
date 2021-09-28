#ifndef __VECTOR_H__
# define __VECTOR_H__

# include <iostream>
# include <memory>
# include <iterator>
# include <algorithm>
# include <cstddef>
# include "../iterator_traits.hpp"
# include "../utils.hpp"
# include "../randomiterator.hpp"
# include "../reverseiterator.hpp"

namespace ft {


template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		typedef T											value_type;
		typedef typename std::allocator<T>					allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ptrdiff_t									difference_type;
		typedef size_t										size_type;

		class iterator: public RandIt<value_type> {
			public:
				iterator(): RandIt<value_type>() {}
				iterator(pointer ptr): RandIt<value_type>(ptr) {}
				iterator(const iterator& copy) {	*this = copy;	}


				iterator&	operator=(const iterator& rhs) {
					if (this == &rhs)
						return *this;
					this->_ptr = rhs._ptr;
					return (*this);
				}
				iterator&	operator++() {
					this->_ptr++;
					return (*this);
				}
				iterator	operator++(int) {
					iterator tmp(*this);
					++(*this);
					return (tmp);
				}
				iterator&	operator--() {
					this->_ptr--;
					return (*this);
				}
				iterator	operator--(int) {
					iterator tmp(*this);
					--(*this);
					return (tmp);
				}
				difference_type	operator-(const RandIt<value_type>& rhs) const {	return (RandIt<value_type>::operator-(rhs));	}
				iterator		operator-(const difference_type& rhs) const {	return (iterator(this->_ptr - rhs));	}
				iterator		operator+(const difference_type& rhs) const { return (iterator(this->_ptr + rhs));	}
				friend iterator	operator+(const difference_type& lhs, const iterator& rhs) {	return(iterator(rhs._ptr + lhs));	}

				reference		operator[](size_type n) {	return (this->_ptr[n]);	}
				const_reference operator[](size_type n) const {	return (this->_ptr[n]);	}
				difference_type	operator[](const RandIt<value_type>& rhs) const {	return (*this - rhs);	}
			private:
				iterator(const RandIt<value_type>& copy): RandIt<value_type>(copy) {}
		};

		class const_iterator: public RandIt<value_type> {
			public:
				typedef const T&			reference;
				typedef const T&			const_reference;
				typedef	const value_type*	pointer;

				const_iterator(): RandIt<value_type>() {}
				const_iterator(value_type* ptr): RandIt<value_type>(ptr) {}
				const_iterator(const RandIt<value_type>& copy): RandIt<value_type>(copy) {}

				friend iterator	operator+(difference_type lhs, const const_iterator &rhs)
				{	return rhs._ptr + lhs;	}
				reference		operator*() const {	return *this->_ptr;	}
				const_reference operator[](size_type n) const {	return RandIt<value_type>::_ptr[n];	}
				difference_type	operator[](const RandIt<value_type>& rhs) const {	return (*this - rhs);	}
		};

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// ** MEMBER FUNCTIONS **
		explicit vector (const allocator_type& alloc = allocator_type()):
		_alloc(alloc), _size(0), _capacity(0)
		{	_max_size = _alloc.max_size();	}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_max_size = _alloc.max_size();
			_data = _alloc.allocate(n);
			_size = _capacity = n;
			for(size_type i = 0; i < n; ++i)
				_alloc.construct(&_data[i], val);
		}

		template <class InputIterator>
        vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(0), _capacity(0), _max_size(_alloc.max_size()) {
			insert(begin(),first, last);
		}

		vector (const vector& copy): _alloc(copy.get_allocator()), _size(0), _capacity(0), _max_size(_alloc.max_size())
		{	*this = copy;	}

		virtual ~vector() {
			clear();
			if (_capacity)
				_alloc.deallocate(_data, _capacity);
		}

		vector& operator=(const vector& rhs);

		// ** CAPACITY **
		size_type	size() const;
		size_type	max_size() const;
		void		resize(size_type n, value_type val = value_type());
		size_type	capacity() const;
		bool		empty() const;
		void		reserve(size_type n);

		// ** ELEMENT ACCESS **
		reference		operator[](size_type n)
		{	return (_data[n]);	}
		const_reference	operator[](size_type n) const
		{	return (_data[n]);	}
		reference		at(size_type n) {
			if (n < 0 || n >= _size)
				throw std::out_of_range("Element out of range.");
			return (_data[n]);
		}
		const_reference	at(size_type n) const {
			if (n < 0 || n >= _size)
				throw std::out_of_range("Element out of range.");
			return (_data[n]);
		}
		reference		front()
		{	return (_data[0]);	}
		const_reference	front() const
		{	return (_data[0]);	}
		reference		back()
		{	return (_data[_size -1]);	}
		const_reference	back() const
		{	return (_data[_size -1]);	}

		// ** MODIFIERS **
		template <class InputIterator>
		void		assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last);
		void		assign(size_type n, const value_type& val);
		void		push_back(const value_type& val);
		void		pop_back();
		iterator	insert(iterator position, const value_type& val);
		void		insert(iterator position, size_type $n, const value_type& val);
		template <class InputIterator>
		void		insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last);
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
		void		swap(vector& x);
		void		clear();

		// ** ITERATORS **
		iterator				begin() {	return (iterator(_data));	}
		const_iterator			begin() const {	return (const_iterator(_data));	}
		iterator				end() {	return (iterator(_data + _size));	}
		const_iterator			end() const {	return (const_iterator(_data + _size));	}
		reverse_iterator		rbegin() {	return(reverse_iterator(_data + _size - 1));	}
		const_reverse_iterator	rbegin() const {	return(const_reverse_iterator(_data + _size - 1));	}
		reverse_iterator		rend() {	return(reverse_iterator(_data - 1));	}
		const_reverse_iterator	rend() const {	return(const_reverse_iterator(_data - 1));	}

		// ** ALLOCATOR **
		allocator_type get_allocator() const { return(_alloc);	}
	private:
		value_type*			_data;
		allocator_type		_alloc;
		size_type			_size;
		size_type			_capacity;
		size_type			_max_size;

		template <class InputIterator>
		size_t	_ite_diff(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
			size_t	i = 0;
			while (first != last)
			{
				first++;
				i++;
			}
			return(i);
		}

		void _stagger_vector(iterator position, size_type len, size_type diff) {
			for (difference_type i = 1; this->_size - i >= len + diff; i++)
				*(position + this->_size - diff - i) = *(position + this->_size - diff - len - i);
		}

		template < class InputIterator >
		size_type	_count_difference(InputIterator first, InputIterator last) {
			size_type	count = 0;

			while (first != last)
			{
				first++;
				count++;
			}
			return (count);
		}

};

// ** RELATIONAL OPERATORS **
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); ++i)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{	return (lhs == rhs ? false : true);	}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return false;
	if (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return true;
	return false;
}

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{	return (lhs < rhs || lhs == rhs ? true : false);	}

template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{	return (lhs < rhs ? false : true);	}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{	return (lhs > rhs || lhs == rhs ? true : false);	}

// ** SWAP **
template <class T, class Alloc>
void	swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
{	x.swap(y);	}

}

#endif