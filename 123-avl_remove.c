#include "binary_trees.h"

/* Function to get the height of a tree */
int height(avl_t *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

/* Function to get the maximum of two integers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/* Function to perform a right rotation */
avl_t *rotate_right(avl_t *y)
{
    avl_t *x = y->left;
    avl_t *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/* Function to perform a left rotation */
avl_t *rotate_left(avl_t *x)
{
    avl_t *y = x->right;
    avl_t *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/* Function to get the balance factor of a node */
int get_balance(avl_t *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

/**
 * avl_remove - a function that removes a node from an AVL tree
 *
 * @root: is a pointer to the root node of the tree for removing a node
 * @value: is the value to remove in the tree
 * Return: pointer to the new root node of the tree after removing
 * the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        /* Node with the value to be deleted found */
        if ((root->left == NULL) || (root->right == NULL))
        {
            avl_t *temp = root->left ? root->left : root->right;

            /* No child or one child case */
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            /* Node with two children */
            avl_t *temp = root->right;

            while (temp->left != NULL)
                temp = temp->left;

            root->n = temp->n;
            root->right = avl_remove(root->right, temp->n);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);

    /* Left Left Case */
    if (balance > 1 && get_balance(root->left) >= 0)
        return rotate_right(root);

    /* Left Right Case */
    if (balance > 1 && get_balance(root->left) < 0)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    /* Right Right Case */
    if (balance < -1 && get_balance(root->right) <= 0)
        return rotate_left(root);

    /* Right Left Case */
    if (balance < -1 && get_balance(root->right) > 0)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}
