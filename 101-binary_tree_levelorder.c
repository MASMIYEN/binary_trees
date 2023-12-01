#include "binary_trees.h"
#include <stddef.h>

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * binary_tree_level - goes through a binary tree by level
 * @tree: pointer to the root node of the tree to traverse
 * @level: level of the tree
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, size_t level,
		       void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	if (level > 1)
	{
		binary_tree_level(tree->left, level - 1, func);
		binary_tree_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree by level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree || !func)
		return;

	h = height(tree);
	for (i = 1; i <= h; i++)
		binary_tree_level(tree, i, func);
}
