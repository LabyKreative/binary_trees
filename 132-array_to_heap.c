#include "binary_trees.h"

/**
 * array_to_heap - a function that builds a Max Binary Heap tree
 * from an array
 *
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t x;
	heap_t *root = NULL;

	if (!array)
		return (NULL);

	root = heap_insert(&root, array[0]);
	for (x = 1; x < size; x++)
		heap_insert(&root, array[x]);

	return (root);
}
