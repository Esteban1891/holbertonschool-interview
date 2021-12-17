#include "binary_trees.h"
/**
 * heapify - Function that fix the heap max
 * @root: pointer to the head of the heap tree
 * Return: void function
 */
void heapify(binary_tree_t *root)
{
	binary_tree_t *child = NULL;
	int num = 0;

	while (1)
	{
		if (!root->left)
			break;
		else if (!root->right)
			child = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				child = root->left;
			else
				child = root->right;
		}

		if (root->n >= child->n)
			break;

		num = root->n;
		root->n = child->n;
		child->n = num;

		root = child;
	}
}

/**
 * num_nodes - Function that stores the number of nodes of heap tree
 * @root: Pointer to the head of the heap tree
 * Return: number of nodes in heap tree
 */
int num_nodes(heap_t *root)
{
	int l = 0, r = 0;

	if (!root)
		return (0);

	l = num_nodes(root->left);
	r = num_nodes(root->right);

	return (1 + l + r);
}

/**
 * last_node_func - Function that gets the last node in heap min
 * @root: pointer to the head of the heap tree
 * Return: The last node in heap min
 */
binary_tree_t *last_node_func(heap_t *root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *last_node = NULL;

	size_heap = num_nodes(root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (last_node = root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return (last_node);
}
/**
 * heap_extract - Function that extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value stored in the root node, or 0 if fail.
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *last_node = NULL, *head_node = NULL;
	int extracted_num = 0;

	if (!root || !*root)
		return (0);
	head_node = *root;
	if (!head_node->left && !head_node->right)
	{
		extracted_num = head_node->n;
		free(head_node);
		*root = NULL;
		return (extracted_num);
	}

	head_node = *root;
	extracted_num = head_node->n;

	last_node = last_node_func(*root);

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	last_node->left = head_node->left;
	last_node->right = head_node->right;
	last_node->parent = head_node->parent;

	if (head_node->left)
		head_node->left->parent = last_node;
	if (head_node->right)
		head_node->right->parent = last_node;

	*root = last_node;
	free(head_node);

	heapify(*root);

	return (extracted_num);
}
