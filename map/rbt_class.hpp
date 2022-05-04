#ifndef __RBT_CLASS__
# define __RBT_CLASS__

# include <iostream>
# include <sstream>
# include "../utils.hpp"
# include "rbtiterator.hpp"
# include "../reverseiterator.hpp"

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
	struct s_node*	left;
	struct s_node*	right;

	s_node(const value_type &src = value_type()) : \
		value(src), parent(NULL), left(NULL), right(NULL) {};
};

template < class U, class V >
std::ostream&	operator<<(std::ostream& o, const ft::pair<const U, V>& rhs)
{	o<<rhs.key;return o;}

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
		typedef	s_node< value_type >*							nodeptr;

		typedef rbt_ite< T, s_node< T > >						iterator;
		typedef rbt_ite< T const, s_node< T > >				const_iterator;
		typedef ft::reverse_iterator< iterator >				reverse_iterator;
		typedef ft::reverse_iterator< const_iterator >			const_reverse_iterator;

		/* * * * Constructors * * * */
		rb_tree(allocator_type const &alloc = allocator_type(), key_compare const &compare = key_compare()) :
		_comp(compare), _pairalloc(alloc), _size(0)
		{
			_root = NULL;
		}
		rb_tree(rb_tree const &rhs) :
		_pairalloc(rhs._pairalloc), _comp(rhs._comp), _size(rhs.size)//, _size(size_type(0))
		{
			*this= rhs;
		}
		virtual ~rb_tree()
		{
			delete_recursif(_root);
		}

		rb_tree&	operator=(rb_tree rhs)
		{
			delete_recursif(_root);
			_root = rhs->_root;
			//other values as well?
			return (this);
		}

		void	delete_recursif(nodeptr node)
		{
			if (!node)
				return ;
			if (node->left)
				delete_recursif(node->left);
			if (node->right)
				delete_recursif(node->right);
			_pairalloc.destroy(&node->value);
			_nodealloc.deallocate(node, 1);
		}

		/* * * * Getter * * * */
		size_type	getSize()
		{	return (_size);	}

		/* * * * Finders * * * */
		nodeptr	findMin(nodeptr	node)
		{
			while (node->left != NULL)
				node = node->left;
			return (node);
		}
		nodeptr	findMax(nodeptr node)
		{
			while (node->right != NULL)
				node = node->right;
			return (node);
		}
		nodeptr	findLast()
		{	return (findMax(_root));	}
		nodeptr	searchNode(key_type key)
		{
			nodeptr res = NULL;
			nodeptr tmp = _root;

			while (tmp != NULL)
			{
				if (!_comp(tmp->value.key, key) && !_comp(key, tmp->value.key))
				{
					res = tmp;
					break ;
				}
				else if (!_comp(tmp->value.key, key))
					tmp = tmp->left;
				else
					tmp = tmp->right;
			}
			return (res);
		}
		nodeptr	getPrev(nodeptr node)
		{
			if (node->left)
				return (findMax(node->left));
			nodeptr parent = node->parent;
			while (parent && node == parent->left)
			{
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}
		nodeptr	getNext(nodeptr node)
		{
			if (node->right)
				return (findMin(node->right));
			nodeptr parent = node->parent;
			while (parent && node == parent->right)
			{
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}

		/* * * * Movers * * * */
		void	leftRotate(nodeptr	x)
		{
			nodeptr	y = x->right;

			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
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

			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
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
			if (v && v->parent)
				v->parent = u->parent;
		}

		/* * * * Nodes Insertion-Deletion * * * */
		nodeptr	createNewNode(value_type value)
		{
			nodeptr newN = _nodealloc.allocate(1);
			if (!newN)
				return NULL;
			_pairalloc.construct(&newN->value, value);

			newN->color = 'r';
			newN->left = NULL;
			newN->right = NULL;
			newN->parent = NULL;
			return (newN);
		}
		int		insertNode(value_type value)
		{
			if (searchNode(value))
				return (0);
			nodeptr	node = createNewNode(value);
			nodeptr	x = _root;
			nodeptr	tmp = NULL;

			if (!_root)
			{
				_root = node;
				_root->color = 'b';
				return (1);
			}
			while (x != NULL)
			{
				tmp = x;
				if (_comp(x->value.key, node->value.key)) // x->v < n->v
					x = x->right;
				else
					x = x->left;
			}
			node->parent = tmp;
			if (_comp(node->value.key, tmp->value.key)) //node->v < tmp->v
				tmp->left = node;
			else
				tmp->right = node;

			if (node->parent->parent == NULL)
				return ;
			insertFix(node);
			_size++;
			return (1);
		}
		void	insertFix(nodeptr node)
		{
			nodeptr	y = NULL;

			while (node->parent->color == 'r')
			{
				if (node->parent == node->parent->parent->right)
				{
					y = node->parent->parent->left; //uncle
					if (y && y->color == 'r')
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
					if (y && y->color == 'r')
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

		bool	deleteNode(key_type key)
		{
			nodeptr x, y, oldparent;
			bool		left;
			x = y = oldparent = NULL;
			nodeptr	tmp = searchNode(key);
			if (!tmp)
				return (false);

			y = tmp;
			char	ogcolor = y->color;
			if (tmp->left == NULL)
			{
				x = tmp->right;
				oldparent = tmp->parent;
				left = (tmp->parent && tmp == tmp->parent->left ? true : false);
				rbTransplant(tmp, tmp->right);
			}
			else if (tmp->right == NULL)
			{
				x = tmp->left;
				oldparent = tmp->parent;
				left = (tmp->parent && tmp == tmp->parent->left ? true : false);
				rbTransplant(tmp, tmp->left);
			}
			else
			{
				y = findMin(tmp->right);
				ogcolor = y->color;
				x = y->right;
				if (y->parent == tmp)
				{
					if (x)
						x->parent = y;
				}
				else
				{
					oldparent = y->parent;
					left = (tmp->parent && tmp == y->parent->left ? true : false);
					rbTransplant(y, y->right);
					y->right = tmp->right;
					y->right->parent = y;
				}
				oldparent = tmp->parent;
				left = (tmp->parent && tmp == tmp->parent->left ? true : false);
				rbTransplant(tmp, y);
				y->left = tmp->left;
				y->left->parent = y;
				y->color = tmp->color;
			}
			_pairalloc.destroy(&tmp->value);
			_nodealloc.deallocate(tmp, 1);
			if (ogcolor == 'b')
				deleteFix(x, oldparent, left);
			_size--;
			return (true);
		}
		void	deleteFix(nodeptr node, nodeptr parent, bool left)
		{
			nodeptr	w = NULL;

			while (parent != NULL && (node && node->color == 'b'))
			{
				if (left)
				{
					w = parent->right;
					if (w->color == 'r')
					{
						w->color = 'b';
						parent->color = 'r';
						leftRotate(parent);
						w = parent->right;
					}
					if (w->left && w->left->color == 'b' && w->right && w->right->color == 'b')
					{
						w->color = 'r';
						node = parent;
					}
					else
					{
						if (w->right && w->right->color == 'b')
						{
							w->left->color = 'b';
							w->color = 'r';
							rightRotate(w);
							w = parent->right;
						}
						w->color = parent->color;
						parent->color = 'b';
						if (w->right)
							w->right->color = 'b';
						leftRotate(parent);
						node = _root;
					}
				}
				else
				{
					w = parent->left;
					if (w->color == 'r')
					{
						w->color = 'b';
						parent->color = 'r';
						rightRotate(parent);
						w = parent->left;
					}
					if (w->right && w->right->color == 'b' && w->left && w->left->color == 'b')
					{
						w->color = 'r';
						node = parent;
					}
					else
					{
						if (w->left && w->left->color == 'b')
						{
							w->right->color = 'b';
							w->color = 'r';
							leftRotate(w);
							w = parent->left;
						}
						w->color = parent->color;
						parent->color = 'b';
						if (w->left)
							w->left->color = 'b';
						rightRotate(parent);
						node = _root;
					}
				}
			}
			if (node)
				node->color = 'b';
		}

		/* * * * Iterator * * * */
		iterator	begin()
		{	return (iterator(min(), _root));	}
		const_iterator	begin() const
		{	return (const_iterator(min(), _root));	}
		iterator	end()
		{	return (iterator(_nil, _root));	}
		const_iterator	end() const
		{	return (const_iterator(_nil, _root));	}
		reverse_iterator	rbegin()
		{	return (reverse_iterator(end()));	}
		const_reverse_iterator	rbegin() const
		{	return (const_reverse_iterator(end()));	}
		reverse_iterator	rend()
		{	return (reverse_iterator(begin()));	}
		const_reverse_iterator	rend() const
		{	return (const_reverse_iterator(begin()));	}

		/* * * * Printer * * * */
		void    printTree(void) {
			std::stringstream buffer;
			this->_print(this->_root, buffer, true, "");
			std::cout << buffer.str();
		}
		void	_print(nodeptr node, std::stringstream &buffer, bool is_tail, std::string prefix) {
			if (node == NULL)
				return;
			if (node->right != NULL)
				this->_print(node->right, buffer, false,
					std::string(prefix).append(is_tail != 0 ? "│   " : "	"));
			buffer << prefix << (is_tail != 0 ? "└── " : "┌── ");
			if (node->color == 'r')
				buffer << "\033[31m";
			buffer << node->value << "\033[0m" << std::endl;
			if (node->left != NULL)
				this->_print(node->left, buffer, true,
					std::string(prefix).append(is_tail != 0 ? "    " : "│   "));
		}

	protected:
	private:
		key_compare		_comp;
		allocator_type	_pairalloc;
		std::allocator< s_node< value_type > >	_nodealloc;
		nodeptr	_root;
		nodeptr	last;
		size_type	_size;

};

}

#endif