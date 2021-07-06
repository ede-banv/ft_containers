#ifndef __VECTOR_H__
# define __VECTOR_H__

# include <iostream>
# include <memory>
#include <iterator>
#include <cstddef>

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

		class iterator
		{
			public:
				typedef std::random_access_iterator_tag	iterator_category;
				typedef std::ptrdiff_t					difference_type;
				typedef T								value_type;
				typedef T*								pointer;
				typedef T&								reference;

				iterator(): _ptr(NULL) {}
				iterator(pointer ptr): _ptr(ptr) {}
				iterator(const iterator& copy){	*this = copy;	}
				~iterator();

				iterator&	operator++() {
					_ptr++;
					return (*this);
				}
				iterator&	operator++(int) {
					iterator tmp = *this;
					++(*this);
					return (tmp);
				}
				iterator&	operator--() {
					_ptr--;
					return (*this);
				}
				iterator&	operator--(int) {
					iterator tmp = *this;
					--(*this);
					return tmp;
				}
				iterator&	operator=(const iterator& rhs) {
					_ptr = rhs._ptr;
					return (*this);
				}
				iterator&	operator-(const iterator& rhs) {	return (_ptr - rhs._ptr);	}
				iterator&	operator+(const int& rhs) {
					for (int i = 0; i < rhs; ++i)
						++(*this);
					return (*this);
				}
				iterator&	operator-(const int& rhs) {
					for (int i = 0; i < rhs; ++i)
						--(*this);
					return (*this);
				}
				reference	operator*() const {	return *_ptr;	}
				pointer		operator->() const {	return _ptr;	}
				bool		operator==(const iterator& rhs) const {	return (_ptr == rhs._ptr);	}
				bool		operator!=(const iterator& rhs) const {	return (_ptr != rhs._ptr);	}
				bool		operator>(const iterator& rhs) const {	return (_ptr > rhs._ptr);	}
				bool		operator>=(const iterator& rhs) const {	return (_ptr >= rhs._ptr);	}
				bool		operator<(const iterator& rhs) const {	return (_ptr < rhs._ptr);	}
				bool		operator<=(const iterator& rhs) const {	return (_ptr <= rhs._ptr);	}
			private:
				pointer	_ptr;
		};

		class const_iterator
		{
			public:
				typedef std::random_access_iterator_tag	iterator_category;
				typedef std::ptrdiff_t					difference_type;
				typedef const T							value_type;
				typedef const T*						pointer;
				typedef const T&						reference;

				const_iterator(): _ptr(NULL) {}
				const_iterator(const iterator& copy): _ptr(copy.operator->()) {}
				const_iterator(pointer ptr): _ptr(ptr) {}
				const_iterator(const_iterator& copy){	*this = copy;	}
				~const_iterator();

				const_iterator&	operator++() {
					_ptr++;
					return (*this);
				}
				const_iterator&	operator++(int) {
					const_iterator tmp = *this;
					++(*this);
					return (tmp);
				}
				const_iterator&	operator--() {
					_ptr--;
					return (*this);
				}
				const_iterator&	operator--(int) {
					const_iterator tmp = *this;
					--(*this);
					return tmp;
				}
				const_iterator&	operator=(const const_iterator& rhs) {
					_ptr = rhs._ptr;
					return (*this);
				}
				const_iterator&	operator-(const const_iterator& rhs) {	return (_ptr - rhs._ptr);	}
				const_iterator&	operator+(const int& rhs) {
					for (int i = 0; i < rhs; ++i)
						++(*this);
					return (*this);
				}
				const_iterator&	operator-(const int& rhs) {
					for (int i = 0; i < rhs; ++i)
						--(*this);
					return (*this);
				}
				reference	operator*() const {	return *_ptr;	}
				pointer	operator->() const {	return _ptr;	}
				bool			operator==(const const_iterator& rhs) const {	return (_ptr == rhs._ptr);	}
				bool			operator!=(const const_iterator& rhs) const {	return (_ptr != rhs._ptr);	}
				bool			operator>(const const_iterator& rhs) const {	return (_ptr > rhs._ptr);	}
				bool			operator>=(const const_iterator& rhs) const {	return (_ptr >= rhs._ptr);	}
				bool			operator<(const const_iterator& rhs) const {	return (_ptr < rhs._ptr);	}
				bool			operator<=(const const_iterator& rhs) const {	return (_ptr <= rhs._ptr);	}
			private:
				pointer	_ptr;
		};

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
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc) {
			insert(begin(), first, last);
		}

		vector& operator= (const vector& rhs);
		vector (const vector& copy) {	*this = copy;	}

		virtual ~vector() {
			this->clear();
			_alloc.deallocate(_data, this->_capacity);
		}



		// ** CAPACITY **
		size_type	size() const;
		size_type	max_size() const;
		void		resize(size_type n, value_type val = value_type());
		size_type	capacity() const;
		bool		empty() const;
		void		reserve(size_type n);

		// ** ELEMENT ACCESS **
		//Returns a reference to the element at position n in the vector container.
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
		void		assign(InputIterator first, InputIterator last);
		void		assign(size_type n, const value_type& val);
		void		push_back(const value_type& val);
		void		pop_back();
		iterator	insert(iterator position, const value_type& val);
		void		insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last);
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last); //opti
		void		swap(vector& x);
		void		clear();

		// ** ITERATORS **
		iterator				begin() {	return (iterator(&_data[0]));	}
		const_iterator			begin() const {	return (const_iterator(&_data[0]));	}
		iterator				end() {	return (iterator(&_data[this->size()]));	}
		const_iterator			end() const {	return (const_iterator(&_data[this->size()]));	}
		//reverse_iterator		rbegin();
		//const_reverse_iterator	rbegin() const;
		//reverse_iterator		rend();
		//const_reverse_iterator	rend() const;
	private:
		value_type*			_data;
		allocator_type		_alloc;
		size_type			_size;
		size_type			_capacity;
		static size_type	_max_size;

};

// ** RELATIONAL OPERATORS **
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	for (vector<T, Alloc>::size_type i = 0; i < lhs.size(); ++i)
		if (lhs[i] != rhs[i])
			return false;
	return true;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (lhs == rhs ? false : true);
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs.size() > rhs.size())
		return false;
	for (vector::size_type i = 0; i < lhs.size(); ++i)
		if (lhs[i] > rhs[i])
			return false;
	return true;
}

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (lhs < rhs || lhs == rhs ? true : false);
}

template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (lhs < rhs ? false : true);
}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return (lhs > rhs || lhs == rhs ? true : false);
}


}

#endif