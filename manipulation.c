#include "shell.h"

/**
 * catstr - conatenates strings
 * @dest: destinination string
 * @src: source string
 * Return: 0
 */

char *catstr(char *dest, char *src)
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
 * cmpstr - compares
 * @s1: 1st string
 * @s2: 2nd string
 * Return: diff between s1 and s2
 */

int cmpstr(char *s1, char *s2)
{
	int i, diff;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	diff = s1[i] - s2[i];

	return (diff);
}

/**
 * lenstr - calculates length of string
 * @str: string
 * Return: length of `str`
 */

int lenstr(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;

	return (i);
}

/**
 * cmpnstr - compares strings to the nth byte
 * @s1: 1st string
 * @s2: 2nd string
 * @s: maximum bytes
 * Return: diff between s1 and s2
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
 * cpystr - duplicates string `src` into `dest`
 * @dest: destination string
 * @src: source string
 * Return: pointer to `dest`
 */

char *cpystr(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i + 1] = 0;

	return (dest);
}
