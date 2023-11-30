#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor
 * of a binary tree
 *
 * @binary_tree_t: binary tree
 *
 * returns: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right_height, left_height;

	if (!tree)
		return (0);

	right_height = binary_tree_height(tree->right);
	left_height = binary_tree_height(tree->left);

	return (left_height - right_height);
}

size_t binary_tree_height(const binary_tree_t *tree)
{

	size_t left_count, right_count;

	if (tree == NULL)
		return (0);

	left_count = binary_tree_height(tree->left);
	right_count = binary_tree_height(tree->right);

	if (right_count > left_count)
		return (right_count + 1);
	else
		return (left_count + 1);
}
