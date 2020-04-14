#include "holberton.h"
/**
 *  _exit_ - function that show the command exit in shell
 * @source: doble pointer
 * Return: nothing
 */
int _salir_(char *line, char *word_wsp, char **split_2, int *countfree,
	    dir *head)
{
	char *pointer = "exit";

	if ((_strcmp(split_2[0], pointer) == 0))
	{
		printf("entre al if  y me sali\n");
		free_list(head);
		free(line);
		free_function(split_2, countfree);
		free(word_wsp);
		exit(127);
	}
	return (0);
}
/**
 *  _exit_ - function that show the command exit in shell
 * @source: doble pointer
 * Return: nothing
 */

void aux_errores(int a, int *words, char **source, long int *count_cmd)
{
	char *word_to_send = '\0', cadena[] = "sh";
	int i = 0;

	if (a == 0)
	{
		if (*words > 2)
		{
			for (i = 1; source[i]; i++)
			{
				if (*source[i] == '/' || *source[i] == '.')
				{
					word_to_send = source[i];
					break;
				}
				else
					word_to_send = cadena;
			}
		}
		else
			word_to_send = cadena;
		errores(source[0], word_to_send, count_cmd);
	}
}
