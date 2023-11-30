#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 *
 * Return: nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* 	return if node is null */
	if (tree == NULL)
		return;

	/* 	recursively delete the left subtreees */
	binary_tree_delete(tree->left);
	/* 	recursively delete the right subtreees if has no left */
	binary_tree_delete(tree->right);
	/* 	free the node if it has no children */
	free(tree);
}
