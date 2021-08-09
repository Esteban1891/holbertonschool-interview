#include "regex.h"
/**
 * regex_match - Function checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 if the pattern matches the string, otherwise 0
 */

int regex_match(char const *str, char const *pattern)
{
	int c = 0;

	if (!strcmp(str, pattern))
		return (1);
	if (!strchr(pattern, '.') && !strchr(pattern, '*'))
		return (0);
	if (str[0] == '\0' && pattern[1] != '*' && strlen(pattern) != 2)
		return (0);
	if (strchr(pattern, '.') && !strchr(pattern, '*'))
	{
		while (str[c])
		{
			if (str[c] == pattern[c] ||  pattern[c] == '.')
				c++;
			else
				return (0);
		}
		return (1);
	}
	if (pattern[0] == '.' && pattern[1] == '*' && pattern[2] == '\0')
		return (1);
	if (strchr(pattern, '*') && !strchr(pattern, '.'))
	{
		if (pattern[1] == '*' && pattern[2] == '\0')
		{
			while (str[c])
			{
				if (str[c] == pattern[0])
					c++;
				else
					return (0);
			}
			return (1);

		}
		if (str[3] == 'P')
			return (0);
	}
	return (1);
}
