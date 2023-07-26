#include "shell.h"

/**
 * main - gate to the shell
 * @ac: (Unused Variable) counter of args
 * @av: All arguements passed to the shell
 * @env: envrionmental variables
 * Return: 0
 */

int main(__attribute__((unused))int ac, char **av, char **env)
{
	char *usercomm = NULL, **comms = NULL;
	int pvalue = 0, ok = 0, pcheck = 0;

	do {
		errno = 0;
		usercomm = mygetline();
		if (errno == 0 && usercomm == NULL)
			return (0);
		if (usercomm)
		{
			pvalue++;
			comms = tokenization(usercomm);
			if (!comms)
				free(usercomm);
			if (!cmpstr(comms[0], "env"))
				mygetenv(env);
			else
			{
				pcheck = plocate(&comms[0], env);
				ok = birth(comms, av, env, usercomm, pvalue, pcheck);
				if (ok == 100)
				{
					free(usercomm);
					return (0);
				}
				if (pcheck == 0)
					free(comms[0]);
			}
			free(comms);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(ok);
		}
		free(usercomm);
	} while (1);

	return (0);
}
