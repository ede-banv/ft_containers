#ifndef __MAP_H__
# define __MAP_H__

#include <iostream>
#include <utility>
#include <memory>
# include "rbt_class.hpp"
# include "../iterator_traits.hpp"
# include "../utils.hpp"

# ifndef __APPLE__
#  define __APPLE__ 0
# endif

namespace ft {

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class map {

	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef std::pair< const key_type, mapped_type >		value_type;
		typedef	Compare											key_compare;
		typedef typename std::allocator< std::pair<constKey,T>	allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef std::ptrdiff_t									difference_type;
		typedef size_t											size_type;

		typedef typename tree_type::iterator					iterator;
		typedef typename tree_type::const_iterator				const_iterator;
		typedef ft::reverse_iterator< iterator >				reverse_iterator;
		typedef ft::reverse_iterator< const_iterator >			const_reverse_iterator;


		class value_compare: public std::binary_function < value_type, value_type, bool >
		{
			public:
				bool	operator()(value_type const &lhs, value_type const &rhs) const
				{	return (comp(lhs.first, rhs.first));	}

			protected:
				key_compare comp;
				value_compare(key_compare c): comp(c) {}

			private:
				friend class map;
		};

		// ** MEMBER FUNCTIONS **
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
		_Treeroot(NULL), _alloc(alloc), _key_comp(comp), _size(0), _max_size(alloc.max_size()) {}

		template <class InputIterator>
		map(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
		_Treeroot(NULL), _alloc(alloc), _key_comp(comp), _size(0), _max_size(alloc.max_size())
		{	insert(first, last);	}

		map(const map& copy): _alloc(get_allocator()), _key_comp(comp), _size(size()), _max_size(max_size())
		{
			if (empty())
			{
				//put all binary tree
			}
			else
			{
				//clear
				//put all binary tree
			}
		}

		map&	operator=(const map& x);

		// ** CAPACITY **
		bool		empty() const {	if (!_root) return (true); else return (false);	}
		size_type	size() const {	return (_size);	}
		size_type	max_size() const {	return (_max_size);	}

		// ** ELEMENT ACCESS **
		mapped_type&	operator[](const key_type& k);

		// ** MODIFIERS **
		pair<iterator,bool>	insert(const value_type& val)
		{
			if (!_Treeroot->insertNode(val))
			{
				return
			}
		}
		iterator			insert(iterator position, const value_type& val)
		{

		}
		template <class InputIterator>
		void				insert(InputIterator first, InputIterator last);
		void				erase(iterator position);
		size_type			erase(const key_type& k)
		{
			_Treeroot->deleteNode(k);
		}
		void				erase(iterator first, iterator last);
		void				swap(map& x);
		void				clear();

		// ** ITERATORS **

		iterator				begin() {	return (_Treeroot->begin());	} //smallest: far left
		const_iterator			begin() const {	return (_Treeroot->begin());	} //idem
		iterator				end() {	return (_Treeroot->end());	} //largest: far right
		const_iterator			end() const {	return (_Treeroot->end());	} //idem
		reverse_iterator		rbegin() {	return (_Treeroot->rbegin());	} //largest
		const_reverse_iterator	rbegin() const {	return (_Treeroot->rbegin());	} //idem
		reverse_iterator		rend() {	return (_Treeroot->rend());	} //smallest
		const_reverse_iterator	rend() const {	return (_Treeroot->rend());	} //idem

		// ** OBSRVERS **
		key_compare		key_comp() const {	return (_key_comp);	}
		value_compare	value_comp() const {	return (_value_comp);	}

		// ** OPERATIONS **
		iterator		find(const key_type& k);
		const_iterator	find(const key_type& k) const;
		size_type		count(const key_type& k) const;
		iterator		lower_bound(const key_type& k);
		const_iterator	lower_bound(const key_type& k) const;
		iterator		upper_bound(const key_type& k);
		const_iterator	upper_bound(const key_type& k) const;
		iterator		upper_bound(const key_type& k);
		const_iterator	upper_bound(const key_type& k) const;

		// ** ALLOCATOR **
		allocator_type	get_allocator() const {	return (_alloc);	}

	private:
		typedef	rb_tree<Key, T, Compare, Alloc>	tree_type;

		tree_type*							_Treeroot
		allocator_type						_allocp;
		std::allocator<s_node<value_type>	_allocn;
		key_compare							_key_comp;
		size_type							_size;
		size_type							_max_size;
};

}

#endif
