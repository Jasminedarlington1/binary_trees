#include "binary_trees.h"
/**
 * array_to_heap - builds Max Binary Heap tree from an array
 * @array: pointer to the 1st element of the array to be converted
 * @size: number of elements in the array
 * Return: a pointer to the root node or NULL
 */
heap_t *array_to_heap(int *array, size_t size)
{
        unsigned int j;
        heap_t *root = NULL;

        for (j = 0; j < size; j++)
        {
                heap_insert(&root, array[j]);
        }
        return (root);
}
