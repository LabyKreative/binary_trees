#include "binary_trees.h"
/**
 * min_finder - a function that finds the minimum root
 * @root: pointer to the tree
 * Return: minimum root
 */

bst_t *min_finder(bst_t *root)
{
	while ((*root).left != NULL)
		root = (*root).left;
	return (root);
}

/**
 * bst_remove -  a function that removes a node from a Binary Search Tree
 *
 * @root: is a pointer to the root node of the tree
 * where you will remove a node
 * @value: is the value to remove in the tree
 * Return: if the node to be deleted has two children,
 * it must be replaced with its first in-order successor (not predecessor)
 * return a pointer to the new root node of the tree
 * after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		(*root).left = bst_remove((*root).left, value);
	else if (value > (*root).n)
		(*root).right = bst_remove((*root).right, value);
	else
	{
		if ((*root).left == NULL && (*root).right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if ((*root).left == NULL)
		{
			temp = root;
			parent = (*root).parent;
			root = (*root).right;
			(*root).parent = parent;
			free(temp);
		}
		else if ((*root).right == NULL)
		{
			temp = root;
			parent = (*root).parent;
			root = (*root).left;
			(*root).parent = parent;
			free(temp);
		}
		else
		{
			temp = min_finder((*root).right);
			(*root).n = (*temp).n;
			(*root).right = bst_remove((*root).right, (*temp).n);
		}
	}
	return (root);
}
