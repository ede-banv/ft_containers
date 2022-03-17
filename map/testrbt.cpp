#include <iostream>

template < class T >
struct s_node {
	T		value;
	char	color;
	s_node*	parent;
	s_node*	left;
	s_node*	right;
};

template < class T >
s_node<T>*	searchNode(s_node<T>* root, T key)
{
	s_node<T>*	res = NULL;

	while (root)
	{
		if (node->data == key)
			res = node;
		else if (node->data > key)
			node = node->left;
		else
			node = node->right;
	}
	return (res);
}

template < class T >
s_node<T>*	createNewNode(T value)
{
	s_node<T>* newN = new s_node<T>; //alloc unsure

	newN->value = value;
	newN->color = 'r';
	newN->left = NULL;
	newN->right = NULL;
	newN->parent = NULL;
	return (newN);
}

template < class T >
void	leftRotate(s_node<T>* root, s_node<T>* x)
{
	s_node<T>*	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (!x->parent)
		root- = y;
	else if (x == x->parent->left)
		x->parent->right = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
	//to test and verify
}

template < class T >
void	rightRotate(s_node<T>* root, s_node<T>* x)
{
	s_node<T>*	y;
	y->left = x->right;
	if (x->right)
		x->right->parent = y;
	if (!y->parent)
		root = x;
	else if (y == y->parent->right)
		y->parent->right = x
	else
		y->parent->left = y;
	x->right = y;
	y->parent = x;
}

template < class T >
void	insertNode(s_node<T>*	root, T value)
{
	s_node<T>*	node = createNewNode(value);
	if (!root)
	{
		root = node;
		root->color = 'b';
		root->parent = NULL;
	}
	else
	{
		while (root)
		{
			if (node->value > root->value)
				root = root->right;
			else if (node->value < root->value)
				root = root->left;
			else
				return;
			root->parent = node->parent;
		}
		if (node->parent->value > node->value)
			node->parent->left = node;
		else
			node->parent->right = node;
		insertFix(root, node);
	}
}

template < class T >
void	insertFix(s_node<T>* root, s_node<T>* node)
{
	s_node<T>*	y = NULL;

	while (node->parent->color == 'r') //while parent is red
	{
		if (node->parent == node->parent->parent->left) //if parent is left of gp
		{
			y = node->parent->parent->right; //uncle
			if (y->color == 'r') //if uncle is red
			{
				node->parent->color = 'b'; //both parent
				y->color = 'b'; //and uncle become black
				node->parent->parent->color = 'r'; //and gp becomes black
				node = y->parent; //assign gp to newnode (???)
			}
			else
			{
				if (node == node->parent->right) //if node to right of parent
				{
					node = node->parent; //assign parent to newnode (???)
					leftRotate(root, node); //leftrot node
				}
				node->parent->color = 'b'; //node parent black
				y->parent->color = 'r'; //node gp red
				rightRotate(root, y->parent)//rightrot gp
			}
		}
		else if (node->parent == node->parent->parent->right)
		{
			y = node->parent->parent->left;
			if (y->color == 'r') //if uncle is red
			{
				node->parent->color = 'b'; //both parent
				y->color = 'b'; //and uncle become black
				node->parent->parent->color = 'r'; //and gp becomes black
				node = y->parent; //assign gp to newnode (???)
			}
			else
			{
				if (node == node->parent->right) //if node to right of parent
				{
					node = node->parent; //assign parent to newnode (???)
					leftRotate(root, node); //leftrot node
				}
				node->parent->color = 'b'; //node parent black
				y->parent->color = 'r'; //node gp red
				rightRotate(root, y->parent)//rightrot gp
			}
		}
		if (node == root)
			break;
	}
	root->color = 'b';
}

template < class T >
void	rbTransplant(s_node<T>* root, s_node<T>* u, s_node<T>* v)
{
	if (!u->parent)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

template < class T >
void	deleteNode(s_node<T>* root, T key)
{
	s_node<T>* x, y;
	s_node<T>* tmp = searchNode(root, key);
	y = tmp;
	char ogcolor = y->color;

	if (!tmp->left)
	{
		x = tmp->right;
		rbTransplant(root, tmp, tmp->right);
	}
	else if (!tmp->right)
	{
		x = tmp->left;
		rbTransplant(root, tmp, tmp->left);
	}
	else
	{
		//y = tree minimum (tmp->right)
		ogcolor = y->color;
		x = y->right;
		if (y->parent == tmp)
			x->parent = y;
		else
		{
			rbTransplant(root, y, y->right);
			y->right = tmp->right;
			y->right->parent = y;
		}
		rbTransplant(root, tmp, y);
		y->left = tmp->left;
		y->left->parent = y;
		y->color = tmp->color;
	}
	if (ogcolor == 'b')
		//deleteFix
}