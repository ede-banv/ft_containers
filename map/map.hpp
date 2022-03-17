#ifndef __MAP_F_H__
# define __MAP_F_H__

# include "map_class.hpp"

namespace ft {

template < class Key, class T, class Compare, class Alloc >
s_node<typename map<Key, T, Compare, Alloc>::value_type>*	map<Key, T, Compare, Alloc>::_newNode(value_type value)
{
	//allocate
	s_node<value_type>* newN = this->_allocn(1);
	if (newN)
		this->_allocp(newN->value, value);

	newN->value = value;
	newN->color = 'r';
	newN->left = NULL;
	newN->right = NULL;
	newN->parent = NULL;
	return (newN);
}

template < class Key, class T, class Compare, class Alloc >
void	map<Key, T, Compare, Alloc>::_searchKey(s_node<value_type>** root, value_type key)
{
	while (*root && (*root)->value != key)
	{
		if (key < (*root)->value)
			*root = (*root)->left;
		else
			*root = (*root)->left;
	}
}

template < class Key, class T, class Compare, class Alloc >
s_node<typename map<Key, T, Compare, Alloc>::value_type>*	map<Key, T, Compare, Alloc>::_findMaxKey(s_node<value_type>* node)
{
	while (node->right)
		node = node->right;
	return (node == this->_ghost ? this->_ghost->parent : node);
}

template < class Key, class T, class Compare, class Alloc >
bool	map<Key, T, Compare, Alloc>::_insertNode(s_node<value_type>* node, value_type value)
{ //insert ghost node cdt?
	if  (!this->_root)
	{
		this->_root = this->_newNode(value);
		this->_ghost = this->_newNode(NULL);
		this->_root->right = this->_ghost;
		this->_ghost->parent = this->_root;
		return (true);
	}
	else if (node == this->_ghost)
	{
		s_node<value_type>* tmp = this->_newNode(value);
		tmp->right = _ghost;
		tmp->parent = node->parent;
		return (true);
	}
	else if (!node)
	{
		node = this->_newNode(value);
		return (true);
	}
	else if (node->value == value)
		return (true);
	else if (value > node->value) // how can value_type be compared? COmpare?
	{
		this->_insertNode(&node->right, value);
		node->right->parent = node;
		return (true);
	}
	else
	{
		this->_insertNode(&node->left, value);
		node->left->parent = node;
		return (true);
	}
	return (false);
}

template < class Key, class T, class Compare, class Alloc >
void	map<Key, T, Compare, Alloc>::_deleteNode(s_node<value_type>* node, value_type value)
{
	if (!this->_root)
		return;
	s_node<value_type>* curr = node;
	this->_searchKey(&curr, value);
	if (!curr)
		return;
	else if (!curr->left && !curr->right)
	{
		if (curr != node)
		{
			if (curr->parent->left = curr)
				curr->parent->left = NULL;
			else
				curr->parent->right = NULL;
		}
		else
			node = NULL;
		//delete but not delete, deallocate
	}
	else if (curr->right && curr->left)
	{
		s_node<value_type>* pred = this->_findMaxKey(curr->left);
		value_type tmp = pred->value;
		this->_deleteNode(this->_root, pred->value);
		curr->value = tmp;
	}
	else
	{
		if (curr != node)
		{
			if (curr == curr->parent->left)
				curr->parent->left = curr->left ? curr->left : curr->right;
			else
				curr->parent->right = curr->left ? curr->left : curr->right;
		}
		else
			node = curr->left ? curr->left : curr->right;
		if (curr != this->_root)
			(curr->left ? curr->left : curr->right)->parent = curr->parent;
		delete curr;
	}


}

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