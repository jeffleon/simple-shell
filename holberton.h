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
#include <fcntl.h>


/**
 * struct nodo - struct
 * @direccion:address stored of each node
 * @next:pointer to next node
 */
typedef struct nodo
{
	char *direccion;
	struct nodo *next;
} dir;


/**
 * struct built - struct
 * @comandokey:select the function
 * @func: a pointer to function
 */
typedef struct built
{
	char *comandokey;
	int (*func)(char **source, char **environ, dir **test
		    , long int *count_cmd);
} built_in;

extern char *environ[];
char **split_word(char *cadena, int *countfree);
void free_function(char **from, int *countfree);
void execute_v(char **ln_cmd, long int *count_cmd
	       , int *words, char **source, char **environ);
char *print_integers(long int *j, int *retorno);
void errores(char *split_arg0, char *split_arg2, long int *count_cmd);
char *_concat(char *direccion, char *comand);
char **_verification(dir **head, char *source, int *pointer);
dir *split_path(char *path, int *count_list);
dir *addnode(dir **head, char *aux);
char  *_catchPATH(char **environ);
void free_list(dir *head);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *delete_spaces(char *elm_spc, int *count_words);

char *_union(long int *count_cmd, int *sizenum);

int _cd(char **source, char **environ, dir **test, long int *count_cmd);
int _which(char **source, char **environ, dir **test, long int *count_cmd);
int _help(char **source, char **environ, dir **test, long int *count_cmd);
int _selection(char **source, char **environ, dir **test, long int *count_cmd);
int _salir_(char *line, char *word_wsp, char **split_2, int *countfree
	    , dir *head);
int _env(char **source, char **environ, dir **test, long int *count_cmd);
void aux_errores(int a, int *words, char **source, long int *count_cmd);



#endif
