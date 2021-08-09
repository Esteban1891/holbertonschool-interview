#include "search_algos.h"
/**
 * print_array - print the message
 * @array: array to print
 * @from: index to start print
 * @to: index to end print
 *
 * Return: is a void
 */
void print_array(int *array, int from, int to)
{
	printf("Searching in array: ");
	while (from < to)
	{
		printf("%i, ", array[from]);
		from++;
	}
	printf("%i\n", array[from]);
}
/**
 * recursion_binary - print the message
 * @array: array to find
 * @from: index to start search
 * @to: index to end search
 * @value: value to find
 *
 * Return: index
 */
int recursion_binary(int *array, int from, int to, int value)
{
	int mid;

	print_array(array, from, to);
	mid = (to - from) / 2 + from;
	if (from == to)
		return (-1);
	if (array[mid] == value && array[mid - 1] != value)
		return (mid);
	if (array[mid] >= value)
		return (recursion_binary(array, from, mid, value));
	if (array[mid] <= value)
		return (recursion_binary(array, mid + 1, to, value));
	return (-1);
}
/**
 * advanced_binary - print the message
 * @array: array to find
 * @size: array length
 * @value: value to find
 *
 * Return: index
 */
int advanced_binary(int *array, size_t size, int value)
{

	if (!array)
		return (-1);

	return (recursion_binary(array, 0, size - 1, value));
}
