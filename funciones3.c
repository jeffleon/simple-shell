#include "holberton.h"
/**
 *  _salir_ - function that show the command exit in shell
 * @line: string
 * @word_wsp: spaces
 * @split_2: contain the tokens
 * @countfree: words
 * @head: pointer to struct
 * @error: error
 * @path: path
 * Return: zero
 */
int _salir_(char *line, char *word_wsp, char **split_2, int *countfree,
	    dir *head, int error, char *path)
{
	char *pointer = "exit";

	if ((_strcmp(split_2[0], pointer) == 0) && split_2[1] == NULL)
	{
		free(path);
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
		if ((_strcmp(source[0], "exit") != 0))
		{
			if (*words > 2)
			{
				for (i = 1; source[i]; i++)
				{
					if (*source[i] == '/' ||
					    *source[i] == '.')
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
		else
			err_exit(source[0], source[1], count_cmd);

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
			}
		}
	}
	if (error_found == -1)
		error = 127;
	else if (error_denied == -1)
		error = 126;
	return (error);
}



/**
 * err_exit - function that create a child
 * @split_arg0: argument
 * @split_arg2: argument
 * @count_cmd: argument
 */

void err_exit(char *split_arg0, char *split_arg2, long int *count_cmd)
{
	int i, j, w = 0, z = 0, valor_total = 0, h = 0;
	char *msg_error = '\0', add[] = "sh: ";
	char msg[] = ": exit: Illegal number: ";
	char salto[] = "\n";
	char *p = '\0';

	p = print_integers(count_cmd, &w);
	for (j = 0; split_arg0[j] != '\0'; j++)
	{}
	for (i = 0; split_arg2[i] != '\0'; i++)
	{}
	for (h = 0; msg[h] != '\0'; h++)
	{}
	valor_total = (i + w + h + 5);
	msg_error = malloc(sizeof(char) * (valor_total));
	if (msg_error == '\0')
		return;
	for (z = 0; z < 4; z++)
		msg_error[z] = add[z];
	for (z = 0; z < w; z++)
		msg_error[z + 4] = p[z];
	for (z = 0; z < h; z++)
		msg_error[z + 4 + w] = msg[z];
	for (z = 0; z < i; z++)
		msg_error[z + 4 + w + h] = split_arg2[z];
	for (z = 0; z < 1; z++)
		msg_error[z + 4 + w + h + i] = salto[z];
	write(STDERR_FILENO, msg_error, valor_total);
	free(msg_error);
	free(p);
}
/**
 * lk_lst_env - function that create a child
 * @environ: argument
 * Return: return a pointer
 *
 */

dir *lk_lst_env(char **environ)
{
	int i = 0;
	dir *head_env = NULL;

	for (i = 0; environ[i] != NULL; i++)
		head_env = addnode(&head_env, environ[i]);
	return (head_env);
}
