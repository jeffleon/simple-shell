#include "holberton.h"
/**
 * _which - function that show the command which in shell
 * @source: doble pointer
 * Return: nothing
 */
int _which(char **source, char **environ, dir **test, long int *count_cmd)
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
        if (*source[1] != '/' && *source[1] != 46)
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
			printf("aca me meti \n");
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
int _cd(char **source, char **environ, dir **test, long int *count_cmd)
{
	char s[100];
	char *msg = NULL;
	int sizenum = 0;

	getcwd(s, 100);
	if (source[1] == NULL)
		return (1);
	if (chdir(source[1]) != 0)
	{
		msg = _union(count_cmd, &sizenum);
		perror(msg);
		free(msg);
	}
	return (1);
}
/**
 * _help - function that show the command help in shell
 * @source: doble pointer
 * Return: nothing
 */
int _help(char **source, char **environ, dir **test, long int *count_cmd)
{
	printf("me meti help\n");
}

/**
 *  _env - function that show the command exit in shell
 * @source: doble pointer
 * Return: nothing
 */
int _env(char **source, char **environ, dir **test, long int *count_cmd)
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

/**
 *  _union - function that show the command exit in shell
 * @source: doble pointer
 * Return: nothing
 */
char *_union(long int *count_cmd, int *sizenum)
{
	int i = 0;
	char *total = NULL;
	char *num = NULL;
	char inicio[5] = "sh: ";
	char inter[5] = ": cd";

	num = print_integers(count_cmd, sizenum);
	total = malloc(sizeof(char) * (9 + *sizenum));
	for (i = 0; inicio[i]; i++)
		total[i] = inicio[i];
	for (i = 0; i < *sizenum; i++)
		total[4 + i] = num[i];
	for (i = 0; inter[i]; i++)
		total[4 + *sizenum + i] = inter[i];
	total[4 + *sizenum + i] = '\0';
	printf("mensaje : [%s]\n", total);
	free(num);
	return(total);
}
