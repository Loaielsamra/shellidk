#include "shell.h"

/**
 * tokenization - splits the string
 * @usercomm: user input
 * Return: split string
 */

char **tokenization(char *usercomm)
{
	int i, num = 0;
	char *tokenhold = NULL;
	char **comms = NULL;

	if (usercomm == NULL)
		return (NULL);

	for (i = 0; usercomm[i]; i++)
	{
		if (usercomm[i] == ' ')
			num++;
	}
	if ((num + 1) == lenstr(usercomm))
		return (NULL);
	comms = malloc((num + 2) * sizeof(char *));
	if (comms == NULL)
		return (NULL);

	tokenhold = strtok(usercomm, " \n\t\r");
	for (i = 0; tokenhold != NULL; i++)
	{
		comms[i] = tokenhold;
		tokenhold = strtok(NULL, " \n\t\r");
	}
	comms[i] = NULL;
	return (comms);
}
