#include "binary_trees.h"
#include "limits.h"
/**
 * height - will measure the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: return 0 if NULL, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t m = 0, s = 0;

		m = tree->left ? 1 + height(tree->left) : 1;
		s = tree->right ? 1 + height(tree->right) : 1;
		return ((m > s) ? m : s);
	}
	return (0);
}
/**
 * is_avl_helper - Checks if the binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 * @hi: value of the largest node visited this far.
 * @lo: value of the smallest node visited thus far.
 * Return: valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t l_hgt, r_hgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
		{
			return (0);
		}
		l_hgt = height(tree->left);
		r_hgt = height(tree->right);
		diff = l_hgt > r_hgt ? l_hgt - r_hgt : r_hgt - l_hgt;
		if (diff > 1)
		{
			return (0);
		}
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}
/**
 * binary_tree_is_avl - will check if  binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to be checked
 * Return: 1 if is a valid AVL tree otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
