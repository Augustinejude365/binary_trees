#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - A function that measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree whose height is to
 * be measured
 * Return: If tree is NULL, return 0, otherwise return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lf = 0, rt = 0;

		lf = tree->left ? 1 + height(tree->left) : 1;
		rt = tree->right ? 1 + height(tree->right) : 1;
		return ((lf > rt) ? lf : rt);
	}
	return (0);
}

/**
 * is_avl_helper - A function that checks if a binary tree is a
 * valid AVL tree.
 * @tree: A pointer to the root node of the tree to be checked.
 * @lo: The value of the smallest node checked thus far.
 * @hi: The value of the largest node checked so far.
 * Return: If the tree is a valid AVL tree, 1, else, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lf_hgt, rt_hgt, dif_hgt;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lf_hgt = height(tree->left);
		rt_hgt = height(tree->right);
		dif_hgt = lf_hgt > rt_hgt ? lf_hgt - rt_hgt : rt_hgt - lf_hgt;
		if (dif_hgt > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
				is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - A function that checks if a binary tree is
 * a valid AVL tree.
 * @tree: A pointer to the root node of the tree to be checked.
 * Return: 1 if tree is a valid AVL tree, and 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
