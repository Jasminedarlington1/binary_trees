#include "binary_trees.h"
/**
 * binary_tree_node - creates the binary tree node
 * @parent: a pointer to parent node of the node to create
 * @value: the value to put in the new node
 * Return: the binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	temp = malloc(sizeof(binary_tree_t));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp->n = value;
	temp->left = NULL;
	temp->parent = parent;
	temp->right = NULL;

	return (temp);
}
