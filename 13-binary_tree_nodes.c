#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in bt
 * @tree: pointer to the root node of the tree to count
 * Description: if tree is NULL, the function must return 0
 * A NULL pointer is not a node
 *
 * Return: nodes or 0 on failure
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
