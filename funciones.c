#include "holberton.h"
/**
 * split_word - function that split a string
 * @cadena: string to strtok
 * Return: string split
 */

char** split_word(char *cadena, int *countfree)
{
	char **from = NULL;
	char token[] = " ";
	char *aux = NULL;
	int i = 0, count = 0;

	if(cadena == NULL)
		return(NULL);

	while (cadena[i])
	{
		if (cadena[i] == token[0] && cadena[i + 1] != '\0')
			count++;
		i++;
	}
	from = malloc(sizeof(char *) * (count + 2));
	if(from == NULL)
		return(NULL);
	aux = strtok(cadena, token);
	i = 0;
	while(aux != NULL)
	{
	   	from[i] = strdup(aux);
		aux = strtok(NULL, token);
		i++;
	}
	*countfree = count + 1;
	return(from);
}
/**
 * free_function - function that split a string
 * @from: array
 * @countfree:
 * Return: void
 */
void free_function(char **from, int *countfree)
{
	int i = 0;

	while (i < *countfree)
	{
	free(from[i]);
	i++;
	}
	free(from);
}
/**
 * execute_v - function that create a child
 * @ln_cmd: line of comands
 * Return: void
 */
void execute_v(char **ln_cmd, int *count_cmd)
{
	struct stat st;

	if(stat(ln_cmd[0], &st) != -1)
	{
		if (fork() == 0)
	   	execve(ln_cmd[0], ln_cmd, NULL);
	}
	else
		printf("[%d] : %s Not Found\n", *count_cmd, ln_cmd[0]);

}
