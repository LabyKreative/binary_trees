#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a Binary Search Tree
 *
 * @tree: is a pointer to the root node of the BST to search
 * @value: is the value to search in the tree
 * Return: pointer to the node containing a value equals to value
 * if tree is NULL or if nothing is found, return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || (*tree).n == value)
		return ((binary_tree_t *) tree);

	if (value < (*tree).n)
		return (bst_search((*tree).left, value));
	return (bst_search((*tree).right, value));
}
