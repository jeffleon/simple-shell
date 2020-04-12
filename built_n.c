#include "holberton.h"
/**
 * _which - function that show the command which in shell
 * @source: doble pointer
 * Return: nothing
 */
int _which(char **source, char **environ, dir **test)
{
	int j = 0, i = 0, count_list = 0;
	struct stat st;
	dir *copia = *test;
	char **verificar;

	for (count_list = 0; copia;copia = copia->next, count_list++)
	{
	}
	count_list++;
	if (source[1] == NULL)
		return(1);
        if (*source[0] != '/' && *source[0] != 46)
        {
		verificar = _verification(test,source[1], &count_list);
		for (j = 0; verificar[j]; j++)
                {
                        if (stat(verificar[j], &st) != -1)
			{
				for (i = 0; *(verificar[j] + i); i++)
				{}
				write(1, verificar[j], i);
				write(1, "\n", 1);
				break;
                        }
		}
		free_function(verificar, &count_list);
        }
        else
        {
                if ((stat(source[1], &st)) != -1)
                {
                        for (i = 0; *(source [1] + i); i++)
			{}
			write(1, source[1], i);
			write(1, "\n", 1);
                }
	}
	return(1);
}
/**
 * _cd - function that show the command cd in shell
 * @source: doble pointer
 * Return: nothing
 */
int _cd(char **source, char **environ, dir **test)
{
	printf("me meti cd\n");
}
/**
 * _help - function that show the command help in shell
 * @source: doble pointer
 * Return: nothing
 */
int _help(char **source, char **environ, dir **test)
{
	printf("me meti help\n");
}

/**
 *  _env - function that show the command exit in shell
 * @source: doble pointer
 * Return: nothing
 */
int _env(char **source, char **environ, dir **test)
{
	int i = 0, j = 0;
	char **env = (char **)environ[0];

	if (environ == NULL)
		return (1);
	for (i = 0; env[i] != NULL; i++)
	{
		for(j = 0; *(env[i] + j); j++)
		{}
		write(1, env[i], j);
		write(1, "\n",1);
	}
	return (1);
}
