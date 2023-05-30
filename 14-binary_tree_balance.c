#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures
 * the height of a binary tree
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
	if ((*tree).left || (*tree).right)
	{
		b1 = binary_tree_height((*tree).left);
		br = binary_tree_height((*tree).right);
		return (1 + (br > b1 ? br : b1));
	}
	return (0);
}

/**
 * binary_tree_balance - a function that measures
 * the balance factor of a binary tree
 * @tree: is a pointer to the root node of the
 * tree to measure the balance factor
 *
 * Return: balance, if tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right, res;

	if (!tree)
		return (0);

	left = binary_tree_height((*tree).left);
	right = binary_tree_height((*tree).right);
	res = left - right;

	res -= (*tree).right ? 0 : -1;
	res += (*tree).left ? 0 : -1;
	return (res);
}
