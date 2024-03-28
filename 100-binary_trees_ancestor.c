#include "binary_trees.h"

/**
 * binary_trees_ancestro - finds the lowes common ancestor of bt
 * @first: pointer to first node to find the ancestor
 * @second: pointer to the second node to find the ancestor
 *
 * Return: pointer to ancestor node or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *fanc, *sec;

	for (fanc = first; fanc; fanc = fanc->parent)
		for (sec = second; sec; sec = sec->parent)
			if (fanc == sec)
				return ((binary_tree_t *)fanc);
	return (NULL);
}
