#include "binary_trees.h"

size_t max_depth(const binary_tree_t *node);

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @d: depth of the tree
 * @level: level of the tree
 *
 *	Return: 1 if tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (d == level);

	return (is_complete(tree->left, d, level + 1) &&
		is_complete(tree->right, d, level + 1));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int d = max_depth(tree);

	if (!tree)
		return (0);

	return (is_complete(tree, d, 1));
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

	size_t left_depth = max_depth(node->left);
	size_t right_depth = max_depth(node->right);

	return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

/* size_t max_depth(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (1 + max_depth(node->left) > 1 + max_depth(node->right)
		    ? 1 + max_depth(node->left)
		    : 1 + max_depth(node->right));

} */
