#include "lists.h"

/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: Pointer to the head of the list
 * Return: 1 if it is palindrome or 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head;
	int array[2048], i = 0, j = 0, middle;

	if (head == NULL || (tmp != NULL && tmp->next == NULL))
		return (1);
	while (tmp != NULL)
	{
		array[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	i--, middle = i / 2;
	while (i >= middle && j <= middle)
	{
		if (array[j] != array[i])
			return (0);
		i--, j++;
	}
	return (1);
}
