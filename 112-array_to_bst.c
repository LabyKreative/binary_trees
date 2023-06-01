#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 *
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 * if a value of the array is already present in the tree, ignored
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t lenght;
	bst_t *tree = NULL;

	for (lenght = 0; lenght < size; lenght++)
		bst_insert(&tree, array[lenght]);

	return (tree);
}
