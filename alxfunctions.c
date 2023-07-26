#include "shell.h"

/**
 * cmpstr - compares 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0 if identical, -1 otherwise
 */

int cmpstr(char *s1, char *s2)
{
	int i,  diff;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	diff = s1[i] - s2[i];

	return (diff);
}

/**
 * catstr - concatenates strings
 * @src: source string
 * @dest: desitination strings
 * Return: pointer to `dest`
 */

char *catstr(char *src, char *dest)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _putchar - prints character
 * @c: character
 * Return: num
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * cmpnstr - compares 2 strings to the nth byte
 * @s1: 1st strig
 * @s2: 2nd string
 * @s: num of bytes
 * Return: difference between s1 and s2
 */

size_t cmpnstr(char *s1, char *s2, size_t s)
{
	size_t i, j;

	for (i = 0; i < s && s1[i] != '\0'; i++)
	{
		j = s1[i] - s2[i];
		if (j != 0)
			return (j);
	}
	return (0);
}

/**
 * cpystr - duplicates src string into dest string
 * @src: source string
 * @dest: destination string
 * Return: pointer to `dest`
 */

char *cpystr(char *src, char *dest)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i + 1] = 0;
	return (dest);
}
