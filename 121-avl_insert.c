#include "binary_trees.h"

bst_t *bst_insert(bst_t **tree, int value);
/**
 * avl_insert - will inserts the value in an AVL Tree
 * @value: value to store in the node
 * @tree: a double pointer to the root node of the AVL tree
 * Return:  pointer to created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;
	avl_t *aux = NULL;
	int balance, balance_prev = 0;

	new = bst_insert(tree, value);
	aux = new;
	while (aux != NULL)
	{
		balance_prev = balance;
		balance = binary_tree_balance(aux);
		if (balance > 1)
		{
			if (balance_prev < 0)
				binary_tree_rotate_left(aux->left);
			aux = binary_tree_rotate_right(aux);
		}
		else if (balance < -1)
		{
			if (balance_prev > 0)
				binary_tree_rotate_right(aux->right);
			aux = binary_tree_rotate_left(aux);
		}
		if (aux->parent == NULL)
			*tree = aux;

		aux = aux->parent;
	}
	return (new);
}
/**
 * bst_insert - will insert a value in a Binary Search Tree
 * @value: the value to store in the node to be inserted
 * @tree: double pointer to root node of the BST to insert the value
 * Return: pointer, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *aux = NULL;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	aux = *tree;
	while (1)
	{
		if (aux->n == value)
			return (NULL);
		if (value > aux->n)
		{
			if (aux->right != NULL)
				aux = aux->right;
			else
			{
				aux->right = binary_tree_node(aux, value);
				return (aux->right);
			}
		}
		else
		{
			if (aux->left != NULL)
				aux = aux->left;
			else
			{
				aux->left = binary_tree_node(aux, value);
				return (aux->left);
			}
		}
	}
}
