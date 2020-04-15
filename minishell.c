#include "holberton.h"
/**
 * sighandler - main function
 * @sighandler:integer
 * Return: void
 */
void sighandler(int sighandler)
{
	(void)sighandler;
	write(1, "\n$ ", 3);
}
/**
 * main - main function
 * Return: zero
 */
int main(void)
{
	dir *head = NULL;
	size_t len = 0;
	ssize_t linesize = 0;
	char *_path = NULL, *word_wsp = NULL, *line = NULL;
	char **split_2 = NULL, **test = NULL;
	int countfree = 0, count_list = 0, count_sp = 0, built_in_ent = 0, isa = 0;
x	long int count_cmd = 0;

	_path = _catchPATH(environ);
	head = split_path(_path, &count_list), signal(SIGINT, sighandler);
	for (; linesize != EOF; count_cmd++)
	{
		isa = isatty(0);
		if (isa)
			write(1, "$ ", 2);
		linesize = getline(&line, &len, stdin);
		if (linesize > 1)
			line[linesize - 1] = '\0';
		else
			continue;
		word_wsp = delete_spaces(line, &count_sp);
		if (word_wsp == NULL || *word_wsp == '\0')
		{
			free(word_wsp);
			continue;
		}
		split_2 = split_word(word_wsp, &countfree);
		_salir_(line, word_wsp, split_2, &countfree, head);
		built_in_ent = _selection(split_2, environ, &head, &count_cmd);
		test = _verification(&head, split_2[0], &count_list);
		if (built_in_ent == 0)
			execute_v(test, &count_cmd, &countfree, split_2,
				  environ, isa);
		wait(NULL), free(word_wsp), free_function(test, &count_list);
		free_function(split_2, &countfree);
		if (!isa)
			break; /* Implement function isatty*/
	}
	if (linesize < 2)
		write(1, "\n", 1);
	return (free_list(head), free(line), 0);
}
