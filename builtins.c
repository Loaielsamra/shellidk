#include "shell.h"

char *builtinz[] = {"exit"};
int builtinexit(char **var);
int (*builtfunctions[])(char **) = {&builtinexit};

/**
 * numbuilt - number of builtin functions
 * Return: num
 */

int numbuilt(void)
{
	return (sizeof(builtinz) / sizeof(char *));
}

/**
 * builtinexit - exit
 * @var: unused variable
 * Return: 100
 */

int builtinexit(__attribute__((unused))char **var)
{
	free(var);
	return (100);
}

/**
 * birth - Birthes a child to execute a function
 * @msc: everything
 * @av: shell name
 * @env: environmental vars
 * @usercomm: user input
 * @mpid: pid
 * @f: frees 1st arguement if triggered
 * Return: 0 on succes, appropriate ERRNO otherwise
 */

int birth(char **msc, char **av, char **env, char *usercomm, int mpid, int f)
{
	char *spec = "%s: %d: %s: not found\n";
	int i, ok;
	pid_t mypid;

	if (msc[0] == NULL)
		return (1);
	for (i = 0; i < numbuilt(); i++)
	{
		if (cmpstr(msc[0], builtinz[i]) == 0)
			return (builtfunctions[i](msc));
	}
	mypid = fork();
	if (mypid == 0)
	{
		if (execve(msc[0], msc, env) == -1)
		{
			fprintf(stderr, spec, av[0], mpid, msc[0]);
			if (!f)
				free(msc[0]);
			free(msc);
			free(usercomm);
			exit(errno);
		}
	}
	else
	{
		wait(&ok);
		return (ok);
	}

	return (0);
}
