#include "holberton.h"
/**
 * free_list - adds a
 * @head: pointer
 *
 */
void free_list(dir *head)
{
	if (head != NULL)
	{
		free(head->direccion);
		free_list(head->next);
		free(head);
	}
}
