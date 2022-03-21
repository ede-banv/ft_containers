#ifndef __MAP_F_H__
# define __MAP_F_H__

# include "map_rbt_utils.hpp"

namespace ft {

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	;
}

// ** ELEMENT ACCESS **
template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::mapped_type&	map<Key, T, Compare, Alloc>::operator[] (const key_type& k)
{
	;
}

// ** MODIFIERS **
template < class Key, class T, class Compare, class Alloc >
std::pair<typename map<Key, T, Compare, Alloc>::iterator,bool> map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
template < class InputIterator >
void map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::erase (iterator position)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::erase(const key_type& k)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::swap(map& x)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
void map<Key, T, Compare, Alloc>::clear()
{
	;
}

// ** OBSRVERS **
//	template < class Key, class T, class Compare, class Alloc >
//	map<Key, T, Compare, Alloc>::key_compare map<Key, T, Compare, Alloc>::key_comp() const
//	{	return(_key_comp);	}

//	template < class Key, class T, class Compare, class Alloc >
//	typename map<Key, T, Compare, Alloc>::value_compare map<Key, T, Compare, Alloc>::value_comp() const
//	{	;	}

// ** OPERATIONS **
template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find(const key_type& k)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find(const key_type& k) const
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	;
}

template < class Key, class T, class Compare, class Alloc >
typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	;
}

}

#endif