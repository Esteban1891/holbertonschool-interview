#include "search.h"
/**
 * print_found - print message when found limits
 * @index1: from this index
 * @index2: to this index
 * @last: know if the last one in express line
 *
 * Return: nothing
 */
void print_found(size_t index1, size_t index2, skiplist_t *last)
{
	if (last != NULL)
	{
		while (last->next != NULL)
			last = last->next;
		index2 = last->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", index1, index2);
}
/**
 * print_check - print message when check values
 * @index: index where is comparing
 * @value: value to compare
 *
 * Return: nothing
 */
void print_check(size_t index, int value)
{
	printf("Value checked at index [%lu] = [%i]\n", index, value);
}
/**
 * find_one_by_one - check next by next
 * @head: express line node
 * @value: value to compare
 *
 * Return: node founded
 */
skiplist_t *find_one_by_one(skiplist_t *head, int value)
{
	skiplist_t *current = head;

	if (head == NULL)
		printf("n head nullll");
	for (; current; current = current->next)
	{
		print_check(current->index, current->n);
		if (current->n == value)
			return (current);
	}

	return (NULL);
}
/**
 * linear_skip - found a value in skip list
 * @head: express line node
 * @value: value to compare
 *
 * Return: node founded
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *current  = head, *next = NULL;

	if (head == NULL)
		return (NULL);

	while (current != NULL)
	{
		next = current->express;
		if (next != NULL)
		{
			print_check(next->index, next->n);
			if (next->n >= value)
			{
				print_found(current->index, next->index, NULL);
				return (find_one_by_one(current, value));
			}

			if (next->express == NULL)
			{
				print_found(next->index, 0, next);
				return (find_one_by_one(next, value));
			}
		}

		current = current->express;
	}

	return (NULL);
}
