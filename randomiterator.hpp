#ifndef __RANDOMITE__
# define __RANDOMITE__

# include <iterator>

namespace ft {

template < class T >
class RandIt {
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;

		RandIt(): _ptr(NULL) {}
		RandIt(pointer ptr): _ptr(ptr) {}
		RandIt(const RandIt& copy){	*this = copy;	}
		~RandIt();

		RandIt&	operator=(const RandIt& rhs) {
			if (this == &rhs)
				return *this;
			_ptr = rhs._ptr;
			return (*this);
		}
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

		difference_type	operator-(const RandIt& rhs) {	return (_ptr - rhs._ptr);	}
		RandIt			operator-(const difference_type& rhs) {	return (_ptr - rhs);	}
		RandIt			operator+(const difference_type& rhs) { return (_ptr + rhs);	}
		friend RandIt	operator+(const difference_type& lhs, const RandIt& rhs) {	return(rhs + lhs);	}
		RandIt			operator-=(const difference_type& rhs) {}
		RandIt			operator+=(const difference_type& rhs) {}

		reference		operator*() const {	return *_ptr;	}
		pointer			operator->() const {	return _ptr;	}
		reference		operator[](size_type n);
		const_reference operator[](size_type n) const;
		difference_type	operator[](const Random<value_type>&) const;

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