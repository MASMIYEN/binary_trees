#include "binary_trees.h"
/**
 * binary_tree_insert_left -  creates a binary tree node.
 *
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULLif failed
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (!parent)
		return (NULL);

	newNode = malloc(sizeof(binary_tree_t));

	if (!newNode)
		return (NULL);

	newNode->parent = NULL;
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;

	if (parent->left)
	{
		parent->left->parent = newNode;
	}
	newNode->left = parent->left;
	parent->left = newNode;
	newNode->parent = parent;

	return (newNode);
}
