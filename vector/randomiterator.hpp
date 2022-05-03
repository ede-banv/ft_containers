#ifndef __RANDOMITE__
# define __RANDOMITE__

# include <iterator>

namespace ft {

template < class T >
class RandIt {
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef const T&						const_reference;
		typedef std::ptrdiff_t					difference_type;
		typedef size_t							size_type;

		RandIt(): _ptr(NULL) {}
		RandIt(pointer ptr): _ptr(ptr) {}
		RandIt(const RandIt& copy){	*this = copy;	}
		virtual ~RandIt() {}

		RandIt&	operator++() {
			_ptr++;
			return (*this);
		}
		RandIt	operator++(int) {
			RandIt tmp(*this);
			++(*this);
			return (tmp);
		}
		RandIt&	operator--() {
			_ptr--;
			return (*this);
		}
		RandIt	operator--(int) {
			RandIt tmp(*this);
			--(*this);
			return (tmp);
		}

		difference_type	operator-(const RandIt& rhs) const {	return (_ptr - rhs._ptr);	}
		RandIt			operator-(const difference_type& rhs) const {	return (RandIt(_ptr - rhs));	}
		RandIt			operator+(const difference_type& rhs) const { return (RandIt(_ptr + rhs));	}
		friend RandIt	operator+(const difference_type& lhs, const RandIt& rhs) {	return(RandIt(rhs._ptr + lhs));	}
		RandIt			operator-=(const difference_type& rhs) {
			_ptr -= rhs;
			return (*this);
		}
		RandIt			operator+=(const difference_type& rhs) {
			_ptr += rhs;
			return (*this);
		}

		reference		operator*() const {	return *_ptr;	}
		pointer			operator->() const {	return _ptr;	}

		bool		operator==(const RandIt& rhs) const {	return (_ptr == rhs._ptr);	}
		bool		operator!=(const RandIt& rhs) const {	return (_ptr != rhs._ptr);	}
		bool		operator>(const RandIt& rhs) const {	return (_ptr > rhs._ptr);	}
		bool		operator>=(const RandIt& rhs) const {	return (_ptr >= rhs._ptr);	}
		bool		operator<(const RandIt& rhs) const {	return (_ptr < rhs._ptr);	}
		bool		operator<=(const RandIt& rhs) const {	return (_ptr <= rhs._ptr);	}
	protected:
		pointer	_ptr;
};

}

#endif