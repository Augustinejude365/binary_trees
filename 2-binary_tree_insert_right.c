#include "binary_trees.h"

/**
 * binary_tree_insert_right - A function that inserts a node as the
 * right-child of another node
 * @parent: Pointer to the parent node of the node to be created
 * @value: Value to put in the newly created node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);

	node = binary_tree_node(parent, value);

	if (node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		parent->right->parent = node;
		node->right = parent->right;
	}

	parent->right = node;

	return (node);
}
