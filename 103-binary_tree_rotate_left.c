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
	if (tree == NULL || tree->right)
		return (NULL);

	binary_tree_t *right_child = tree->right;

	tree->right = right_child->left;

	if (right_child->left)
		right_child->left->parent = tree;

	right_child->parent = tree->parent;

	if (tree->parent)
	{
		if (tree->parent->left == tree)
			tree->parent->left = right_child;
		else
			tree->parent->right = right_child;
	}
	right_child->left = tree;
	tree->parent = right_child;

	return (right_child);
}
