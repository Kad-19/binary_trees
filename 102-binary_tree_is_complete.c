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
	size_t size;

	if (!tree)
		return (0);
	size = _size(tree);

	return (_checker(tree, 0, size));
}

/**
 * _checker - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 or 0
 */

int _checker(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (0);

	if (index >= size)
		return (0);

	return (_checker(tree->left, 2 * index + 1, size) &&
		_checker(tree->right, 2 * index + 2, size));
}
