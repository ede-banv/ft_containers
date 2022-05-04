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
		{	return (current->value);	}

		const_reference	operator*() const
		{	return (current->value);	}

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
};

}

#endif