#include "holberton.h"
/**
 * sighandler - main function
 * @signum:integer
 * Return: zero por
 */
void sighandler(int signum)
{
	write(1, "\n$ ", 2);
}
/**
 * main - main function
 * Return: zero
 */
extern char *environ[];
int main(void)
{
	dir *head = NULL;
	size_t len = 0;
	ssize_t linesize = 0;
	char *_path = NULL, *word_wsp = NULL, *line = NULL;
	char **split_2 = NULL, **test = NULL;
	int countfree = 0, count_list = 0, count_sp = 0;
	long int count_cmd = 0;

	_path = _catchPATH(environ);
	head = split_path(_path, &count_list);
	signal(SIGINT, sighandler);
	while (linesize != EOF)
	{
		if ((isatty(0)))
			write(1, "$ ", 2);
		linesize = getline(&line, &len, stdin);
		if (linesize > 1)
			line[linesize - 1] = '\0';
		else
			continue;
		count_cmd++;
		word_wsp = delete_spaces(line, &count_sp);
		split_2 = split_word(word_wsp, &countfree);
		if (split_2 == NULL)
			continue;
		if (!(_strcmp(split_2[0], "exit")))
		{
			free_function(split_2, &countfree);
				break;
		}
		test = _verification(&head, split_2, &count_list);
		execute_v(test, &count_cmd, &countfree, split_2);
		free(word_wsp), free_function(test, &count_list);
		free_function(split_2, &countfree);
		if (!(isatty(0)))
			break; /* Implement function isatty*/
	}
	if (linesize < 2)
		write(1, "\n", 1);
	free_list(head), free(line);
}
