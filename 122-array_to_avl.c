#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure. If a value of the array is already present in the
 * tree, this value must be ignored
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t x;
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	root = avl_insert(&root, array[0]);
	for (x = 1; x < size; x++)
		avl_insert(&root, array[x]);

	return (root);
}
