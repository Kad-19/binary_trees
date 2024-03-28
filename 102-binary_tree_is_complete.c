#include "binary_trees.h"

/**
 * _size - measure size of binary tree
 * @tree: tree to be measured
 * Return: size or NUll at fail
 */

size_t _size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_size(tree->left) + _size(tree->right) + 1);
}
/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size;
	binary_tree_t *r;

	if (!tree)
		return (0);

	r = (binary_tree_t *)tree;
	size = _size(r);

	return (_checker(r, 0, size));
}

/**
 * _checker - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 or 0
 */

int _checker(const binary_tree_t *tree, int index, int size)
{
	if (!tree)
		return (0);

	if (index >= size)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (tree->right && !tree->left)
		return (0);
	if (tree->left && !tree->right)
		return (_checker(tree->left, index * 2 + 1, size));

	return (_checker(tree->left, index * 2 + 1, size) &&
		_checker(tree->right, index * 2 + 2, size));
}
