#include "binary_trees.h"

/**
 * binary_tree_balance - A function that measures the balance factor
 * of a binary tree.
 * @tree: A pointer to the root node of the tree whose balance factor
 * is to be measured.
 * *
 * Return: If tree is NULL, return 0, otherwise return balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - A function that measures the height of a
 * binary tree.
 * @tree: A pointer to the root node of the tree whose height is
 * to be measured.
 * Return: If tree is NULL, return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lf = 0, rt = 0;

		lf = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rt = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lf > rt) ? lf : rt);
	}
	return (0);
}
