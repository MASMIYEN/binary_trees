#include "binary_trees.h"

size_t depth(const binary_tree_t *node);

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @d: depth of the tree
 * @level: level of the tree
 *
 * Return: 1 if tree is perfect, otherwise 0
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (d == level + 1);

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
	int d = depth(tree);

	return (is_perfect(tree, d, 0));
}

/**
 * depth - measures the depth of a node in a binary tree
 * @node: pointer to the node to measure the depth
 *
 * Return: depth of the node, or 0 if tree is NULL
 */
size_t depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (node == NULL)
		return (0);

	while (node)
	{
		depth++;
		node = node->left;
	}

	return (depth);
}
