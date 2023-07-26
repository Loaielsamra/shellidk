#include "shell.h"

char *builtinz[] = {"exit"};
int (*builtinf[])(char **) = {&builtinexit};

/**
 * numbuilt -calculates sizeof `builtinz`
 * Return: sizeof(`builtinz`)
 */
int numbuilt(void)
{
	int s;

	s = sizeof(builtinz) / sizeof(char *);

	return (s);
}

/**
 * builtinexit - exit
 * @unused: Unused variable
 * Return: always 200
 */
int builtinexit(__attribute__((unused))char **unused)
{
	free(unused);
	return (200);
}

/**
 * birth - birthes a child process
 * @av: Program's name
 * @env: environmental variables
 * @msc: all arguements
 * @usercomm: user command
 * @mpid: the processID
 * @f: indicates if needed to free 1st arg
 * Return: 0 on success, or errno otherwise
 */

int birth(char **av, char **env, char **msc, char *usercomm, int mpid, int f)
{
	char *spec = "%s: %d: %s: not found\n";
	int i = 0, ok;
	pid_t cpid;

	if (msc[0] == NULL)
		return (1);
	for (i = 0; i < numbuilt(); i++)
	{
		if (cmpstr(msc[0], builtinz[i]) == 0)
			return (builtinf[i](msc));
	}
	cpid = fork();
	if (cpid == 0)
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
