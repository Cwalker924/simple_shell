#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *pars_path_dir(char *argv);
char *_getenv(const char *name);
char *_strcat(char *dest, char *src);
int fileExists(const char *file);
int _strcmp(char *s1, char *s2);

/**/
typedef struct node{
	char *dirdir;
	struct node *next;
} node;

#endif
