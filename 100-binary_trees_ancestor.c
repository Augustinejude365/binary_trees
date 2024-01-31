#include "binary_trees.h"

/**
 * binary_trees_ancestor - A function that finds the lowest common
 * ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common
 * ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *moma, *papa;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	moma = first->parent, papa = second->parent;
	if (first == papa || !moma || (!moma->parent && papa))
		return (binary_trees_ancestor(first, papa));
	else if (moma == second || !papa || (!papa->parent && moma))
		return (binary_trees_ancestor(moma, second));
	return (binary_trees_ancestor(moma, papa));
}
