#include "binary_trees.h"
/**
 * binary_tree_rotate_left - do left rotation of the tree
 *
 * @tree: the binary tree
 *
 * Return: the new root of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	tree->parent = tree->right;

	if (tree->right)
	{
		tree->right = tree->right->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;

		if (tree->right)
			tree->right->parent = tree;
		return (tree->parent);
	}
	return (tree);
}
