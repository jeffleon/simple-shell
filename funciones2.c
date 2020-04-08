#include "holberton.h"
/**
 * addnode - function that split a string
 * @head: string to strtok
 * @aux: aux
 * Return: string split
 */
dir *addnode(dir **head, char *aux)
{
	dir *nuevopath = NULL;

	if (!nuevopath)
		return (NULL);
	if (!head)
		return (NULL);
	nuevopath = malloc(sizeof(dir));
	nuevopath->direccion = strdup(aux);
	nuevopath->next = *head;
	*head = nuevopath;
	return (*head);
}
/**
 * split_path - function that split a string
 * @path: string to strtok
 * @count_list: path
 * Return: string split
 */
dir *split_path(char *path, int *count_list)
{
	char delim[] = "=:";
	char *aux = NULL;
	dir *head = NULL;

	aux = strtok(path, delim);
	for (*count_list = 0; aux != NULL; *count_list += 1)
	{
		if (*count_list > 0)
			addnode(&head, aux);
		aux = strtok(NULL, delim);
	}
	return (head);
}
/**
 * concat - function that split a string
 * @direccion: string to strtok
 * @comand: path
 * Return: string split
 */

char *concat(char *direccion, char *comand)
{
	char *concat = NULL;
	int i, j, z, count = 0, size = 0;

	for (i = 0; direccion[i]; i++)
	{}
	for (j = 0; comand[j]; j++)
	{}
	size = i + j + 2;
	concat = malloc(sizeof(char) * (size));
	for (z = 0; z < size; z++, count++)
	{
		if (z < i)
			concat[z] = direccion[count];
		else
		{
			if (z == i)
				concat[z] = '/';
			else
			{
				if (z == (i + 1))
					count = 0;
				concat[z] = comand[count];
			}
		}
	}
	return (concat);
}
/**
 * _verification - function that split a string
 * @head: string to strtok
 * @source: string
 *
 */
void _verification(dir **head, char **source)
{
	dir *copia = *head;
	char *cmd_ver = NULL;
	char *rep_ver = NULL;

	for (; copia; copia = copia->next)
	{
		cmd_ver = concat(copia->direccion, source[0]);
	}
}
/**
 * _catchPATH - function that split a string
 * @environ: string to strtok
 * Return: string split
 */
char  *_catchPATH(char **environ)
{
	char *aux = "PATH";
	char **env = (char **)environ[0];
	char *path = NULL;
	int j = 0, i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; *(env[i] + j); j++)
		{
			if (*(env[i] + j) != aux[j])
			{
				break;
			}
		}
		if (j == 4)
		{
			path = env[i];
			break;
		}
	}
	printf("\n %s \n", path);
	return (path);
}
