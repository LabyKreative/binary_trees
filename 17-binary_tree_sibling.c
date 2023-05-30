#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the siblings of a node
 * @node: is a pointer to the node to find the sibling
 *
 * Return: if node is NULL or the parent is NULL, return NULL
 * if node has no sibling, return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if ((*node).parent->left == node)
		return ((*node).parent->right);

	if ((*node).parent->right == node)
		return ((*node).parent->left);

	return (NULL);
}
