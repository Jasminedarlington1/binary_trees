#include "binary_trees.h"

/**
 * binary_tree_node - this function creates a binary tree node
 * @parent: parameter
 * @value: value
 * Return: binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *p;

	p = malloc(sizeof(binary_tree_t));
	if (p == NULL)
		return (NULL);

	p->n = value;
	p->left = NULL;
	p->parent = parent;
	p->right = NULL;

	return (p);
}
