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

		rbt_ite() : current(NULL) {}

		rbt_ite(nodeptr node) : current(node){}

		rbt_ite(rbt_ite const &copy) : current(copy.current) {}

		~rbt_ite() {}

		rbt_ite	&operator=(rbt_ite const &rhs)
		{
			if (this != &rhs)
				current = rhs.current;
			return (*this);
		}

		operator	rbt_ite<const value_type, Node>() const
		{	return (rbt_ite<const value_type, Node>(current));	}

		rbt_ite	&operator++()
		{
			current = _next(current);
			return (*this);
		}

		rbt_ite	operator++(int)
		{
			rbt_ite tmp(current);
			current = _next(current);
			return (tmp);
		}

		rbt_ite	&operator--()
		{
			current = _prev(current);
			return (*this);
		}

		rbt_ite	operator--(int) {
			rbt_ite tmp(current);
			current = _prev(current);
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

	private:
		nodeptr	_max(nodeptr node)
		{
			if (node)
				while (node->right)
					node = node->right;
			return (node);
		}

		nodeptr	_min(nodeptr node)
		{
			if (node)
				while (node->left)
					node = node->left;
			return (node);
		}

		nodeptr	_next(nodeptr node)
		{
			if (node->right)
				return (_min(node->right));
			nodeptr parent = node->parent;
			while (parent && node == parent->right)
			{
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}

		nodeptr	_prev(nodeptr node)
		{
			if (node->left)
				return (_max(node->left));
			nodeptr parent = node->parent;
			while (parent && node == parent->left)
			{
				node = parent;
				parent = parent->parent;
			}
			return (parent);
		}
};

}

#endif