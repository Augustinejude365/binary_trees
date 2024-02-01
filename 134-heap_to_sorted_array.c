#include "binary_trees.h"

/**
 * tree_size - A function that measures the sum of heights of a
 * binary tree
 * @tree: A pointer to the root node of the tree whose height is to
 * be measured
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_lf = 0;
	size_t height_rt = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_lf = 1 + tree_size(tree->left);

	if (tree->right)
		height_rt = 1 + tree_size(tree->right);

	return (height_lf + height_rt);
}

/**
 * heap_to_sorted_array - A function that converts a Binary Max Heap
 * into a sorted array of integers
 * @heap: A pointer to the root node of the heap to convert
 * @size: An address to store the size of the array
 * Return: The generated array, NULL upon failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int k, *array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	for (k = 0; heap; k++)
		array[k] = heap_extract(&heap);

	return (array);
}
