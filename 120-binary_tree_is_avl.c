#include "binary_trees.h"

/**
 * btl - a function that checks auxiliary level
 *
 * @tree: pointer to root
 * Return: integer with level
 */

int btl(const binary_tree_t *tree)
{
	int hl, hr;

	if (tree == NULL)
		return (0);
	if ((*tree).left == NULL && (*tree).right == NULL)
		return (1);
	hl = btl((*tree).left);
	hr = btl((*tree).right);
	if (hl > hr)
		return (hl + 1);
	else
		return (hr + 1);
}


/**
 * bt_balance - a function that calculate the factor
 *
 * @tree: pointer to root
 * Return: integer with factor
 */

int bt_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btl((*tree).left) - btl((*tree).right));
}

/**
 * bavl - a function that checks the level
 *
 * @tree: pointer to root
 * @min: value
 * @max: value
 * Return: 1 if is AVL, 0 otherwise
 */

int bavl(const binary_tree_t *tree, int min, int max)
{
	int bleft, bright, balance;

	if (tree == NULL)
		return (1);
	if ((*tree).n > max || (*tree).n < min)
		return (0);
	balance = bt_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	bleft = bavl((*tree).left, min, (*tree).n - 1);
	bright = bavl((*tree).right, (*tree).n + 1, max);
	if (bleft == 1 && bright == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - a function that checks if a
 * binary tree is a valid AVL Tree
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 * if tree is NULL, return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bavl(tree, INT_MIN, INT_MAX));

}
