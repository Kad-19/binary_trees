#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse a binary tree in level-order
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, max;

	if (!tree || !func)
		return;

	max = binary_tree_height(tree) + 1;

	for (i = 1; i <= max; i++)
		traverse(tree, func, i);
}

/**
 * traverse - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void traverse(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		traverse(tree->left, func, level - 1);
		traverse(tree->right, func, level - 1);
	}
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
