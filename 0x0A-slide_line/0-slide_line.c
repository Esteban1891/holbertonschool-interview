#include <stdlib.h>
#include "slide_line.h"

/**
 * swap_ints - switch 
 * @p: pointer to an int
 * @p2: pointer to an int
 */
void swap_ints(int *p, int *p2)
{
	int temp = *p;

	*p = *p2;
	*p2 = temp;
}

/**
 * shift_left - shifts nonzero numbers in a matrix to the left
 * @line: array of integers.
 * @size: size of the array
 */
void shift_left(int *line, size_t size)
{
	size_t i, pos = 0;

	for (i = 0; i < size && pos < size; i++)
	{
		while (line[pos] == 0 && pos < size && pos + 1 < size)
			pos++;
		if (!line[i])
			swap_ints(&line[pos], &line[i]);
		pos++;
	}
}

/**
 * shift_right - shift nonzero numbers in an array to the right
 * @line: array of integers.
 * @size: size of the array
 */
void shift_right(int *line, size_t size)
{
	size_t i;
	size_t pos = size - 1;

	for (i = size - 1; (int) i >= 0 && (int) pos >= 0; i--)
	{
		while (line[pos] == 0 && (int) pos > 0)
			pos--;
		if (!line[i])
			swap_ints(&line[pos], &line[i]);
		pos--;
	}
}

/**
 * slide_line - merge like nums in array & shift non-0 nums in given direction
 * @line: given array of integers
 * @size: size of the array
 * @direction: either left or right
 * Return: 1 for success, else 0.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == SLIDE_LEFT) {
		shift_left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		shift_left(line, size);
		return (1);
	} else if (direction == SLIDE_RIGHT) {
		shift_right(line, size);
		for (i = size - 1; (int) i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		shift_right(line, size);
		return (1);
	}
	return (0);
}

