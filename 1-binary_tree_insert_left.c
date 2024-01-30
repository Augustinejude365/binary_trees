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
	if (parent == NULL)
	{
		return NULL;
	}

	binary_tree_t *new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return NULL; /* Memory allocation failed*/
	}

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;

	return new_node;
}
