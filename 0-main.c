#include "holberton.h"


int main(void)
{
	extern char *environ[];
	char *_path = NULL;

	_path =(char *)_catchPATH(environ);
	//no necesita liberar nada
	//split_path(path);
	return(0);
}
