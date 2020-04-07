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

typedef struct comando {

char *direccion;
struct comando *next;

}path;

char** split_word(char *cadena, int *countfree);
void free_function(char **from, int *countfree);
void execute_v(char **ln_cmd, int *count_cmd);
#endif
