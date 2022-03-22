#ifndef __RBT_CLASS__
# define __RBT_CLASS__

# ifndef __APPLE__
#  define __APPLE__ 0
# endif

namespace ft
{

template < class pair_type>
class rb_tree {
	public:
	protected:
	private:
		bool _unused;
		#if __APPLE__ == 0
			int _unused_linux;
		#endif
}

}

#endif