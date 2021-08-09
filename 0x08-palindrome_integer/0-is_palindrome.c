#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: the number to check
 * Return: 1 if n is palindrome 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char num[50];
	int i, total_digits;

	/* Put the number n in array */
	for (i = 0; n; i++)
	{
		num[i] = n % 10;
		n = n / 10;
	}
	num[i] = '\0';
	/* Go through the string to identify the palindrome */
	total_digits = i;
	for (i = 0; i < (total_digits / 2); i++)
		/* If borders are diferent, then no palindrome */
		if (num[i] != num[total_digits - 1 - i])
			return (0);
	/* Else is a palindrome */
	return (1);
}
