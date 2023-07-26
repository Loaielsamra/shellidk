#include "shell.h"

/**
 * tokenization - Tokenizes `str`
 * @str: string to tokenize
 * Return: Pointer to an array of strings
 */

char **tokenization(char *str)
{
	int i, num;
	char *tokenz = NULL;
	char **usercomm = NULL;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			num++;
	}
	if ((num + 1) == lenstr(str))
		return (NULL);
	usercomm = malloc((num + 2) * sizeof(char *));
	if (usercomm == NULL)
		return (NULL);
	tokenz = strtok(str, " \n\t\r");
	for (i = 0; tokenz != NULL; i++)
	{
		usercomm[i] = tokenz;
		tokenz = strtok(NULL, " \n\t\r");
	}
	usercomm[i] = NULL;
	return (usercomm);
}

/**
 * mygetenv - Prints all environmental variables to STDOUT
 * @env: environmental variables
 */

void mygetenv(char **env)
{
	size_t i;

	i = 0;
	while (env[i])
	{
		write(STDOUT_FILENO, env[i], lenstr(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
