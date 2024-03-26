#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Description - The value in the node must be passed
 * as a parameter to this function.
 * If tree or func is NULL, do nothing
 * Return: Nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL  || func == NULL)
		return;

	/*traverse the left subtree first*/
	binary_tree_inorder(tree->left, func);

	/*visit the root node (second step in inorder traversal)*/
	func(tree->n);

	/* last step is to taverse the right subtree*/
	binary_tree_inorder(tree->right, func);
}
