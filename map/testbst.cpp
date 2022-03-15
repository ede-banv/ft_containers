#include <iostream>

template < class pair_type >
struct s_node {
	pair_type	value;
	struct s_node* left;
	struct s_node* right;
	struct s_node* parent;

};

template < class pair_type >
s_node<pair_type>*	createNewNode(pair_type value)
{
	s_node<pair_type>* newN = new s_node<pair_type>; //alloc unsure

	newN->value = value;
	newN->left = NULL;
	newN->right = NULL;
	newN->parent = NULL;
	return (newN);
}

template < class pair_type >
s_node<pair_type>*	findKey(s_node<pair_type>*	start, pair_type value)
{
	if (start->value == value)
		return (start);
	else if (start->value > value)
		findKey(start->right, value);
	else if (start->value < value)
		findKey(start->left, value);
	return (NULL);
}

template < class pair_type >
bool	insertNode(s_node<pair_type>** root, pair_type value)
{
	if (!(*root))
	{
		*root = createNewNode(value);
		return (true);
	}
	else if ((*root)->value == value)
		return (true);
	else if (value > (*root)->value)
	{
		insertNode(&(*root)->right, value);
		(*root)->right->parent = *root;
		return (true);
	}
	else if (value < (*root)->value)
	{
		insertNode(&(*root)->left, value);
		(*root)->left->parent = *root;
		return (true);
	}
	return (false);
}

template < class pair_type >
void	inOrder(s_node<pair_type>** root)
{
	if (*root)
	{
		inOrder(&(*root)->left);
		std::cout << (*root)->value << " ";
		inOrder(&(*root)->right);
	}
}

template < class pair_type>
void	searchKey(s_node<pair_type>** root, pair_type key)
{
	while (*root && (*root)->value != key)
	{
		if (key < (*root)->value)
			*root = (*root)->left;
		else
			*root = (*root)->right;
	}
}

template < class pair_type>
s_node<pair_type>*	findMaxKey(s_node<pair_type>* root)
{
	while(root->right)
		root = root->right;
	return  (root);
}

template < class pair_type >
void deleteNode(s_node<pair_type>* root, pair_type k)
//to verify: parent changed in case 3: enough?
{
	if (!root)
		return;
	s_node<pair_type>* curr = root;
	searchKey(&curr, k);
	std::cout << curr->value;
	if (!curr)
		return;
	else if (!curr->left && !curr->right)
	{
	std::cout << "1\n";
		if (curr != root)
		{
			if (curr->parent->left == curr)
				curr->parent->left = NULL;
			else
				curr->parent->right = NULL;
		}
		else
			root = NULL;
		delete curr;
	}
	else if (curr->right && curr->left)
	{
	std::cout << "2\n";
		s_node<pair_type>* pred = findMaxKey(curr->left);
		pair_type tmp = pred->value;
		deleteNode(root, pred->value);
		curr->value = tmp;
	}
	else
	{
	std::cout << "3\n";
		if (curr != root)
		{
			if (curr == curr->parent->left)
				curr->parent->left = curr->left ? curr->left : curr->right;
			else
				curr->parent->right = curr->left ? curr->left : curr->right;
		}
		else
			root = curr->left ? curr->left : curr->right;
		(curr->left ? curr->left : curr->right)->parent = curr->parent;
		delete curr;
	}

}

int main()
{
	s_node<int>* root = NULL;
	insertNode(&root, 50);
	insertNode(&root, 30);
	insertNode(&root, 20);
	insertNode(&root, 40);
	insertNode(&root, 70);
	insertNode(&root, 60);
	insertNode(&root, 80);

    std::cout << "Inorder traversal of the given tree \n";
    inOrder(&root);

    std::cout << "\nDelete 20\n";
    deleteNode(root, 20);
    std::cout << "Inorder traversal of the modified tree \n";
    inOrder(&root);

    std::cout << "\nDelete 30\n";
    deleteNode(root, 30);
    std::cout << "Inorder traversal of the modified tree \n";
    inOrder(&root);

    std::cout << "\nDelete 50\n";
    deleteNode(root, 50);
    std::cout << "Inorder traversal of the modified tree \n";
    inOrder(&root);

    return 0;
}