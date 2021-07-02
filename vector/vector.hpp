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
				using iterator_category = std::random_access_iterator_tag;
				using difference_type = std::ptrdiff_t;
				using value_type = T;
				using pointer = T*;
				using reference = T&;

				iterator();
				iterator(const iterator& copy);
				~iterator();

				iterator&	operator=(const iterator& rhs);
				iterator&	operator-(const iterator& rhs);
				iterator&	operator+(const int& rhs);
				iterator&	operator-(const int& rhs);
				bool		operator==(const iterator& rhs);
				bool		operator!=(const iterator& rhs);
				bool		operator>(const iterator& rhs);
				bool		operator>=(const iterator& rhs);
				bool		operator<(const iterator& rhs);
				bool		operator<=(const iterator& rhs);

			private:
				pointer	_ptr;
		};

		// ** MEMBER FUNCTIONS **

		//Constructs an empty container, with no elements.
		explicit vector (const allocator_type& alloc = allocator_type()):
		_alloc(alloc), _size(0), _capacity(0)
		{	_max_size = _alloc.max_size();	}
		//Constructs a container with n elements. Each element is a copy of val.
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
		vector (const vector& x);

		//This destroys all container elements, and deallocates all the storage capacity allocated
		//by the vector using its allocator.
		virtual ~vector();

		//Copies all the elements from x into the container. The container preserves its current allocator,
		//which is used to allocate storage in case of reallocation.
		vector& operator= (const vector& x);


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
		void		insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last);
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
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
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
	private:
		value_type*				_data;
		allocator_type			_alloc;
		size_type				_size;
		size_type				_capacity;
		const static size_type	_max_size; //avec alloc

};

}

#endif