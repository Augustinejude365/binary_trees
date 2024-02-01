#include "binary_trees.h"

/**
 * tree_height - A function that measures the height of a binary tree
 * @tree: A pointer to the root node of the tree whose height is
 * to be measured
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_lf = 0;
	size_t height_rt = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lf = 1 + tree_height(tree->left);

	if (tree->right)
		height_rt = 1 + tree_height(tree->right);

	if (height_lf > height_rt)
		return (height_lf);
	return (height_rt);
}

/**
 * tree_size_h - A function that measures the sum of heights of
 * a binary tree
 * @tree: A pointer to the root node of the tree whose height is to
 * be measured
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_lf = 0;
	size_t height_rt = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lf = 1 + tree_size_h(tree->left);

	if (tree->right)
		height_rt = 1 + tree_size_h(tree->right);

	return (height_lf + height_rt);
}

/**
 * _preorder - A function that goes through a binary tree using
 * pre-order traversal
 * @tree: A pointer to the root node of the tree to be traversed
 * @node: A pointer to the last node to be traversed
 * @height: height of the tree
 * Return: Nothing
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heapify - A function that heapifies max binary heap
 * @root: pointer to binary heap
 * Return: Nithing
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tmp1, *tmp2;

	if (!root)
		return;

	tmp1 = root;

	while (1)
	{
		if (!tmp1->left)
			break;
		if (!tmp1->right)
			tmp2 = tmp1->left;
		else
		{
			if (tmp1->left->n > tmp1->right->n)
				tmp2 = tmp1->left;
			else
				tmp2 = tmp1->right;
		}
		if (tmp1->n > tmp2->n)
			break;
		value = tmp1->n;
		tmp1->n = tmp2->n;
		tmp2->n = value;
		tmp1 = tmp2;
	}
}

/**
 * heap_extract - A function that extracts the root node of a Max
 * Binary Heap
 * @root: A double pointer to the root node of the heap
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_rt, *node;

	if (!root || !*root)
		return (0);
	heap_rt = *root;
	value = heap_rt->n;
	if (!heap_rt->left && !heap_rt->right)
	{
		*root = NULL;
		free(heap_rt);
		return (value);
	}

	_preorder(heap_rt, &node, tree_height(heap_rt));

	heap_rt->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify(heap_rt);
	*root = heap_rt;
	return (value);
}
