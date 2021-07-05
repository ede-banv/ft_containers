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
		typedef T									value_type;
		typedef std::allocator<T>::rebind::other	allocator_type;
		typedef allocator_type::reference			reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer		const_pointer;
		typedef ptrdiff_t							difference_type;
		typedef size_t								size_type;

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
				typedef const T							const_value_type;
				typedef const T*						const_pointer;
				typedef const T&						const_reference;

				const_iterator(): _ptr(NULL) {}
				const_iterator(const iterator<T>& copy): _ptr = copy.operator->() {}
				const_iterator(const_pointer ptr): _ptr(ptr) {}
				const_iterator(const const_iterator& copy){	*this = copy;	}
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
				const_reference	operator*() const {	return *_ptr;	}
				const_pointer	operator->() const {	return _ptr;	}
				bool			operator==(const const_iterator& rhs) const {	return (_ptr == rhs._ptr);	}
				bool			operator!=(const const_iterator& rhs) const {	return (_ptr != rhs._ptr);	}
				bool			operator>(const const_iterator& rhs) const {	return (_ptr > rhs._ptr);	}
				bool			operator>=(const const_iterator& rhs) const {	return (_ptr >= rhs._ptr);	}
				bool			operator<(const const_iterator& rhs) const {	return (_ptr < rhs._ptr);	}
				bool			operator<=(const const_iterator& rhs) const {	return (_ptr <= rhs._ptr);	}
			private:
				const_pointer	_ptr;
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
			for(int i = 0; i < n; ++i)
				_alloc.contruct(&_data[i], val);
		}
		//Constructs a container with as many elements as the range [first,last), with each element constructed
		//from its corresponding element in that range, in the same order.
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		//Constructs a container with a copy of each of the elements in x, in the same order.
		vector (const vector& copy) {
			vector()
			this = *copy;
		}

		virtual ~vector() {
			this->clear();
			_alloc.deallocate(_data);
		}

		//Copies all the elements from x into the container. The container preserves its current allocator,
		//which is used to allocate storage in case of reallocation.
		vector& operator= (const vector& rhs);


		// ** CAPACITY **
		size_type	size() const;
		size_type	max_size() const;
		void		resize(size_type n, value_type val = value_type());
		size_type	capacity() const;
		bool		empty() const;
		void		reserve(size_type n);

		// ** ELEMENT ACCESS **
		//Returns a reference to the element at position n in the vector container.
		reference		operator[] (size_type n);
		const_reference	operator[] (size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;

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

		// ** RELATIONAL OPERATORS **
		//compare lexicographiquement les valeurs dans le vector
		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

		// ** ITERATORS **
		iterator				begin() {	return iterator(&_data[0]);	}
		const_iterator			begin() const {	return const_iterator(&_data[0]);	}
		iterator				end() {	return iterator(&_data[this->size]);	}
		const_iterator			end() const {	return const_iterator(&_data[this->size]);	}
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
	private:
		value_type*				_data;
		allocator_type			_alloc;
		size_type				_size;
		size_type				_capacity;
		const static size_type	_max_size;

};

}

#endif