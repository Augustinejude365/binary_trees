#include "binary_trees.h"

/**
 * array_to_avl - A function that builds an AVL tree from an array
 * @array: A pointer to the first element of the array to be
 * converted
 * @size: the number of element in the array
 * Return: A pointer to the root node of the created AVL tree
 * Or NULL upon failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root_node = NULL;
	size_t k, m;

	if (array == NULL)
		return (NULL);

	for (k = 0; k < size; k++)
	{
		for (m = 0; m < k; m++)
		{
			if (array[m] == array[k])
				break;
		}
		if (m == k)
		{
			if (avl_insert(&root_node, array[k]) == NULL)
				return (NULL);
		}
	}

	return (root_node);
}
