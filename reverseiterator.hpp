#ifndef __REVERSEIT__
# define __REVERSEIT__

# include "iterator_traits.hpp"

namespace ft {

template< class Iter >
class reverse_iterator {
	public:
		typedef iterator_type				Iter;
		typedef typename iterator_category	std::iterator_traits<Iter>::iterator_category;
		typedef typename value_type			std::iterator_traits<Iter>::value_type;
		typedef typename difference_type	std::iterator_traits<Iter>::difference_type;
		typedef typename pointer			std::iterator_traits<Iter>::pointer;
		typedef typename reference			std::iterator_traits<Iter>::reference;

		reverse_iterator();
		explicit reverse_iterator( iterator_type x );
		template< class T >
		reverse_iterator( const reverse_iterator<T>& other );

		template< class T >
		reverse_iterator& operator=( const reverse_iterator<T>& other );
		iterator_type base() const;
		reference operator*() const;
		pointer operator->() const;
		operator[]( difference_type n ) const;

		reverse_iterator& operator++();
		reverse_iterator& operator--();
		reverse_iterator operator++( int );
		reverse_iterator operator--( int );
		reverse_iterator operator+( difference_type n ) const;
		reverse_iterator operator-( difference_type n ) const;
		reverse_iterator& operator+=( difference_type n );
		reverse_iterator& operator-=( difference_type n );
	protected:
		//current
	//private:?
}

// ** NON-MEMBER FUNCTIONS **

template< class Iterator1, class Iterator2 >
bool operator==( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

template< class Iterator1, class Iterator2 >
bool operator!=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

template< class Iterator1, class Iterator2 >
bool operator<( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

template< class Iterator1, class Iterator2 >
bool operator<=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

template< class Iterator1, class Iterator2 >
bool operator>( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

template< class Iterator1, class Iterator2 >
bool operator>=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs );

template< class Iter >
reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it );

template< class Iterator >
typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs );

}

#endif