#include "shell.h"

/**
 * main - The gate to the simple shell
 * @ac: (Unused variable) Number of arguements passed to the shell
 * @av: array containing arguements passed to the program
 * @env: array containing all environment variables
 * Return: 0
 */

int main(__attribute__((unused))int ac, char **av, char **env)
{
	char *usercomm = NULL, **tokenizedcomm = NULL;
	int pvalue = 0, ok = 0, pcheck = 0;

	while (1)
	{
		errno = 0;
		usercomm = mygetline();
		if (errno == 0 && usercomm == NULL)
			return (0);
		if (usercomm)
		{
			pvalue++;
			tokenizedcomm = tokenization(usercomm);
			if (!tokenizedcomm)
				free(usercomm);
			if (!cmpstr(tokenizedcomm[0], "env"))
				mygetenv(env);
			else
			{
				pcheck = pseperation(env, &tokenizedcomm[0]);
				ok = birth(av, env, tokenizedcomm, usercomm, pvalue, pcheck);
				if (ok == 200)
				{
					free(usercomm);
					return (0);
				}
				if (pcheck == 0)
					free(tokenizedcomm[0]);
			}
			free(tokenizedcomm);
		}
		else
		{i
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(ok);
		}
		free(usercomm);
	}
	return (0);
}
