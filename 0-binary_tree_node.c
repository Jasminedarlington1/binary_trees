#include "binary_trees.h"

/**
 * binary_tree_node - function creates a binary tree node
 * @parent: parameter
 * @value: value to put in the new node
 * Return: binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *t;

	t = malloc(sizeof(binary_tree_t));
	if (t == NULL)
		return (NULL);

	t->n = value;
	t->left = NULL;
	t->parent = parent;
	t->right = NULL;

	return (t);
}
