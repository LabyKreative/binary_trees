#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node
 * as the right-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node,
 * or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	(*new).n = value;
	(*new).parent = parent;
	(*new).right = NULL;
	(*new).left = NULL;
	if ((*parent).right)
	{
		(*new).right = (*parent).right;
		(*parent).right->parent = new;
	}
	(*parent).right = new;
	return (new);
}
