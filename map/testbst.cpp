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
	newN->parent = NULL;
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
void	insertNode(s_node<pair_type>* newnode, pair_type value)
{
	if (!newnode)
		newnode = createNewNode(value);
	else if (value > newnode->value)
	{
		insertNode(newnode->right, value)
		newnode->right->parent = newnode;
	}
	else if (value < newnode->value)
	{
		insertNode(newnode->left, value);
		newnode->left->parent = newnode;
	}
}
