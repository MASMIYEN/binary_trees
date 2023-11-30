#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *tmp;

	size_t left_count = 0, right_count = 0;

	if (tree == NULL)
		return (0);

	tmp = (binary_tree_t *)tree;

	if (tmp->left != NULL)
		left_count = 1 + binary_tree_height(tmp->left);

	if (tmp->right != NULL)
		right_count = 1 + binary_tree_height(tmp->right);

	if (left_count >= right_count)
		return (left_count);
	else
		return (right_count);
}
