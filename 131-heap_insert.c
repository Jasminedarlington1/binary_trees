#include "binary_trees.h"
/**
 * heap_insert -  inserts value into a Max Binary Heap
 * @value: value store in the node to insert
 * @root: double pointer to root node of the Heap
 * Return: pointer to the node, or NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *aux = NULL, *new = NULL;
	int bal = 0, value_aux = 0;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	aux = *root;
	while (aux->left && aux->right)
	{
		bal = binary_tree_balance(aux);
		if ((bal > 0 && binary_tree_is_perfect(aux->left) == 1) ||
			(binary_tree_is_perfect(aux->right) == 0))
			aux = aux->right;
		else
			aux = aux->left;
	}
	if (aux->left == NULL)
	{
		new = binary_tree_node(aux, value);
		aux->left = new;
	}
	else
	{
		new = binary_tree_node(aux, value);
		aux->right = new;
	}
	while (new->parent != NULL && new->n > new->parent->n)
	{
		value_aux = new->parent->n;
		new->parent->n = new->n;
		new->n = value_aux;
		new = new->parent;
	}
	return (new);
}

int balance_recursion(const binary_tree_t *tree, int count);

/**
 * binary_tree_balance - measures balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: balance factor. If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_right = 0;
	int balance_left = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		balance_left = balance_recursion(tree->left, 1);
	if (tree->right != NULL)
		balance_right = balance_recursion(tree->right, 1);

	return (balance_left - balance_right);
}
/**
 * balance_recursion - the aux function for recursion
 * @count: the counter of height
 * @tree: the pointer to the tree
 * Return: the height
 */
int balance_recursion(const binary_tree_t *tree, int count)
{
	int r_count = 0;
	int l_count = 0;

	if (tree->left != NULL)
	{
		l_count = balance_recursion(tree->left, count + 1);
	}
	if (tree->right != NULL)
	{
		r_count = balance_recursion(tree->right, count + 1);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (count);
	}
	if (r_count > l_count)
	{
		return (r_count);
	}
	else
	{
		return (l_count);
	}
}

size_t height_recursion(const binary_tree_t *tree, size_t count);
size_t leaves_recursion(const binary_tree_t *tree, size_t count);

/**
 * binary_tree_is_perfect - checks if the binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if perfect, otherwise 0 
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t hgt, leaves = 0;
	size_t expectd_leaves = 1;
	size_t count;

	if (tree == NULL)
	{
		return (0);
	}
	hgt = height_recursion(tree, 0);
	leaves = leaves_recursion(tree, 0);

	for (count = 0; count < hgt; count++)
	{
		expectd_leaves = expectd_leaves * 2;
	}
	if (expectd_leaves == leaves)
	{
		return (1);
	}
	return (0);
}
/**
 * leaves_recursion - aux function for recursion
 * @count: leaves counter
 * @tree: pointer to the root node of the tree
 * Return: Number of leaves
 */
size_t leaves_recursion(const binary_tree_t *tree, size_t count)
{
	if (tree->left != NULL)
	{
		count = leaves_recursion(tree->left, count);
	}
	if (tree->right != NULL)
	{
		count = leaves_recursion(tree->right, count);
	}
	if (tree->right == NULL && tree->left == NULL)
	{
		return (count + 1);
	}
	return (count);
}
/**
 * height_recursion - the aux function for recursion
 * @tree: the pointer to the tree
 * @count: height counter
 * Return: the height
 */
size_t height_recursion(const binary_tree_t *tree, size_t count)
{
	size_t r_count = 0;
	size_t l_count = 0;

	if (tree->left != NULL)
	{
		l_count = height_recursion(tree->left, count + 1);
	}
	if (tree->right != NULL)
	{
		r_count = height_recursion(tree->right, count + 1);
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (count);
	}
	if (r_count > l_count)
	{
		return (r_count);
	}
	else
	{
		return (l_count);
	}
}
