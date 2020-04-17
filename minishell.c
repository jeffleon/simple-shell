#include "holberton.h"
/**
 * sighandler - main function
 * @sighandler:integer
 * Return: void
 */
void sighandler(int sighandler)
{
	(void)sighandler;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - main function mi
 * Return: zero mo
 */
int main(void)
{
	dir *head = NULL, *head_env = NULL;
	size_t len = 0;
	ssize_t linesize = 0;
	char *_path = NULL, *word_wsp = NULL, *line = NULL;
	char **split_2 = NULL, **test = NULL;
	int countfree = 0, count_list = 0, count_sp = 0, built_in_ent = 0
		, isa = 0, error = 0;
	long int count_cmd = 0;

	_path = _catchPATH(environ);
	head = split_path(_path, &count_list), signal(SIGINT, sighandler);
	head_env = lk_lst_env(environ);
	for (isa = isatty(0); linesize != EOF; count_cmd++)
	{
		if (isa)
			write(1, "$ ", 3);
		linesize = getline(&line, &len, stdin);
		if (linesize == EOF)
			break;
		if (linesize > 1)
			line[linesize - 1] = '\0';
		word_wsp = delete_spaces(line, &count_sp);
		if (word_wsp == NULL || *word_wsp == '\0' || *word_wsp == '\n')
		{
			free(word_wsp);
			continue;
		}
		split_2 = split_word(word_wsp, &countfree);
		_salir_(line, word_wsp, split_2, &countfree, head, error, _path, head_env);
		built_in_ent = _selection(split_2, &head_env, &head, &count_cmd);
		test = _verification(&head, split_2[0], &count_list);
		if (built_in_ent == 0)
			error = execute_v(test, &count_cmd, &countfree, split_2,
				  environ);
		free(word_wsp), free_function(test, &count_list);
		free_function(split_2, &countfree);
	}
	if (isa)
		write(STDOUT_FILENO, "\n", 2);
	return (free(line), free(_path), free_list(head_env), free_list(head), error);
}
