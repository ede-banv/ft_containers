#ifndef __REVERSEIT__
# define __REVERSEIT__

# include "iterator_traits.hpp"
# include "randomiterator.hpp"

namespace ft {

template< class Iter >
class reverse_iterator {
	public:
		typedef Iter													iterator_type;
		typedef typename std::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename std::iterator_traits<Iter>::value_type			value_type;
		typedef typename std::iterator_traits<Iter>::difference_type	difference_type;
		typedef typename std::iterator_traits<Iter>::pointer			pointer;
		typedef typename std::iterator_traits<Iter>::reference			reference;

		reverse_iterator(): _current() {}
		explicit reverse_iterator(iterator_type x); _current(x) {}
		template< class T >
		reverse_iterator(const reverse_iterator<T>& copy) {	*this = copy;	}

		template< class T >
		reverse_iterator&	operator=(const reverse_iterator<T>& rhs);
		iterator_type		base() const;
		reference			operator*() const {	return (*_current);	}
		pointer				operator->() const {	return (_current.operator->());	}
		reference			operator[](difference_type n) const {	return(_current[n]);	}

		reverse_iterator&	operator++() {	--_current;	return (*this);	}
		reverse_iterator&	operator--() {	++_current;	return (*this);	}
		reverse_iterator	operator++(int) {	return (reverse_iterator(--_current));	}
		reverse_iterator	operator--(int) {	return (reverse_iterator(++_current));	}
		reverse_iterator	operator+(difference_type n) const {	return (iterator_type(_current - n));	}
		reverse_iterator	operator-(difference_type n) const {	return (iterator_type(_current + n));	}
		reverse_iterator&	operator+=(difference_type n) {	_current -= n;	return (*this);	}
		reverse_iterator&	operator-=(difference_type n) {	_current += n;	return (*this);	}
	protected:
		Iter	_current;
};

// ** NON-MEMBER FUNCTIONS **
template< class Iter >
reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it) {

}

template< class Iterator >
typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {

}

}

#endif