#include "shell.h"

/**
 * pfetch - fetches PATh variable
 * @env: environmental variables
 * Return: Path's value
 */

char *pfetch(char **env)
{
	char *p = NULL;
	size_t i, num = 5, v = 0;

	for (i = 0; cmpnstr(env[i], "PATH=", 5); i++)
		;
	if (env[i] == NULL)
		return (NULL);
	for (num = 5; env[i][v]; v++, num++)
		;

	p = malloc((num + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);

	for (v = 5, num = 0; env[i][v]; v++, num++)
		p[num] = env[i][v];

	p[num] = '\0';
	return (p);
}
