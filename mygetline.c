#include "shell.h"

/**
 * mygetline - our own getline
 * Return: user input
 */

char *mygetline(void)
{
	size_t size = 0;
	char *user = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "HELL $ ", 7);
	if (getline(&user, &size, stdin) == -1)
	{
		free(user);
		return (NULL);
	}

	return (user);
}
