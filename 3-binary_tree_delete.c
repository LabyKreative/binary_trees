#include "binary_trees.h"

/**
 * binary_tree_delete - a function that deletes an entire binary tree
 * @tree: is a pointer to the root node of the tree to delete
 *
 * Return: nothing if tree is NULL
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
	{
		return;
	}
	if ((*tree).left)
	{
		binary_tree_delete((*tree).left);
	}
	if ((*tree).right)
	{
		binary_tree_delete((*tree).right);
	}
	free(tree);
}
