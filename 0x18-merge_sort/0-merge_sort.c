#include "sort.h"

/**
 * merge - merge sort
 * @array: pointer
 * @size: size of the array
 * @m: Middle index
 * @temp: pointer
 * Return: void
 */
void merge(int *array, int size, int m, int *temp)
{
	int i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array, m);
	printf("[right]: ");
	print_array(array + m, size - m);
	for (i = 0, j = m, k = 0; k < size; k++)
	{

		if (j == size)
		{
			temp[k] = array[i];
			i++;
		}
		else if (i == m)
		{
			temp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			temp[k] = array[j];
			j++;
		}
		else
		{
			temp[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	printf("[Done]: ");
	print_array(temp, size);
}


/**
 * merge_main - merge sort
 * @array: pointer
 * @size: size of the array
 * @temp: pointer
 * Return: void
 */
void merge_main(int *array, size_t size, int *temp)
{
	int m;

	if (size < 2)
		return;
	m = size / 2;
	merge_main(array, m, temp);
	merge_main(array + m,  size - m, temp);
	merge(array, size, m, temp);
}


/**
 * merge_sort - merge sort
 * @array: pointer
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;
	merge_main(array, size, temp);
	free(temp);
}
