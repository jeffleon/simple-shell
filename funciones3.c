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
}
