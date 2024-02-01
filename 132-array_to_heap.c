#include "binary_trees.h"

/**
 * array_to_heap - A function that builds a Max Binary Heap tree
 * from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of element in the array
 * Return: A pointer to the root node of the created Binary Heap
 * Or NULL upon failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int k;
	heap_t *root_node = NULL;

	for (k = 0; k < size; k++)
		heap_insert(&root_node, array[k]);

	return (root_node);
}
