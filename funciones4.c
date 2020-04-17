#include "holberton.h"
/**
 * _strlen - measure string length.
 * @s: value to size.
 * Return: string length.
 */
int _strlen(char *s)
{
	int count = 0;

	for (; s[count]; count++)
		;

	return (count);
}
