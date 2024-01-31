#include "binary_trees.h"

/**
 * binary_tree_height - A function that measures the height of a
 * binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, return 0, otherwise return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lf = 0, rt = 0;

		lf = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((lf > rt) ? lf : rt);
	}
	return (0);
}
