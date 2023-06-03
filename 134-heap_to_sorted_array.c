#include "binary_trees.h"

/**
 * tree_size - a function that measures the sum of heights of a BT
 * @tree: pointer to the root node of the tree
 *
 * Return: height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if ((*tree).left)
		height_l = 1 + tree_size((*tree).left);

	if ((*tree).right)
		height_r = 1 + tree_size((*tree).right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - a function that converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: is a pointer to the root node of the heap to convert
 * @size: is an address to store the size of the array
 * Return: array sorted in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int x, *y = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	y = malloc(sizeof(int) * (*size));

	if (!y)
		return (NULL);

	for (x = 0; heap; x++)
		y[x] = heap_extract(&heap);

	return (y);
}
