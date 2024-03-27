#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, NULL if the node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Description: if node is NULL or parents is NULL return NULL
 * if node has no sibiling, return NULL
 *
 * Return: must return pointer to the sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	/* lets check if the given node is left or not */
	if (node->parent->left == node)
	{
		if (node->parent->right != NULL)
			return (node->parent->right);
	}
	else /* if not left sibiling, so find left sibling */
	{
		if (node->parent->left != NULL)
			return (node->parent->left);
	}
	return (NULL);
}
