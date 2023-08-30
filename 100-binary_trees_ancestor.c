#include "binary_trees.h"

/**
 * binary_trees_ancestor - func that finds the lowest common ancestor
 * of two nodes.
 * @first: Pointer
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mum, *dad;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mum = first->parent, dad = second->parent;
	if ((first == dad) || !mum || (!mum->parent && dad))
		return (binary_trees_ancestor(first, dad));
	else if (mum == second || !dad || (!dad->parent && mum))
		return (binary_trees_ancestor(mum, second));
	return (binary_trees_ancestor(mum, dad));
}
