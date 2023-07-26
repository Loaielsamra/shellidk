#include "shell.h"

/**
 * mygetenv - prints all environmental variables
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
