#include "holberton.h"
/**
 * errores - function that split a string
 * @split_arg0: string to strtok and other
 * @count_cmd: count
 * @split_arg2: count
 */
void errores(char *split_arg0, char *split_arg2, long int *count_cmd);

/**
 * split_word - function that create a child
 * @cadena: line of comands
 * @countfree: count
 * Return: pointer char
 */

char **split_word(char *cadena, int *countfree)
{
	char **from = NULL;
	char token[] = " ,\n";
	char *aux = NULL;
	int i = 0, count = 0;

	if (cadena == NULL)
		return (NULL);
	while (cadena[i])
	{
		if (cadena[i] == token[0])
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
 * @ln_cmd: line of comands
 * @count_cmd: count
 * @words: string
 * @source:quantity of words that had a split_word
 */
void execute_v(char **ln_cmd, long int *count_cmd, int *words, char **source)
{
	struct stat st;
	char *word_to_send = '\0';
	char cadena[] = "sh";
	int j = 0, a = 0, i = 0;

	if (*source[0] != '/' && *source[0] != 46)
	{
		for (j = 0; ln_cmd[j]; j++)
		{
			if (stat(ln_cmd[j], &st) != -1)
			{
				a = fork();
				if (a == 0)
				{
					execve(ln_cmd[j], source, NULL);
					break;
				}
			}
		}
	}
	else
	{
		if ((stat(source[0], &st)) != -1)
		{
			a = fork();
			if (a == 0)
				execve(source[0], source, NULL);
		}
	}
	wait(NULL);
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
		{
			word_to_send = cadena;
			errores(source[0], word_to_send, count_cmd);

		}
	}
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
 *
 */

void errores(char *split_arg0, char *split_arg2, long int *count_cmd)
{
	int i, j, w = 0, z = 0, countarg = 0, valor_total = 0;
	char *msg_error = '\0', msg[] = ": not found\n", add[] = ": ";
	char *p = '\0';

	p = print_integers(count_cmd, &w);
	for (j = 0; split_arg0[j] != '\0'; j++)
	{}
	for (i = 0; split_arg2[i] != '\0'; i++)
	{}
	valor_total = (i + j + w + 17);
	msg_error = malloc(sizeof(char) * (valor_total));
	if (msg_error == '\0')
		return;
	for (z = 0; z < valor_total; z++, countarg++)
	{
		if (z < i)
			msg_error[z] = split_arg2[countarg];
		else if (z < (i + 2))
		{
			if (z == i)
				countarg = 0;
			msg_error[z] = add[countarg];
		}
		else if (z < (i + w + 2))
		{
			if (z == (i + 2))
				countarg = 0;
			msg_error[z] = p[countarg];
		}
		else if (z < (i + w + 4))
		{
			if (z == (i + w + 2))
				countarg = 0;
			msg_error[z] = add[countarg];
		}
		else if (z < (i + w + j + 4))
		{
			if (z == (i + w + 4))
				countarg = 0;
			msg_error[z] = split_arg0[countarg];
		}
		else
		{
			if (z == (i + w + j + 4))
				countarg = 0;
			msg_error[z]  = msg[countarg];
		}
	}
	write(1, msg_error, valor_total);
	free(msg_error);
	free(p);
}
