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

	nuevopath = malloc(sizeof(dir));
	if (!nuevopath)
		return (NULL);
	if (!head)
		return (NULL);
	nuevopath->direccion = _strdup(aux);
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
			head = addnode(&head, aux);
		aux = strtok(NULL, delim);
	}
	return (head);
}
/**
 * _concat - function that split a string
 * @direccion: string to strtok
 * @comand: path
 * Return: string split
 */

char *_concat(char *direccion, char *comand)
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
 * @pointer:sizeof of cmd_ver
 * Return:cmd_ver array
 */
char **_verification(dir **head, char *source, int *pointer)
{
	dir *copia = *head;
	char **cmd_ver = NULL;
	int i = 0;

	cmd_ver = malloc(sizeof(char *) * (*pointer));
	for (i = 0; copia; copia = copia->next, i++)
	{

		cmd_ver[i] = _concat(copia->direccion, source);
	}
	cmd_ver[i] = '\0';
	return (cmd_ver);
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
	return (path);
}
