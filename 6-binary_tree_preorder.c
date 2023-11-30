#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tmp;

	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	tmp = (binary_tree_t *)tree;
	binary_tree_preorder(tmp->left, func);
	binary_tree_preorder(tmp->right, func);
}
