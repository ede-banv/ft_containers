#ifndef __MAP_H__
# define __MAP_H__

#include <iostream>
#include <utility>
#include <memory>
# include "rbt_class.hpp"
# include "bidirectionaliterators.hpp"
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
		typedef std::pair<const key_type, mapped_type>			value_type;
		typedef	Compare											key_compare;
		typedef typename std::allocator<std::pair<const Key,T>	allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef std::ptrdiff_t									difference_type;
		typedef size_t											size_type;

		class iterator: public BiDir<value_type> {
			public:

		}

		class const_iterator: public BiDir<value_type> {
			public:
//a vuar
		}

		// ** MEMBER FUNCTIONS **
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
		, _root(NULL), _alloc(alloc), _key_comp(comp), _size(0), _max_size(alloc.max_size()) {}

		template <class InputIterator>
		//map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		map(const map& copy): _alloc(get_allocator()), _key_comp(comp), _size(size()), _max_size(max_size())
		{
			//*this = x
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
			_Treeroot->insertNode(val);
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
		void				swap (map& x);
		void				clear();

		// ** ITERATORS **

		iterator				begin() {	;	} //smallest: far left
		const_iterator			begin() const {	;	} //idem
		iterator				end() {	;	} //largest: far right
		const_iterator			end() const {	;	} //idem
		reverse_iterator		rbegin() {	;	} //largest
		const_reverse_iterator	rbegin() const {	;	} //idem
		reverse_iterator		rend() {	;	} //smallest
		const_reverse_iterator	rend() const {	;	} //idem

		// ** OBSRVERS **
		key_compare		key_comp() const {	return(_key_comp);	}
		value_compare	value_comp() const {	;	}

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
	protected:
		rb_tree<Key, T, Compare, Alloc>*	_Treeroot
		allocator_type						_allocp;
		std::allocator<s_node<value_type>	_allocn;
		key_compare							_key_comp;
		size_type							_size;
		size_type							_max_size;
};

}

#endif
