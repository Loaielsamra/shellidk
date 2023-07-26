#include "shell.h"

/**
 * plocate - makes the PATH more accessible to the program
 * by seperating it into strings
 * @arguements: user input
 * @env: environmental variables
 * Return: pointer to strings
 */

int plocate(char **arguements, char **env)
{
	struct stat buf;
	size_t length, pvalue;
	char *tokenholder = NULL, *pr = NULL, *pa = NULL;

	if (stat(*arguements, &buf) == 0)
		return (-1);
	pr = pfetch(env);
	if (!pr)
		return (-1);
	tokenholder = strtok(pr, ":");
	length = lenstr(*arguements);
	while (tokenholder)
	{
		pvalue = lenstr(tokenholder);
		pa = malloc((pvalue + length + 2) * sizeof(char));
		if (!pa)
		{
			free(pr);
			return (-1);
		}
		pa = cpystr(pa, tokenholder);
		catstr(pa, "/");
		catstr(pa, *arguements);

		if (stat(pa, &buf) == 0)
		{
			*arguements = pa;
			free(pr);
			return (0);
		}
		free(pa);
		tokenholder = strtok(NULL, ":");
	}
	tokenholder = '\0';
	free(pr);
	return (-1);
}
