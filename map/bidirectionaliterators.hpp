#ifndef __BIDIR__
# define __BIDIR__

# include <iterator>

namespace ft {

template < class T >
class BiDir {
	public:
		typedef std::bidirectional_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t							difference_type;
		typedef size_t									size_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef const T&								const_reference;

		BiDir(): _ptr(NULL) {}
		BiDir(pointer ptr): _ptr(ptr) {}
		BiDir(const BiDir& copy){	*this = copy;	}
		virtual ~BiDir() {}

		BiDir&		operator=(BiDir& const rhs) {
			if (this == &rhs)
				return (*this);
			this->_ptr = rhs._value;
			return (*this);
		}
		BiDir&		operator++() {
			_ptr++;
			return (*this);
		}
		BiDir		operator++(int) {
			BiDir	tmp(*this);
			++(*this);
			return (tmp);
		}
		BiDir&		operator--() {
			_ptr--;
			return (*this);
		}
		BiDir		operator--(int) {
			BiDir	tmp(*this);
			--(*this);
			return (*this);
		}

		reference	operator*() const {	return *_ptr;	}
		pointer		operator->() const {	return _ptr;	}
		bool		operator==(const RandIt& rhs) const {	return (_ptr == rhs._ptr);	}
		bool		operator!=(const RandIt& rhs) const {	return (_ptr != rhs._ptr);	}
	private:
		value_type	_ptr;
}

}

#endif