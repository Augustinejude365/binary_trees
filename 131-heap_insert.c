#include "binary_trees.h"

/**
 * binary_tree_nodes - A function that counts the nodes with at least
 * 1 child in a binary tree.
 * @tree: A pointer to the root node of the binary tree to count
 * the number of nodes.
 * *
 * Return: If tree is NULL, return 0, otherwise return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num_nodes = 0;
	if (tree)
	{
		num_nodes += (tree->left || tree->right) ? 1 : 0;
		num_nodes += binary_tree_nodes(tree->left);
		num_nodes += binary_tree_nodes(tree->right);
	}
	return (num_nodes);
}

/**
 * heap_insert - A function that inserts a value in Max Binary Heap
 * @root: A double pointer to the root node of the Heap where the
 * value will be inserted
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the newly created node or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - A function that measures the size of a binary
 * tree
 * @tree: A pointer to the tree whose size is to be measured
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
