#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds the
 * lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 *
 * Return: pointer to the lowest common ancestor, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor = first;

	while (ancestor != NULL)
	{
		if (binary_tree_is_ancestor(ancestor, second))
			return ((binary_tree_t *)ancestor);

		ancestor = ancestor->parent;
	}

	return (NULL);
}

/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another node
 * @node: is a pointer to the potential ancestor node
 * @target: is a pointer to the target node
 *
 * Return: 1 if @node is an ancestor of @target, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *node,
		const binary_tree_t *target)
{
	if (node == NULL)
		return (0);

	if (node == target)
		return (1);

	return (binary_tree_is_ancestor(node->left, target) ||
			binary_tree_is_ancestor(node->right, target));
}
