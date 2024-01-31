#include "binary_trees.h"

/**
 * binary_tree_leaves - A function that counts the leaves in a
 * binary tree.
 * @tree: A pointer to the root node of the tree whose leaves are
 * to be counted.
 * *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t bt_leaves = 0;

	if (tree)
	{
		bt_leaves += (!tree->left && !tree->right) ? 1 : 0;
		bt_leaves += binary_tree_leaves(tree->left);
		bt_leaves += binary_tree_leaves(tree->right);
	}
	return (bt_leaves);
}
