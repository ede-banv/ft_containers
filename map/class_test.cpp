#include "rbt_class.hpp"

int main()
{
	ft::rb_tree<int, int> root;
	root.insertNode(ft::pair<const int, int>(55, 1));
	root.insertNode(ft::pair<const int, int>(40, 2));
	root.insertNode(ft::pair<const int, int>(50, 3));
	root.insertNode(ft::pair<const int, int>(60, 4));
	root.insertNode(ft::pair<const int, int>(65, 5));
	root.insertNode(ft::pair<const int, int>(57, 6));

	root.printTree();
	std::cout << std::endl
		 << "After deleting" << std::endl;
	root.deleteNode(40);
	root.printTree();
}