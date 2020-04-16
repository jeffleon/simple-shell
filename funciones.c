#include "holberton.h"
/**
 * errores - function that split a string
 * @split_arg0: string to strtok and other
 * @count_cmd: count
 * @split_arg2: count
 * @error: error
 */
void errores(char *split_arg0, char *split_arg2, long int *count_cmd
	     , int error);

/**
 * split_word - function that create a child
 * @cadena: line of comands
 * @countfree: count
 * Return: pointer char
 */

char **split_word(char *cadena, int *countfree)
{
	char **from = NULL;
	char token[] = {' ', '\t', '\0'};
	char *aux = NULL;
	int i = 0, count = 0;

	if (cadena == NULL)
		return (NULL);
	while (cadena[i])
	{
		if (cadena[i] == ' ' ||  cadena[i] == '\t')
			count++;
		i++;
	}
	count = count + 2;
	from = malloc(sizeof(char *) * (count));
	if (from == NULL)
		return (NULL);
	i = 0;
	if (count > 2)
	{
		aux = strtok(cadena, token);
		while (aux != NULL)
		{
			from[i] = _strdup(aux);
			aux = strtok(NULL, token);
			i++;
		}
		from[i] = NULL;
	}
	else
	{
		from[i] = _strdup(cadena);
		from[i + 1] = NULL;
	}
	*countfree = count;
	return (from);
}
/**
 * free_function - function that split a string
 * @from: array
 * @countfree: has a other number
 *
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
 * @ln_cmd:line of comands
 * @count_cmd:count
 * @words:string
 * @source:quantity of words that had a split_word
 * @environ:list of vars
 * Return:empty
 */
int execute_v(char **ln_cmd, long int *count_cmd,
	       int *words, char **source, char **environ)
{
	int a = 0;
	int i = 0;
	int error = 0;
	int status = 0;

	error = aux_execute(ln_cmd, source, environ, &a, &i);
	wait(&status);
	status = WEXITSTATUS(status);
	aux_errores(a, words, source, count_cmd, error);
	if (status == 2)
		error = 2;
	return (error);
}
/**
 * print_integers - function that create a child
 * @j: line of comands
 * @r: count
 * Return: a char integers
 */
char *print_integers(long int *j, int *r)
{
	char *p = NULL;
	long int i = 0;
	long int aux = *j;
	int retorno = 0;

	while (aux / 10 > 0)
	{
		aux = aux / 10;
		i++;
	}
	retorno = i;
	p = malloc(sizeof(char) * (i + 1));
	if (p == '\0')
		return ('\0');
	while (*j / 10 > 0)
	{
		p[i] = *j % 10 + '0';
		*j = *j / 10;
		i--;
	}
	p[i] = *j % 10 + '0';
	retorno++;
	*r = retorno;
	return (p);
}

/**
 * errores - function that create a child
 * @split_arg0: argument
 * @split_arg2: argument
 * @count_cmd: argument
 * @error: int
 */

void errores(char *split_arg0, char *split_arg2, long int *count_cmd,
	     int error)
{
	int i, j, w = 0, z = 0, valor_total = 0, h = 0;
	char *msg_error = '\0', add[] = ": ";
	char *msg[] = { ": Permission denied\n", ": not found\n"};
	char *p = '\0';

	p = print_integers(count_cmd, &w);
	for (j = 0; split_arg0[j] != '\0'; j++)
	{}
	for (i = 0; split_arg2[i] != '\0'; i++)
	{}
	for (h = 0; *(msg[error - 126] + h) != '\0'; h++)
	{}
	valor_total = (i + j + w + h + 5);
	msg_error = malloc(sizeof(char) * (valor_total));
	if (msg_error == '\0')
		return;
	for (z = 0; z < i; z++)
		msg_error[z] = split_arg2[z];
	for (z = 0; z < 2; z++)
		msg_error[z + i] = add[z];
	for (z = 0; z < w; z++)
		msg_error[z + i + 2] = p[z];
	for (z = 0; z < 2; z++)
		msg_error[z + i + 2 + w] = add[z];
	for (z = 0; z < j; z++)
		msg_error[z + i + 2 + w + 2] = split_arg0[z];
	for (z = 0; z < h; z++)
		msg_error[z + i + 4 + w + j]  = msg[error - 126][z];
	write(STDERR_FILENO, msg_error, valor_total);
	free(msg_error);
	free(p);
}
