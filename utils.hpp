#ifndef __UTILS__
# define __UTILS__

namespace ft
{

// ** LEXICOGRAPHICAL COMPARE **

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, InputIterator2 last2) {
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
InputIterator2 last2, Compare comp);

// ** EQUAL **

template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
	}
	return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (!pred(*first1, *first2))
			return false;
		++first1; ++first2;
	}
	return true;
}

// -------- ENABLE IF
template<bool, class T>
struct enable_if {};
template<class T>
struct enable_if<true, T> { typedef T type; };

// -------- IS INTEGRAL
template <class T>
struct is_integral {
	const static bool value = false;
};
template <>
struct is_integral<int> {
	const static bool value = true;
};

// -------- PAIR

template < class Key, class T >
struct pair {
	typedef Key	key_type;
	typedef T	value_type;

	key_type	key;
	value_type	value;

	pair(void) :
		key(),
		value() {}

	template< class U, class V >
	pair(const pair<U, V> & pr) :
		key(pr.key),
		value(pr.value) {}

	pair(const key_type & a, const value_type & b) :
		key(a),
		value(b) {}

	pair& operator= (const pair & pr) {
		if (this == &pr) return *this;
		key = pr.key;
		value = pr.value;
		return *this;
	}
};

template < class Key, class T >
bool operator== (const pair<Key, T>& lhs, const pair<Key, T>& rhs) {
	return lhs.key == rhs.key && lhs.value == rhs.value;
}

template < class Key, class T >
bool operator!= (const pair<Key, T>& lhs, const pair<Key, T>& rhs) {
	return !(lhs == rhs);
}

template < class Key, class T >
bool operator<  (const pair<Key, T>& lhs, const pair<Key, T>& rhs) {
	return lhs.key < rhs.key || (!(rhs.key < lhs.key) && lhs.value < rhs.value);
}

template < class Key, class T >
bool operator<= (const pair<Key, T>& lhs, const pair<Key, T>& rhs) {
	return !(rhs < lhs);
}

template < class Key, class T >
bool operator>  (const pair<Key, T>& lhs, const pair<Key, T>& rhs) {
	return rhs < lhs;
}

template < class Key, class T >
bool operator>= (const pair<Key, T>& lhs, const pair<Key, T>& rhs) {
	return !(lhs < rhs);
}

template< class Key, class T >
pair<Key,T> make_pair( Key t, T u )
{
	return (pair<Key, T>(t, u));
}

}

#endif