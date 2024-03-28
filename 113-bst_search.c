#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: A pointer to the node containing an int equal to `value`
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *curr = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (curr)
	{
		if (value == curr->n)
			return (curr);
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
	}

	return (NULL);
}
