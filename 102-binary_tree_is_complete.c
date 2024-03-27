#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 or 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag = 0;
	const binary_tree_t *stack[10000];
	const binary_tree_t *node;
	int top = -1;

	if (!tree)
		return (0);

	/* push root node to stack */
	stack[++top] = tree;

	/* lets perform depth-first traversal */
	while (top >= 0)
	{
		node = stack[top--];


		if (node == NULL)
		{
			flag = 1;
		}
		else
		{
			/**
			 * if we encountered NUll node before, and current node is not null,
			 * the tree is not complete
			 */
			if (flag)
				return (0);

			/* push the right and left children onto stack */
			stack[++top] = node->right;
			stack[++top] = node->left;
		}
	}

	/* if we reach here, tree is complete :) */
	return (1);
}
