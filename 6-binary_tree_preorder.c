#include "binary_trees.h"

/**
 * binary_tree_preorder - a function that goes through a
 * binary tree using pre-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node
 *
 * Return: tree or func is NULL, do nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	(func)((*tree).n);
	if ((*tree).left)
		binary_tree_preorder((*tree).left, func);
	if ((*tree).right)
		binary_tree_preorder((*tree).right, func);
}
