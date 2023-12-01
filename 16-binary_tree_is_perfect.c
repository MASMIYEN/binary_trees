#include "binary_trees.h"

size_t max_depth(const binary_tree_t *node);

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @d: maximum depth of the tree
 * @level: level of the tree
 *
 * Return: 1 if tree is perfect, otherwise 0
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (d == level);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect(tree->left, d, level + 1) &&
		is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = max_depth(tree);

	return (is_perfect(tree, d, 1));
}

/**
 * max_depth - measures the maximum depth of a node in a binary tree
 * @node: pointer to the node to measure the depth
 *
 * Return: maximum depth of the node
 */
size_t max_depth(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (1 + max_depth(node->left) > 1 + max_depth(node->right)
		    ? 1 + max_depth(node->left)
		    : 1 + max_depth(node->right));
}
