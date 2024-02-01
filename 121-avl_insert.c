#include "binary_trees.h"

/**
 * bst_insert - A function that inserts a value in a Binary Search
 * Tree
 * @tree: A double pointer to the root node of the BST where the
 * value will be inserted
 * @value: the value to be stored in the node
 * Return: A pointer to the newly created node
 * Or NULL if it fails
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = *tree;
	bst_t *second = NULL;
	bst_t *new = binary_tree_node(NULL, value);

	if (*tree == NULL)
		*tree = new;

	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}

/**
 * avl_insert - A function that inserts a value in an AVL Tree
 * @tree: A pointer to the root node of the AVL tree
 * @value: The value to be inserted
 * Return: A pointer to the newly created node
 * Or NULL upon failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance_avl = 0;
	avl_t *new_node = bst_insert(tree, value);

	balance_avl = binary_tree_balance(*tree);

	if (balance_avl > 1 && value < new_node->left->n)
		return (binary_tree_rotate_right(new_node));
	if (balance_avl < -1 && value > new_node->right->n)
		return (binary_tree_rotate_left(new_node));
	if (balance_avl > 1 && value > new_node->left->n)
	{
		new_node->left = binary_tree_rotate_left(new_node->left);
		return (binary_tree_rotate_right(new_node));
	}
	if (balance_avl < -1 && value < new_node->right->n)
	{
		new_node->right = binary_tree_rotate_right(new_node->right);
		return (binary_tree_rotate_left(new_node));
	}

	return (new_node);
}
