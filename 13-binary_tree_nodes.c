#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that counts the nodes with
 * at least 1 child in a binary tree
 * @tree: is a pointer to the root node of the tree to
 * count the number of nodes
 *
 * Return: if tree is NULL, the function must return 0
 * a NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t child = 0;

	if (!tree)
		return (0);

	if ((*tree).left || (*tree).right)
		child += 1;
	if ((*tree).left)
		child += binary_tree_nodes((*tree).left);
	if ((*tree).right)
		child += binary_tree_nodes((*tree).right);
	return (child);
}
