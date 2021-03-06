#include "header.h"

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

node *path_ll(const char *name)
{
	node *addnode, *head, *temp;
	int i;
	char *dir, *pass_to_dir;

	pass_to_dir = getenv("PATH");
	dir = strtok(pass_to_dir, ":");
	head = NULL;

	for (i = 0; dir != NULL; i++)
	{
		addnode = malloc(sizeof(node));
		if (!addnode)
			return (NULL);
		addnode->dirdir = dir;
		addnode->next = head;
		head = addnode;
		dir = strtok(NULL, ":");
//		printf("%s\n", addnode->dirdir);
	}
	return (*head);
}

int main(void)
{
//	printf("%s\n", path_ll("PATH"));
	path_ll("PATH");
	return (0);
}
