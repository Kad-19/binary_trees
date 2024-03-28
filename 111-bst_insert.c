#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *curr = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		curr = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (curr == NULL)
		curr = new;
	else if (value < curr->n)
	{
		curr->left = new;
		new->parent = curr;
	}
	else
	{
		curr->right = new;
		new->parent = curr;
	}

	return (new);
}
