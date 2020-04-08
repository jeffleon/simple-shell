#include "holberton.h"
/**
 * main - main function
 * Return: zero
 */

void sighandler(int signum)
{
	write(1, "\n$", 2);
        return;
}
int main(void)
{
	size_t len = 0;
	char *line = NULL;
	ssize_t linesize = 0;
	char **split_2 = NULL;
	int countfree = 0;
	long int count_cmd = 0;

	signal(SIGINT, sighandler);
	while(linesize != EOF)
	{
		write(1, "$", 1);
		linesize = getline(&line, &len, stdin);
		if (linesize > 1)
			line[linesize -1] = '\0';
		else
			continue;
		count_cmd++;
		split_2 = split_word(line, &countfree);
		if (split_2 == NULL)
			continue;
		execute_v(split_2, &count_cmd, &countfree);
		wait(NULL);
		free_function(split_2, &countfree);
	}
	write(1,"\n",1);
	free(line);
	return (0);
}
