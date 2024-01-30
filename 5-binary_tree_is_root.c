#include "binary_trees.h"

/**
 * binary_tree_is_root - A function that checks if a node is a leaf
 * @node : pointer to the node to be checked
 * Return: 1 if the node is root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);
	else
		return (0);
}
