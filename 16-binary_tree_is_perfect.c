#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 if the tree is not perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t nodes = 0;
	size_t power = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	power = (size_t)pow(2, height + 1);
	return (power - 1 == nodes);
}

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
