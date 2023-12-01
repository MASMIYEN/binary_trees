#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);

	tmp = (binary_tree_t *)second;
	while (first)
	{
		second = tmp;
		while (second)
		{
			if (second->n == first->n)
				return (binary_tree_t *)first;
			second = second->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
