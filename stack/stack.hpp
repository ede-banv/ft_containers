#ifndef __STACK__
# define __STACK__

# include <iostream>
# include "../vector/vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit			stack (const container_type& ctnr = container_type()): _data(ctnr) {}
		bool				empty() const {	return(_data.empty());	}
		size_type			size() const {	return(_data.size());	}
		value_type&			top() {	return(_data.back());	}
		const value_type&	top() const {	return(_data.back());	}
		void				push (const value_type& val) {	_data.push_back(val);	}
		void				pop() {	_data.pop_back();	}
		friend bool operator==(const stack &lhs, const stack &rhs) {
			return (lhs._data == rhs._data); }
        friend bool operator<(const stack &lhs, const stack &rhs) {
			return (lhs._data < rhs._data); }
	protected:
		container_type	_data;
};

// * RELATIONAL OPERATORS

template <class T, class Container>
bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs == rhs); }
template <class T, class Container>
bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (!(lhs == rhs));	}
template <class T, class Container>
bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs < rhs);	}
template <class T, class Container>
bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (lhs < rhs || lhs == rhs ? true : false);	}
template <class T, class Container>
bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (!(lhs < rhs) && lhs != rhs ? true : false);	}
template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return (!(lhs < rhs) || lhs == rhs ? true : false);	}
};

#endif