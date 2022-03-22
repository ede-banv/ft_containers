#ifndef __MAP_RBT__
# define __MAP_RBT__

# include "map_class.hpp"

namespace ft {

template < class Key, class T, class Compare, class Alloc >
s_node<typename map<Key, T, Compare, Alloc>::value_type>*	map<Key, T, Compare, Alloc>::_newNode(value_type value)
{
	//allocate
	if (!this->_Tnull)
	{
		this->_Tnull = this->_allocn(1);
		if (this->_Tnull)
			this->_allocp(this->_Tnull->value, NULL);
		this->_Tnull->color = 'b';
		this->_Tnull->left = this->_Tnull->right = this->_Tnull->parent = NULL;
	}
	s_node<value_type>* newN = this->_allocn(1);
	if (newN)
		this->_allocp(newN->value, value);

	newN->value = value;
	newN->color = 'r';
	newN->left = this->_Tnull; //tthis->_Tnull ctrl c ctrlv
	newN->right = this->_Tnull;
	newN->parent = this->_Tnull;
	return (newN);
}

template < class Key, class T, class Compare, class Alloc >
void	map<Key, T, Compare, Alloc>::_searchKey(s_node<value_type>** root, value_type key)
{
	while (*root != && (*root)->value != key)
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
void	map<Key, T, Compare, Alloc>::_insertNode(s_node<value_type>* node, value_type value)
{
	//only if not in tree
	s_node<value_type>*	node = this->_newNode(value);
	s_node<value_type>*	x = this->_root;
	s_node<value_type>*	tmp = NULL;

	//add cdt in case value already in tree???
	if  (!this->_root)
	{
		this->_root = node;
		this->_root->color = 'b';
		this->_root->parent = this->_Tnull;
		this->_root->left = this->_Tnull;
		this->_root->right = this->_Tnull;
		return ;
	}
	else
	{
		while (x != this->_Tnull)
		{
			tmp = x;
			if (node->value > x->value)//compare use
				x = x->right;
			else
				x = x->left
		}
		node->parent = tmp;
		if (node->value > tmp->value) //comparr use
			tmp->right = node;
		else
			tmp->left = node;
		if (node->parent->parent == NULL) //no need to fix if the node is the direct descendant of the root
			return;
		//insertfix()
	}
}

template < class Key, class T, class Compare, class Alloc >
void	map<Key, T, Compare, Alloc>::_insertFix(s_node<value_type>* node)
{
	s_node<value_type>*	y = NULL;
	while (node->parent->color == 'r')
	{
		if (node->parent == node->parent->parent->left)
		{
			y = node->parent->parent->right; //uncle
			if (y->color == 'r') //if uncle red
			{
				node->parent->color = 'b';
				y->color = 'b'; //parent and uncle become black
				node->parent->parent->color = 'r'; //gp becomes red
				node = y->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					this->_leftRotate(node);
				}
				node->parent->color = 'b';
				y->parent->color = 'r';
				this->_rightRotate(y->parent);
			}
		}
		else if (node->parent == node->parent->parent->right)
		{
			y = node->parent->parent->left;
			if (y->color == 'r')
			{
				node->parent->color = 'b';
				y->color = 'b';
				node->parent->parent->color = 'r';
				node = y->parent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					this->_rightRotate(node);
				}
				node->parent->color = 'b';
				y->parent->color = 'r';
				this->_leftRotate(y->parent);
			}
		}
		if (node == this->_root)
			break;
	}
	this->_root->color = 'b';
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

}

#endif