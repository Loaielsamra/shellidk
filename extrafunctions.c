#include "shell.h"

/**
 * lenstr - calculates length of a string
 * @str: string
 * Return: length of `str`
 */

int lenstr(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
		;

	return (i);
}
