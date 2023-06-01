#include "binary_trees.h"

/**
 * isBST - a function that compare node
 *
 * @tree: pointer to the root node of the tree to check
 * @min: value
 * @max: value
 *
 * Return: 1 if success, 0 otherwise
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if ((*tree).n < min || (*tree).n > max)
		return (0);

	return (
		isBST((*tree).left, min, (*tree).n - 1) &&
		isBST((*tree).right, (*tree).n + 1, max)
	);
}

/**
 * binary_tree_is_bst - a function that checks if a binary tree
 * is a valid Binary Search Tree
 *
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * if tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isBST(tree, INT_MIN, INT_MAX));
}
