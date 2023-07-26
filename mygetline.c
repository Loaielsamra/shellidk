#include "shell.h"

/**
 * mygetline - my own getline command
 * Return: user input
 */

char *mygetline(void)
{
	size_t uinputs = 0;
	char *userinput = NULL;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "HELL $ ", 7);
	if (getline(&userinput, &uinputs, stdin) == -1)
	{
		free(userinput);
		return (NULL);
	}
	return (userinput);
}
