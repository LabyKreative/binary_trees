#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max - a functionat that goes through a binary tree
 * checking root as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int check_max(const binary_tree_t *tree)
{
	int tr1 = 1, tr2 = 1;

	if (!tree)
		return (0);
	if (!(*tree).left && !(*tree).right)
		return (1);
	if ((*tree).left)
	{
		if ((*tree).n <= (*tree).left->n)
			return (0);
		tr1 = check_max((*tree).left);
	}
	if ((*tree).right)
	{
		if ((*tree).n <= (*tree).right->n)
			return (0);
		tr2 = check_max((*tree).right);
	}
	return (tr1 && tr2);
}

/**
 * binary_tree_is_heap - a function that checks if a binary tree
 * is a valid Max Binary Heap
 * @tree: is a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (check_max(tree));
}
