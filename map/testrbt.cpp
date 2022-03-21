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
s_node<T>*	findMin(s_node<T>* node)
{
	while (node->left)
		node = node->left;
	return (node);
}

template < class T >
s_node<T>*	findMax(s_node<T>* node)
{
	while (node->right)
		node =  node->right;
	return (node);
}

template < class T >
s_node<T>*	searchNode(s_node<T>* root, T key)
{
	s_node<T>*	res = NULL;

	while (root)
	{
		if (root->value == key)
		{
			res = root;
			break ;
		}
		else if (root->value > key)
			root = root->left;
		else
			root = root->right;
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
	std::cout << "l\n";
	s_node<T>*	y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (!x->parent)
		root = y;
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
	std::cout << "r\n";
	s_node<T>*	y = NULL;
	y->left = x->right;
	if (x->right)
		x->right->parent = y;
	if (!y->parent)
		root = x;
	else if (y == y->parent->right)
		y->parent->right = x;
	else
		y->parent->left = y;
	x->right = y;
	y->parent = x;
}

template < class T >
void	insertFix(s_node<T>* root, s_node<T>** node)
{
	s_node<T>*	y = NULL;

	while ((*node)->parent->color == 'r') //while parent is red
	{
		std::cout << "while\n";
		if ((*node)->parent == (*node)->parent->parent->left) //if parent is left of gp
		{
			y = (*node)->parent->parent->right; //uncle
			if (y->color == 'r') //if uncle is red
			{
				(*node)->parent->color = 'b'; //both parent
				y->color = 'b'; //and uncle become black
				(*node)->parent->parent->color = 'r'; //and gp becomes black
				*node = y->parent; //assign gp to new*node (???)
			}
			else
			{
				if (*node == (*node)->parent->right) //if *node to right of parent
				{
					*node = (*node)->parent; //assign parent to new*node (???)
					leftRotate(root, *node); //leftrot *node
				}
				(*node)->parent->color = 'b'; //*node parent black
				y->parent->color = 'r'; //*node gp red
				rightRotate(root, y->parent);//rightrot gp
			}
		}
		else if ((*node)->parent == (*node)->parent->parent->right)
		{
			y = (*node)->parent->parent->left;
			if (y->color == 'r') //if uncle is red
			{
				(*node)->parent->color = 'b'; //both parent
				y->color = 'b'; //and uncle become black
				(*node)->parent->parent->color = 'r'; //and gp becomes black
				*node = y->parent; //assign gp to new*node (???)
			}
			else
			{
				if (*node == (*node)->parent->left) //if *node to left of parent
				{
					*node = (*node)->parent; //assign parent to new*node (???)
					rightRotate(root, *node); //rightrot *node
				}
				(*node)->parent->color = 'b'; //*node parent black
				y->parent->color = 'r'; //*node gp red
				leftRotate(root, y->parent);//leftrot gp
			}
		}
		if (*node == root)
			break;
	}
	root->color = 'b';
}

template < class T >
void	insertNode(s_node<T>** root, T value)
{
	s_node<T>*	node = createNewNode(value);
	s_node<T>*	x = *root;
	s_node<T>*	tmp = NULL;

	if (!*root)
	{
		*root = node;
		(*root)->color = 'b';
		(*root)->parent = NULL; //Tnull
		return ;
	}
	else
	{
		while (x)
		{
			tmp = x;
			if (node->value > x->value)
				x = x->right;
			else
				x = x->left;
		}
		node->parent = tmp;
		if (node->value > tmp->value)
			tmp->right = node;
		else
			tmp->left = node;
		if (node->parent->parent == NULL)
			return ;
		insertFix(*root, &node);
	}
}
/*template < class T >
void	insertNode(s_node<T>**	root, T value)
{
	s_node<T>*	node = createNewNode(value);
	if (!root)
	{
		*root = node;
		(*root)->color = 'b';
		(*root)->parent = NULL;
	}
	else
	{
		while (*root)
		{
			if (node->value > (*root)->value)
				*root = (*root)->right;
			else if (node->value < (*root)->value)
				(*root) = (*root)->left;
			else
				return;
			(*root)->parent = node->parent;
		}
		if (node->parent->value > node->value)
			node->parent->left = node;
		else
			node->parent->right = node;
		insertFix(*root, node);
	}
}*/

template < class T >
void	rbTransplant(s_node<T>** root, s_node<T>* u, s_node<T>* v)
{
	if (!u->parent)
		*root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v && u)
		v->parent = u->parent;
}

template < class T >
void	deleteFix(s_node<T>* root, s_node<T>*  node)
{
	s_node<T>* w = NULL;
	if (!node)
		std::cout <<"sexy\n";
	while (node != root && node && node->color == 'b')
	{
		std::cout << "mdr\n";
		if (node == node->parent->left)
		{
			w = node->parent->right;
			if (w->color == 'r')
			{
				w->color = 'b';
				node->parent->color = 'r';
				leftRotate(root, node->parent);
				w = node->parent->right;
			}
			if (w->left->color == 'b' && w->right->color == 'b')
			{
				w->color = 'r';
				node = node->parent;
			}
			else
			{
				if (w->right->color == 'b')
				{
					w->left->color =  'b';
					w->color = 'r';
					rightRotate(root, w);
					w = node->parent->right;
				}
				w->color = node->parent->color;
				node->parent->color = 'b';
				w->right->color = 'b';
				leftRotate(root, node->parent);
				*node = *root;
			}
		}
		else
		{
			w = node->parent->left;
			if (w->color == 'r')
			{
				w->color = 'b';
				node->parent->color = 'r';
				rightRotate(root, node->parent);
				w = node->parent->left;
			}
			if (w->right->color == 'b' && w->left->color == 'b')
			{
				w->color = 'r';
				node = node->parent;
			}
			else
			{
				if (w->left->color == 'b')
				{
					w->right->color =  'b';
					w->color = 'r';
					leftRotate(root, w);
					w = node->parent->left;
				}
				w->color = node->parent->color;
				node->parent->color = 'b';
				w->left->color = 'b';
				rightRotate(root, node->parent);
				node = root;
			}
		}
	}
	root->color = 'b';
}

template < class T >
void	deleteNode(s_node<T>** root, T key)
{
	s_node<T>* x, *y;
	x = y = NULL;
	s_node<T>* tmp = searchNode(*root, key);
	//cdt if no tmp
	y = tmp;
	char ogcolor = y->color;

	//std::cout << "lol " << tmp->value << "\n";
	if (!tmp->left)
	{
		x = tmp->right; //this is NULL, but why? TNULL? but Tnull doesnt hve a parent
		rbTransplant(root, tmp, tmp->right);
		std::cout << "lol1\n";
		std::cout << x->value << std::endl;
	}
	else if (!tmp->right)
	{
		std::cout << "lol2\n";
		x = tmp->left;
		rbTransplant(root, tmp, tmp->left);
	}
	else
	{
		std::cout << "lol3\n";
		y = findMin(tmp->right);
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
	delete tmp;
	//std::cout<<"xd " << x->value << " \n";
	if (ogcolor == 'b')
		deleteFix(*root, x);
}

template < class T >
void	printTree(s_node<T>* root, std::string indent, bool last)
{
	if (root)
	{
		if (root != NULL) {
			std::cout << indent;
			if (last) {
			std::cout << "R----";
			indent += "   ";
		} else {
			std::cout << "L----";
			indent += "|  ";
		}

		std::string sColor = root->color == 'r' ? "RED" : "BLACK";
		std::cout << root->value << "(" << sColor << ")" << std::endl;
 		printTree(root->left, indent, false);
		printTree(root->right, indent, true);
    }
	}
}


int main() {
	s_node<int>* root = NULL;
	insertNode(&root, 55);
	insertNode(&root, 40);
	insertNode(&root, 65);
	insertNode(&root, 60);
	insertNode(&root, 75);
	insertNode(&root, 57);

	printTree(root, "", true);
	std::cout << std::endl
		 << "After deleting" << std::endl;
	deleteNode(&root, 40);
	printTree(root, "", true);
}