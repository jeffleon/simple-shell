#ifndef HOLB_H
#define HOLB_H
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct nodo
{
        char *direccion;
        struct nodo *next;
}dir;

char** split_word(char *cadena, int *countfree);
void free_function(char **from, int *countfree);
void execute_v(char **ln_cmd, long int *count_cmd, int *words);
char *print_integers(long int *j, int *retorno);
void errores(char *split_arg0, char *split_arg2, long int *count_cmd);

char *concat(char *direccion ,char *comand);
void _verification(dir **head, char **source);
dir *split_path(char *path, int *count_list);
dir *addnode(dir **head, char *aux);
char  *_catchPATH(char **environ);

#endif
