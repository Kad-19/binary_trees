#include "binary_trees.h"


/**
 * max - return maximum by comparing two heights
 * @a: first number
 * @b: second number
 * Return: maximum
 */

size_t max(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

/**
 * binary_tree_height - measures the height of binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Description: if tree is NULL, function returns 0
 * Return: height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		l = binary_tree_height(tree->left);
		r = binary_tree_height(tree->right);

		return (max(l, r) + 1);
	}
	return (0);
}