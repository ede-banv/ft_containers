template < class pair_type >
struct s_node {
	pair_type	value;
	struct node* left;
	struct node* right;
	struct node* parent;

};

template < class pair_type >
s_node<pair_type>*	createNewNode(pair_type value)
{
	s_node<pair_type>* newN;

	newN->value = value;
	newN->left = NULL;
	newN->right = NULL;
	newN->parent = NULL; //is the reverse direction needed?
	return (newN)
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

template < class pair_type>
bool	insertNode(s_node<pair_type>** root, pair_type value)
{
	if (!*root)
	{
		*root = createNewNode(value);
		return (true);
	}
	else if (*root->value == value)
		return (true);
	else if (value > *root->value)
	{
		insertNode(&root->right, value)
		*root->right->parent = *root;
		return (true);
	}
	else if (value < *root->value)
	{
		insertNode(&root->left, value);
		*root->left->parent = *root;
		return (true);
	}
	return (false);
}
