#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Description: if tree is NULL, function returns 0
 * Return: size.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
		return (0);

	l = binary_tree_size(tree->left);
	r = binary_tree_size(tree->right);

	return (l + r + 1);
}
