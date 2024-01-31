#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that rotates to the left, the
 * binary tree.
 * @tree: pointer to The root node of the binary three
 * Return: Upon success, Pointer to the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left != NULL)
	{
		pivot->left->parent = tree;
	}
	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	return (pivot);
}
