#include "binary_trees.h"

/**
 * binary_tree_delete - A function that deletes an entire  binary
 * tree.
 * @tree: A pointer to the root node of the binary tree to be delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}

	while (tree != NULL)
	{
		if (tree->left != NULL)
		{
			binary_tree_t *temp = tree->left;

			tree->left = NULL;
			tree = temp;
		}
		else if (tree->right != NULL)
		{
			binary_tree_t *temp = tree->right;

			tree->right = NULL;
			tree = temp;
		}
		else
		{
			binary_tree_t *parent = tree->parent;

			if (parent != NULL)
			{
				if (parent->left == tree)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}
			free(tree);
			tree = parent;
		}
	}
}
