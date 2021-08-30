#ifndef __RAND__
# define __RAND__

# include <iterator>

namespace ft
{

template <typename T>
class RandomAccessIterator {
	public:
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;

		RandomAccessIterator(): _ptr(NULL) {}
		RandomAccessIterator(pointer ptr): _ptr(ptr) {}
		RandomAccessIterator(const RandomAccessIterator& copy){	*this = copy;	}
		~RandomAccessIterator();

		RandomAccessIterator&	operator++() {
			_ptr++;
			return (*this);
		}
		RandomAccessIterator	operator++(int) {
			RandomAccessIterator tmp(*this);
			++(*this);
			return (tmp);
		}
		RandomAccessIterator&	operator--() {
			_ptr--;
			return (*this);
		}
		RandomAccessIterator	operator--(int) {
			RandomAccessIterator tmp(*this);
			--(*this);
			return (tmp);
		}
		RandomAccessIterator&	operator=(const RandomAccessIterator& rhs) {
			if (this == &rhs)
				return *this;
			_ptr = rhs._ptr;
			return (*this);
		}
		difference_type	operator-(const RandomAccessIterator& rhs) {	return (_ptr - rhs._ptr);	}
		RandomAccessIterator	operator+(const difference_type& rhs) {
			for (difference_type i = 0; i < rhs; ++i)
				++(*this);
			return (*this);
		}
		RandomAccessIterator	operator+(const difference_type& lhs, const RandomAccessIterator&rhs) const {
			return (RandomAccessIterator(rhs + lhs));
		}
		RandomAccessIterator	operator-(const difference_type& rhs) {
			for (difference_type i = 0; i < rhs; ++i)
				--(*this);
			return (*this);
		}
		RandomAccessIterator	operator+=(const difference_type& rhs) const {
			return (RandomAccessIterator(*this + rhs));
		}
		RandomAccessIterator	operator-=(const difference_type& rhs) const {
			return (RandomAccessIterator(*this - rhs));
		}
		reference	operator*() const {	return (*_ptr);	}
		reference	operator[](const size_type n) const {	return (_ptr[n]);	}
		//missing one?
		pointer		operator->() const {	return( _ptr);	}
		bool		operator==(const RandomAccessIterator& rhs) const {	return (_ptr == rhs._ptr);	}
		bool		operator!=(const RandomAccessIterator& rhs) const {	return (_ptr != rhs._ptr);	}
		bool		operator>(const RandomAccessIterator& rhs) const {	return (_ptr > rhs._ptr);	}
		bool		operator>=(const RandomAccessIterator& rhs) const {	return (_ptr >= rhs._ptr);	}
		bool		operator<(const RandomAccessIterator& rhs) const {	return (_ptr < rhs._ptr);	}
		bool		operator<=(const RandomAccessIterator& rhs) const {	return (_ptr <= rhs._ptr);	}
		//get value???????????????????????????????
	protected:
		pointer	_ptr;
};

}

#endif