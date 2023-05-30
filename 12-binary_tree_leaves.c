#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves
 * in a binary tree
 * @tree: is a pointer to the root node of the tree to
 * count the number of leaves
 *
 * Return: a NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (!tree)
		return (0);

	if ((*tree).left)
		leaf += binary_tree_leaves((*tree).left);
	if ((*tree).right)
		leaf += binary_tree_leaves((*tree).right);
	if (!(*tree).left  && !(*tree).right)
		leaf += 1;
	return (leaf);
}
