#include "binary_trees.h"
/**
  * binary_tree_is_full - func that checks to see if a tree is
  * filled
  * @tree: tree to measure
  * Return: 1 if full, 0 if not full.
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left && tree->right)
	{
		if (binary_tree_is_full(tree->right) != 1)
			return (0);
		if (binary_tree_is_full(tree->left) != 1)
			return (0);
	}
	if ((tree->right && !tree->left) || (!tree->right && tree->left))
		return (0);
	else
		return (1);
}
