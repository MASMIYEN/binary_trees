#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	if (node->parent)
		node = node->parent;

	if (node->parent)
	{

		if (node->parent->left == node)
		{
			return (node->parent->right);
		}
		else
		{
			return (node->parent->left);
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
