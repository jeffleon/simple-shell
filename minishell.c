#include "holberton.h"
/**
 * sighandler - main function
 * @signum:integer
 * Return: zero por
 */
void sighandler(int signum)
{
	write(1, "\n$", 2);
}
/**
 * main - main function
 * Return: zero
 */
int main(void)
{
	dir *head = NULL;
	size_t len = 0;
	char *line = NULL;
	ssize_t linesize = 0;
	char *_path = NULL;
	char **split_2 = NULL;
	int countfree = 0, count_list = 0;
	long int count_cmd = 0;
	extern char *environ[];
	char **test = NULL;

	_path = _catchPATH(environ);
	head = split_path(_path, &count_list);
	signal(SIGINT, sighandler);
	while (linesize != EOF)
	{
		if ((isatty(0)))
			write(1, "$", 1);
		linesize = getline(&line, &len, stdin);
		if (linesize > 1)
			line[linesize - 1] = '\0';
		else
			continue;
		count_cmd++;
		split_2 = split_word(line, &countfree);
		if (split_2 == NULL)
			continue;
		test = _verification(&head, split_2, &count_list);
		execute_v(test, &count_cmd, &countfree, split_2);
		free_function(test, &count_list);
		free_function(split_2, &countfree);
		if (!(isatty(0))) /* Implement function isatty*/
			break;
	}
	write(1, "\n", 1);
	free_list(head);
	free(line);
	return (0);
}
