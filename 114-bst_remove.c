#include "binary_trees.h"

/**
 * _min - finds minimum root
 * @root: pointer to bt
 * Return: min root
 */

bst_t *_min(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent;

	if (!root)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(temp);
		}
		else
		{
			temp = _min(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
