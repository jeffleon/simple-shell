#include "holberton.h"
/**
 *  _salir_ - function that show the command exit in shell
 * @line: string
 * @word_wsp: spaces
 * @split_2: contain the tokens
 * @countfree: words
 * @head: pointer to struct
 * @error: error
 * Return: zero
 */
int _salir_(char *line, char *word_wsp, char **split_2, int *countfree,
	    dir *head, int error)
{
	char *pointer = "exit";

	if ((_strcmp(split_2[0], pointer) == 0))
	{
		free_list(head);
		free(line);
		free_function(split_2, countfree);
		free(word_wsp);
		exit(error);
	}
	return (0);
}

/**
 * aux_errores - function that show the errors in shell
 * @words: counter to words
 * @a:counter
 * @count_cmd:counter commands
 * @source: doble pointer
 * @error: error
 * Return: nothing
 */

void aux_errores(int a, int *words, char **source, long int *count_cmd
		 , int error)
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
		errores(source[0], word_to_send, count_cmd, error);
	}
}

/**
 * aux_execute - function that show the errors in shell
 * @ln_cmd: counter to words
 * @source: counter
 * @environ: counter commands
 * @a: doble pointer
 * @i: int
 * Return: a integer
 */

int aux_execute(char **ln_cmd, char **source, char **environ, int *a, int *i)
{
	int j = 0, error_found = 0, error_denied = 0, error = 0;

	if (*source[*i] != '/' && *source[*i] != 46)
	{
		for (j = 0; ln_cmd[j]; j++)
		{
			error_found = stat(ln_cmd[j], &st);
			if ((error_found) != -1)
			{
				error_denied = access(ln_cmd[j], X_OK);
				if ((error_denied) == 0)
				{
					*a = fork();
					if (*a == 0)
						execve(ln_cmd[j], source, environ);
					return (0);
				}
			}
		}
	}
	else
	{
		error_found = stat(source[0], &st);
		if ((error_found) != -1)
		{
			error_denied = access(source[0], X_OK);
			if ((error_denied) == 0)
			{
				*a = fork();
				if (*a == 0)
					execve(source[0], source, environ);
				return (0);
			}
		}
	}
	if (error_found == -1)
		error = 127;
	else if (error_denied == -1)
		error = 126;
	return (error);
}
