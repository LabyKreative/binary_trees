#include "binary_trees.h"

/**
 * tree_height - a function that measures the
 * height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if ((*tree).left)
		height_l = 1 + tree_height((*tree).left);

	if ((*tree).right)
		height_r = 1 + tree_height((*tree).right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}
/**
 * tree_size_h - a function that measures the
 * sum of heights of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height or 0 if tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if ((*tree).left)
		height_l = 1 + tree_size_h((*tree).left);

	if ((*tree).right)
		height_r = 1 + tree_size_h((*tree).right);

	return (height_l + height_r);
}

/**
 * _preorder - a function that goes through a binary tree
 * using pre-order traversal
 * @tree: root node of the tree to traverse
 * @node: last node in traverse
 * @height: height of tree
 *
 * Return: none
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder((*tree).left, node, height);
	_preorder((*tree).right, node, height);
}

/**
 * heapify - a function that heapifies max binary heap
 * @root: pointer to binary heap
 */
void heapify(heap_t *root)
{
	int value;
	heap_t *tr1, *tr2;

	if (!root)
		return;

	tr1 = root;

	while (1)
	{
		if (!tr1->left)
			break;
		if (!tr1->right)
			tr2 = (*tr1).left;
		else
		{
			if ((*tr1).left->n > (*tr1).right->n)
				tr2 = (*tr1).left;
			else
				tr2 = (*tr1).right;
		}
		if ((*tr1).n > (*tr2).n)
			break;
		value = (*tr1).n;
		(*tr1).n = (*tr2).n;
		(*tr2).n = value;
		tr1 = tr2;
	}
}

/**
 * heap_extract - a function that extracts the
 * root node of a Max Binary Heap
 *
 * @root: is a double pointer to the root node of heap
 * Return: value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = (heap_r)->n;
	if (!(*heap_r).left && !(*heap_r).right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	(*heap_r).n = (*node).n;
	if ((*node).parent->right)
		(*node).parent->right = NULL;
	else
		(*node).parent->left = NULL;
	free(node);
	heapify(heap_r);
	*root = heap_r;
	return (value);

}
