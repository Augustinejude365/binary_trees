#include "binary_trees.h"

/**
 * array_to_bst - A function that builds a binary search (BST) tree
 * from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the @array.
 * Return: A pointer to the root node of the created BST, or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *bs_tree = NULL;
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
			if (bst_insert(&bs_tree, array[k]) == NULL)
				return (NULL);
		}
	}

	return (bs_tree);
}
