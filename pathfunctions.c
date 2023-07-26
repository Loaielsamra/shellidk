#include "shell.h"

/**
 * pseperation - speretes PATH into strings
 * @env: environmental variables
 * @usercomm: user input
 * Return: poinetr to stirngs on success, -1 otherwise
 */

int pseperation(char **env, char **usercomm)
{
	struct stat buf;
	size_t length, pvalue;
	char *pfake = NULL, *preal = NULL, *tokenholder = NULL;

	if (stat(*usercomm, &buf) == 0)
		return (-1);
	pfake = pfetch(env);
	if (!pfake)
		return (-1);
	tokenholder = strtok(pfake, ":");
	length = lenstr(*usercomm);
	while (tokenholder)
	{
		pvalue = lenstr(tokenholder);
		preal = malloc((pvalue + length + 2) * sizeof(char));
		if (!preal)
		{
			free(pfake);
			return (-1);
		}
		preal = cpystr(tokenholder, preal);
		catstr("/", preal);
		catstr(*usercomm, preal);
		if (stat(preal, &buf) == 0)
		{
			*usercomm = preal;
			free(pfake);
			return (0);
		}
		free(preal);
		tokenholder = strtok(NULL, ":");
	}
	tokenholder = '\0';
	free(pfake);
	return (-1);
}

/**
 * pfetch - fetches PATH var
 * @env: Environment variables
 * Return: PATH's value on success, NULL otherwise
 */

char *pfetch(char **env)
{
	char *p = NULL;
	size_t num = 5, i = 0, var = 0;

	for (i = 0; cmpnstr(env[i], "PATH=", 5); i++)
		;
	if (env[i] == NULL)
		return (NULL);
	for (num = 5; env[i][var]; var++, num++)
		;
	p = malloc((++num) * sizeof(char));
	if (p == NULL)
		return (NULL);
	for (var = 5, num = 0; env[i][var]; var++, num++)
		p[num] = env[i][var];
	p[num] = '\0';
	return (p);
}

