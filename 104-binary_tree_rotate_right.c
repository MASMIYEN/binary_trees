#include "binary_trees.h"
/**
 * binary_tree_rotate_right - do right rotation of the tree
 *
 * @tree: the binary tree
 *
 * Return: the new root of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	tree->parent = tree->left;

	if (tree->left)
	{
		tree->left = tree->left->right;
		tree->parent->right = tree;
		tree->parent->parent = NULL;

		if (tree->left)
			tree->left->parent = tree;
		return (tree->parent);
	}
	return (tree);
}
