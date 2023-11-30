#include "binary_trees.h"

/**
 * binary_tree_is_full - checks binary tree is full
 *
 * @tree: the binary tree
 * Return: 0 if null, 1 if full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int temp = 1;

	if (!tree)
		return (0);

	if ((tree->right && tree->left) || (!tree->right && !tree->left))
		temp *= 1;

	else
		temp *= 0;

	if (tree->right)
		temp *= binary_tree_is_full(tree->right);

	if (tree->left)
		temp *= binary_tree_is_full(tree->left);

	return (temp);
}
