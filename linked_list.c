#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct node{
	char *dirdir;
	struct node *next;
} node;

extern char **environ;

char *getenv(const char *name)
{
	int i;
	char *pth;

	for (i = 0; environ[i] != NULL; i++)
	{
		pth = strtok(environ[i], "=");
		if (strcmp(pth, name) == 0)
		{
			pth = strtok(NULL, "=");
			return(pth);
		}
	}
	return (NULL);
}

int main(void)
{
	node *addnode, *head;
	int i;
	char *dir, *pass_to_dir;

	pass_to_dir = getenv("PATH");
	dir = strtok(pass_to_dir, ":");

	for (i = 0; dir != NULL; i++)
	{
		addnode = malloc(sizeof(node));
		if (!addnode)
			return (1);
		addnode->dirdir = dir;
		addnode->next = head;
		head = addnode;
		dir = strtok(NULL, ":");
		printf("%s\n", addnode->dirdir);
		dir = strtok(NULL, ":");
	}
	return (0);
}
