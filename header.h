#ifndef SHELL
#define SHELL

typedef struct node{
	char *dirdir;
	struct node *next;
} node;

typedef struct addnode{
	const char *name;
	const char *value;
	struct node *next;
} link_env;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#endif
