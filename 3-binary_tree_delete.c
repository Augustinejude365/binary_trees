#include "binary_trees.h"

/**
 * binary_tree_delete - A function that deletes an entire  binary
 * tree.
 * @tree: A pointer to the root node of the binary tree to be delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
