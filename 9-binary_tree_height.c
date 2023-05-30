#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 *
 * Return: tree is NULL, your function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t br = 0, b1 = 0;

	if (!tree)
		return (0);
	if ((*tree).left)
	{
		b1 = binary_tree_height((*tree).left);
		b1 += 1;
	}
	if ((*tree).right)
	{
		br = binary_tree_height((*tree).right);
		br += 1;
	}
	return (br > b1 ? br : b1);
}
