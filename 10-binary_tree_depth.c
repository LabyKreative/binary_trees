#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth
 * of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 *
 * Return: if tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	if ((*tree).parent)
	{
		depth = binary_tree_depth((*tree).parent);
		depth += 1;
	}
	return (depth);
}
