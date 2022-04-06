#ifndef __RBT_CLASS__
# define __RBT_CLASS__

# include <iostream>
# include "../utils.hpp"

# ifndef __APPLE__
#  define __APPLE__ 0
# endif

namespace ft
{

template < class value_type >
struct s_node
{
	bool _unused;
	#if __APPLE__ == 0
		int _unused_linux;
	#endif
	value_type	value;
	char		color;
	struct s_node*	parent;
	struct s_node*	right;
	struct s_node*	left;

};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class rb_tree {
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef	Compare											key_compare;
		typedef std::allocator< ft::pair< const Key, T > >			allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef std::ptrdiff_t									difference_type;
		typedef size_t											size_type;
		typedef	s_node<value_type>*								nodeptr;

		rb_tree(allocator_type const &alloc = allocator_type(), key_compare const &compare = key_compare()) :
		_comp(compare), _pairalloc(alloc)
		{
			_root = NULL;
		}
		rb_tree(rb_tree const &rhs, allocator_type const &alloc = allocator_type(), key_compare const &compare = key_compare()) :
		_pairalloc(rhs._pairalloc), _comp(rhs._comp)//, _size(size_type(0))
		{
			*this= rhs;
		}
		virtual ~rb_tree()
		{
			//if _root
			// delete tree
		}

		rb_tree&	operator=(rb_tree rhs)
		{
			//if root
			// delete tree
			_root = rhs->_root;
			return (this);
		}

		nodeptr	findMin(nodeptr	node)
		{
			while (node->left != _Tnil)
				node = node->left;
			return (node);
		}
		nodeptr	findMax(nodeptr node)
		{
			while (node->right != _Tnil)
				node = node->right;
			return (node);
		}
		nodeptr	searchNode(key_type key)
		{
			nodeptr res = NULL;
			nodeptr tmp = _root;

			while (tmp != _Tnil)
			{
				if (!_comp(tmp->value, key) && !_comp(key, tmp->value))
				{
					res = tmp;
					break ;
				}
				else if (!_comp(tmp->value, key))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return (res);
		}

		void	leftRotate(nodeptr	x)
		{
			nodeptr	y = x->right;

			x->right = y->left;
			if (y->left != _Tnil)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == _Tnil)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
		void	rightRotate(nodeptr	x)
		{
			nodeptr	y = x->left;

			y->left = x->right;
			if (x->right != _Tnil)
				x->right->parent = y;
			y->parent = x->parent;
			if (x->parent == _Tnil)
				_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
		void	rbTransplant(nodeptr u, nodeptr v)
		{
			if (!u->parent)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		nodeptr	createNewNode(value_type value)
		{
			if (!_Tnil)
			{
				_Tnil = _nodealloc.allocate(1);
				//if (_Tnil)
				//	_pairalloc.construct(&_Tnil->value, NULL);
				_Tnil->color = 'b';
				_Tnil->left = _Tnil->right = _Tnil->parent = NULL;
			}
			nodeptr newN = _nodealloc.allocate(1);
			if (newN)
				_pairalloc.construct(&newN->value, value);

			newN->value = value;
			newN->color = 'r';
			newN->left = _Tnil;
			newN->right = _Tnil;
			newN->parent = _Tnil;
			return (newN);
		}
		void	insertNode(value_type value)
		{
			nodeptr	node = createNewNode(value);
			nodeptr	x = _root;
			nodeptr	tmp = NULL;

			if (!_root)
			{
				_root = node;
				_root->color = 'b';
				_root->parent = _Tnil;
				return ;
			}
			while (x != _Tnil)
			{
				tmp = x;
				if (_comp(x->value, node->value)) // x->v < n->v
					x = x->right;
				else
					x = x->left;
			}
			node->parent = tmp;
			if (_comp(node->value, tmp->value)) //node->v < tmp->v
				tmp->left = node;
			else
				tmp->right = node;

			if (node->parent->parent == _Tnil)
				return ;
			insertFix(node);
		}
		void	insertFix(nodeptr node)
		{
			nodeptr	y = NULL;

			while (node->parent->color == 'r')
			{
				if (node->parent == node->parent->parent->right)
				{
					y = node->parent->parent->left; //uncle
					if (y->color == 'r')
					{
						node->parent->color = 'b';
						y->color = 'b';
						node->parent->parent->color = 'r';
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->left)
						{
							node = node->parent;
							rightRotate(node);
						}
						node->parent->color = 'b';
						node->parent->parent->color = 'r';
						leftRotate(node->parent->parent);
					}
				}
				else
				{
					y = node->parent->parent->right;
					if (y->color == 'r')
					{
						y->color = 'b';
						node->parent->color = 'b';
						node->parent->parent->color = 'r';
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{
							node = node->parent;
							leftRotate(node);
						}
						node->parent->color = 'b';
						node->parent->parent->color = 'r';
						rightRotate(node->parent->parent);
					}
				}
				if (node == _root)
					break;
			}
			_root->color = 'b';
		}

		void	deleteNode(key_type key)
		{
			nodeptr x, y;
			x = y = NULL;
			nodeptr	tmp = searchNode(key);
			if (!tmp)
			{
				std::cout << "Key not found in tree\n";
				return ;
			}

			y = tmp;
			char	ogcolor = y->color;
			if (tmp->left == _Tnil)
			{
				x = tmp->right;
				rbTransplant(tmp, tmp->right);
			}
			else if (tmp->right == _Tnil)
			{
				x = tmp->left;
				rbTransplant(tmp, tmp->left);
			}
			else
			{
				y = findMin(tmp->right);
				ogcolor = y->color;
				x = y->right;
				if (y->parent == tmp)
					x->parent = y;
				else
				{
					rbTransplant(y, y->right);
					y->right = tmp->right;
					y->right->parent = y;
				}
				rbTransplant(tmp, y);
				y->left = tmp->left;
				y->left->parent = y;
				y->color = tmp->color;
			}
			_pairalloc.destroy(&tmp->value);
			_nodealloc.deallocate(tmp, 1);
			if (ogcolor == 'b')
				deleteFix(x);
		}
		void	deleteFix(nodeptr node)
		{
			nodeptr	w = NULL;

			while (node != _root && node->color == 'b')
			{
				if (node == node->parent->left)
				{
					w = node->parent->right;
					if (w->color == 'r')
					{
						w->color = 'b';
						node->parent->color = 'r';
						leftRotate(node->parent);
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
							w->left->color = 'b';
							w->color = 'r';
							rightRotate(w);
							w = node->parent->right;
						}
						w->color = node->parent->color;
						node->parent->color = 'b';
						w->right->color = 'b';
						leftRotate(node->parent);
						node = _root;
					}
				}
				else
				{
					w = node->parent->left;
					if (w->color == 'r')
					{
						w->color = 'b';
						node->parent->color = 'r';
						rightRotate(node->parent);
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
							w->right->color = 'b';
							w->color = 'r';
							leftRotate(w);
							w = node->parent->left;
						}
						w->color = node->parent->color;
						node->parent->color = 'b';
						w->left->color = 'b';
						rightRotate(node->parent);
						node = _root;
					}
				}
			}
			node->color = 'b';
		}

		void    printTree(std::string indent, bool last, nodeptr node = _root)
		{
			nodeptr tmp = node;
			if (tmp)
			{
				if (tmp != NULL) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "   ";
					} else {
						std::cout << "L----";
						indent += "|  ";
					}

					std::string sColor = tmp->color == 'r' ? "RED" : "BLACK";
					std::cout << tmp->value.key << "(" << sColor << ")" << std::endl;
 					printTree(indent, false, tmp->left);
					printTree(indent, true, tmp->right);
    			}
			}
		}

	protected:
	private:
		key_compare		_comp;
		allocator_type	_pairalloc;
		std::allocator< s_node< value_type > >	_nodealloc;
		nodeptr	_root;
		nodeptr	_Tnil;

};

}

#endif