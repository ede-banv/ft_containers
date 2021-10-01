#ifndef __REVERSEIT__
# define __REVERSEIT__

# include "iterator_traits.hpp"
# include "randomiterator.hpp"

namespace ft {

template< class Iter >
class reverse_iterator {
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer			pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

		reverse_iterator(): _current() {}
		explicit reverse_iterator(iterator_type x): _current(x) {}
		template< class T >
		reverse_iterator(const reverse_iterator<T>& copy): _current(copy.base()) {}

		template< class T >
		reverse_iterator&	operator=(const reverse_iterator<T>& rhs) {
			if (reinterpret_cast<const void *>(this) == reinterpret_cast<const void *>(&rhs))
				return (*this);
			_current = rhs.base();
			return (*this);
		}
		iterator_type		base() const {	return(_current);	}
		reference			operator*() const {	return (*_current);	}
		pointer				operator->() const {	return (_current.operator->());	}
		reference			operator[](difference_type n) const {	return(*(*this + n));	}

		reverse_iterator&	operator++() {	--_current;	return (*this);	}
		reverse_iterator&	operator--() {	++_current;	return (*this);	}
		reverse_iterator	operator++(int) {	return (reverse_iterator(--_current));	}
		reverse_iterator	operator--(int) {	return (reverse_iterator(++_current));	}
		reverse_iterator	operator+(difference_type n) const {	return (reverse_iterator(_current - n));	}
		reverse_iterator	operator-(difference_type n) const {	return (reverse_iterator(_current + n));	}
		reverse_iterator&	operator+=(difference_type n) {	_current -= n;	return (*this);	}
		reverse_iterator&	operator-=(difference_type n) {	_current += n;	return (*this);	}
	protected:
		iterator_type	_current;
};

// ** NON-MEMBER FUNCTIONS **
template <class Iter1, class Iter2>
bool operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
	return (lhs.base() == rhs.base());
}

template <class Iter1, class Iter2>
bool operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
	return (lhs.base() != rhs.base());
}

template <class Iter1, class Iter2>
bool operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
	return (lhs.base() > rhs.base());
}

template <class Iter1, class Iter2>
bool operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
	return (lhs.base() >= rhs.base());
}

template <class Iter1, class Iter2>
bool operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
	return (lhs.base() < rhs.base());
}

template <class Iter1, class Iter2>
bool operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
	return (lhs.base() <= rhs.base());
}

template <class Iter>
reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rhs) {
	return (reverse_iterator<Iter>(rhs.base() - n));
}

template <class Iter1, class Iter2>
typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs) {
	return (rhs.base() - lhs.base());
}

}

#endif