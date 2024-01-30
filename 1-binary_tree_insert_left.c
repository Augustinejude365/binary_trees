#include "binary_trees.h"

/**
 * binary_tree_insert_left - A function that inserts a node as the
 * left-child of another node
 * @parent : pointer to the parent node of the node to be created
 * @value : value to input in the newly created node
 * Return: pointer to the new node, or NULL upon failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (parent->left != NULL)
	{
		parent->left->parent = node;
		node->left = parent->left;
	}
	parent->left = node;

	return (node);
}
