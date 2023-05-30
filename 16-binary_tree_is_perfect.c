#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the
 * height of a binary tree
 * @tree: is a pointer to the root node of the tree
 * to measure the height
 *
 * Return: height, if tree is NULL, return 0
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

/**
 * binary_tree_is_full - a function that checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: full, if tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!(*tree).left && !(*tree).right)
		return (1);
	if ((*tree).left && (*tree).right)
		return (binary_tree_is_full((*tree).right) &&
				binary_tree_is_full((*tree).left));
	return (0);
}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: if tree is NULL, otherwise return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!(*tree).left && !(*tree).right)
		return (1);
	if ((*tree).left && (*tree).right)
		if (binary_tree_height((*tree).left) ==
				binary_tree_height((*tree).right))
			return (binary_tree_is_perfect((*tree).left) &&
					binary_tree_is_perfect((*tree).right));
	return (0);
}
