#include "binary_trees.h"

/**
 * sorted_array_to_avl - A function that builds an AVL tree from
 * an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 * Return: A pointer to the root node of the created AVL tree
 * Or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);

	sata_helper(&tree, array, -1, middle);
	sata_helper(&tree, array, middle, size);

	return (tree);
}

/**
 * sata_helper - A function that helps build an AVL tree from
 * an array
 * @root: A double pointer to the root node of the subtree
 * @array: A pointer to the first element of the array to be
 * converted
 * @lo: The lower bound index
 * @hi: The upper bound index
 */
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = new;
		else if (array[middle] < (*root)->n)
			(*root)->left = new;
		sata_helper(&new, array, lo, middle);
		sata_helper(&new, array, middle, hi);
	}
}
