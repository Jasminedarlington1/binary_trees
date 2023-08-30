#include "binary_trees.h"
/**
 * array_to_avl - it will build an AVL tree from an array
 * @size: the number of elements in the array
 * @array: the pointer to the 1st element of the array to be converted
 * Return: the pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t j;
	bst_t *tree = NULL;

	if (array == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < size; j++)
	{
		avl_insert(&tree, array[j]);
	}
	return (tree);
}
