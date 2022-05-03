#ifndef __RB_ITE__
# define __RB_ITE__

# include <iterator>
# include "rbt_class.hpp"


namespace ft {

template <typename T, typename Node>
class rbt_ite {

	public:
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef T*								pointer;
		typedef const T*						const_pointer;
		typedef T& 								reference;
		typedef const T&						const_reference;
		typedef std::ptrdiff_t					difference_type;
		typedef Node*							nodeptr;

		nodeptr current;

		rbt_ite() : current(NULL), _root(NULL) {}

		rbt_ite(nodeptr node, nodeptr root) : current(node), _root(root) {}

		rbt_ite(rbt_ite const &copy) : current(copy.current), _root(copy._root) {}

		~rbt_ite() {}

		rbt_ite	&operator=(rbt_ite const &rhs)
		{
			if (this != &rhs) {
				current = rhs.current;
				_root = rhs._root;
			}
			return (*this);
		}

		operator	rbt_ite<const value_type, Node>() const
		{	return (rbt_ite<const value_type, Node>(current, _root));	}

		rbt_ite	&operator++()
		{
			current = _next(current);
			return (*this);
		}

		rbt_ite	operator++(int)
		{
			rbt_ite tmp(current, _root);
			current = _next(current);
			return (tmp);
		}

		pointer	operator->()
		{	return (&operator*());	}

		const_pointer	operator->() const
		{	return (&operator*());	}

		reference	operator*()
		{	return (current->data);	}

		const_reference	operator*() const
		{	return (current->data)	}

		bool	operator==(rbt_ite const &rhs) const
		{	return (current == rhs.current);	}

		bool	operator!=(rbt_ite const &rhs) const
		{	return (current != rhs.current);	}

	/*-------------------
		BIDIRECTIONNAL
	-------------------*/

		rbt_ite	&operator--()
		{
			if (current == NULL)
				current = _max(_root);
			else
				current = _prev(current);
			return (*this);
		}

		rbt_ite	operator--(int) {
			rbt_ite tmp(current, _root);
			if (current == NULL)
				current = _max(_root);
			else
				current = _prev(current);
			return (tmp);
		}

	/*-----------
		UTILS
	-----------*/

	private:
		nodeptr _root;

		nodeptr	_max(nodeptr node) {
			if (node)
				while (node->right)
					node = node->right;
			return (node);
		}
		nodeptr	_min(nodeptr node) {
			if (node)
				while (node->left)
					node = node->left;
			return (node);
		}

		/* Si node right alors on return min du node de droite
			else on remonte les parents de l'arbre
		nodeptr	_next(nodeptr node) {
			if (node->right != this->_nil)
				return (this->_min(node->right));
			nodeptr parent = node->parent;
			while (parent != this->_nil && node == parent->right) {
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}
		nodeptr	_prev(nodeptr node) {
			if (node->left != this->_nil)
				return (this->_max(node->left));
			nodeptr parent = node->parent;
			while (parent != this->_nil && node == parent->left) {
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}*/
};

/*
template < class T >
class BiDir {
	public:
		typedef std::bidirectional_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t							difference_type;
		typedef size_t									size_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef const T&								const_reference;

		BiDir(): _ptr(NULL) {}
		BiDir(pointer ptr): _ptr(ptr) {}
		BiDir(const BiDir& copy){	*this = copy;	}
		virtual ~BiDir() {}

		BiDir&		operator=(BiDir& const rhs) {
			if (this == &rhs)
				return (*this);
			this->_ptr = rhs._value;
			return (*this);
		}
		BiDir&		operator++() {
			_ptr++;
			return (*this);
		}
		BiDir		operator++(int) {
			BiDir	tmp(*this);
			++(*this);
			return (tmp);
		}
		BiDir&		operator--() {
			_ptr--;
			return (*this);
		}
		BiDir		operator--(int) {
			BiDir	tmp(*this);
			--(*this);
			return (*this);
		}

		reference	operator*() const {	return *_ptr;	}
		pointer		operator->() const {	return _ptr;	}
		bool		operator==(const RandIt& rhs) const {	return (_ptr == rhs._ptr);	}
		bool		operator!=(const RandIt& rhs) const {	return (_ptr != rhs._ptr);	}
	private:
		value_type	_ptr;
}
*/
}

#endif