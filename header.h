#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_getenv(const char *name);
char *_strcat(char *dest, char *src);
int fileExists(const char *file);
int _strcmp(char *s1, char *s2);

/**
 * struct flag -flag cmd
 * @letter: flag char
 * @prnt: print function pointer
 * Descriptions: contains flag letter and corresponding cmd function
 **/
typedef struct flag
{
	char cmd;
	int (*ex_ec)(va_list *);
} find_cmd;

/**/
typedef struct node{
	char *dirdir;
	struct node *next;
} node;

#endif
