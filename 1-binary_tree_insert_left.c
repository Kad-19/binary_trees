#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert left child to the node
 * @parent: parent node
 * @value: value to be inserted
 * Return: pointer to created node or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newleft;

	if (!parent)
		return (NULL);

	newleft = malloc(sizeof(binary_tree_t));

	if (!newleft)
		return (NULL);

	newleft->n = value;
	newleft->parent = parent;
	newleft->right = NULL;
	newleft->left = parent->left;
	parent->left = newleft;

	if (newleft->left)
		newleft->left->parent = newleft;

	return (newleft);
}
