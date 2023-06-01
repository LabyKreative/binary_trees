#include "binary_trees.h"

/**
 * count_nodes - a function that counts inside a tree
 * @root:  node
 *
 * Return: count
 */

int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes((*root).left) + count_nodes((*root).right));
}


/**
 * is_complete - a function that checks if a tree is complete
 * @root: pointer to the root of the tree
 * @index: index of the node been evaluated
 * @n: num of trees node
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 */

int is_complete(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (0);

	if (index >= n)
		return (0);
	if (!(*root).left && !(*root).right)
		return (1);
	if (root->right && !(*root).left)
		return (0);
	if ((*root).left && !(*root).right)
		return (is_complete((*root).left, index * 2 + 1, n));

	return (is_complete((*root).left, index * 2 + 1, n) &&
		is_complete((*root).right, index * 2 + 2, n));
}

/**
 * binary_tree_is_complete - a function that checks if
 * a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: if tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nod;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	nod = count_nodes(root);

	return (is_complete(root, 0, nod));
}
