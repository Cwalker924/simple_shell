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
/**
 * Returns(char *)
 * /usr/local/sbin/usr/local/bin/usr/sbin/usr/bin/sbin/bin/usr
 * /games/usr/local/games
 *
 * Tok and create LinkList
 */
char *path_ll(char *argv)
{
	node *addnode, *head;
	int i;
	char *dir, *pass_to_dir, *sing_dir;

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

		sing_dir = _strcat(addnode->dirdir, argv[0]);
		if (fileExists(sing_dir) == 0)
		{
			return(sing_dir);
		}

		dir = strtok(NULL, ":");
		//printf("%s\n", addnode->dirdir);
	}
	return (NULL);
}
