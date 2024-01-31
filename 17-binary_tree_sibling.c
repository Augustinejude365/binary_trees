#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a node
 * in a binary tree.
 * @node: A pointer to the node whose sibling is to be searched.
 * Return: If node is NULL or there is no sibling - NULL.
 * Else - a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
