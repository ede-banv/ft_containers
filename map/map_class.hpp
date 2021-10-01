#ifndef __MAP_H__
# define __MAP_H__

#include <iostream>
#include <utility>
#include <memory>

namespace ft {

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >

class map {

	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef std::pair<const key_type, mapped_type>			value_type;
		typedef	Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef typename std::allocator_type::reference			reference;
		typedef typename std::allocator_type::const_reference	const_reference;
		typedef typename std::allocator_type::pointer			pointer;
		typedef typename std::allocator_type::const_pointer		const_pointer;
		typedef std::ptrdiff_t									difference_type;
		typedef size_t											size_type;


		// ** MEMBER FUNCTIONS **
		explicit map(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());
		map(const map& x);
		~map();

		map& operator= (const map& x);

		// ** CAPACITY **
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		// ** ELEMENT ACCESS **
		mapped_type& operator[] (const key_type& k);

		// ** MODIFIERS **
		pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);
		void erase (iterator position);
		size_type erase (const key_type& k);
		void erase (iterator first, iterator last);
		void swap (map& x);
		void clear();

		// ** ITERATORS **
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// ** OBSRVERS **
		key_compare key_comp() const;
		value_compare value_comp() const;

		// ** OPERATIONS **
		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;
		size_type count (const key_type& k) const;
		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;

		// ** ALLOCATOR **
		allocator_type get_allocator() const;
	protected:
		alllocator_type	_alloc;
		size_type		_size;
		size_type		_max_size;
};

}

#endif