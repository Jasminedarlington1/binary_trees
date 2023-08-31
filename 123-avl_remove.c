#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value);

/**
 * avl_remove - it will remove the node from an AVL tree
 * @root: a pointer to the root node of the tree for removing a node
 * @value: value to be removed in the tree
 * Return: pointer to the new root node of the tree after removing
 *  the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int bal = 0, balance_prev = 0, val;
	avl_t *remove_me = NULL;
	avl_t *parent = NULL;
	avl_t *aux = NULL;

	remove_me = bst_search(root, value);
	if (remove_me == NULL)
		return (root);
	parent = remove_me->parent;

	if (remove_me->left == NULL && remove_me->right == NULL)
	{
		if (remove_me->parent == NULL)
			root = NULL;
		else if (remove_me == remove_me->parent->left)
			remove_me->parent->left = NULL;
		else if (remove_me == remove_me->parent->right)
			remove_me->parent->right = NULL;
		free(remove_me);
	}
	else if (remove_me->left != NULL && remove_me->right == NULL)
	{
		if (remove_me->parent == NULL)
			root = remove_me->left;
		else if (remove_me == remove_me->parent->left)
			remove_me->parent->left = remove_me->left;
		else if (remove_me == remove_me->parent->right)
			remove_me->parent->right = remove_me->left;
		remove_me->left->parent = remove_me->parent;
		free(remove_me);
	}
	else if (remove_me->left == NULL && remove_me->right != NULL)
	{
		if (remove_me->parent == NULL)
			root = remove_me->right;
		else if (remove_me == remove_me->parent->left)
			remove_me->parent->left = remove_me->right;
		else if (remove_me == remove_me->parent->right)
			remove_me->parent->right = remove_me->right;
		remove_me->right->parent = remove_me->parent;
	}
	else if (remove_me->left != NULL && remove_me->right != NULL)
	{
		aux = remove_me->right;
		while (aux->left != NULL)
			aux = aux->left;
		val = aux->n;

		avl_remove(root, val);
		remove_me->n = val;
	}
	if (parent != NULL)
		aux = parent;
	else
		aux = root;
	while (aux != NULL)
	{
		balance_prev = bal;
		bal = binary_tree_balance(aux);
		if (bal > 1)
		{
			if (balance_prev < 0)
				binary_tree_rotate_left(aux->left);
			aux = binary_tree_rotate_right(aux);
		}
		else if (bal < -1)
		{
			if (balance_prev > 0)
				binary_tree_rotate_right(aux->right);
			aux = binary_tree_rotate_left(aux);
		}
		if (aux->parent == NULL)
			root = aux;

		aux = aux->parent;
	}
	return (root);
}
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node, or return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		return (NULL);
	}
	while (1)
	{
		if (tree->n == value)
		{
			return ((bst_t *)tree);
		}
		if (tree->right != NULL && value > tree->n)
		{
			tree = tree->right;
		}
		else if (tree->left != NULL && value < tree->n)
		{
			tree = tree->left;
		}
		else
			return (NULL);
	}
}
