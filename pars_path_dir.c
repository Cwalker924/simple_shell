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
			return (pth);
		}
	}
	return (NULL);
}

char *pars_path_dir(char *argv)
{
	char *dir, *single_dir, *dir_cat, *dup_slash, *dir_dup;

	dir = getenv("PATH");

	single_dir = strtok(dir, ":");
	while (single_dir != NULL)
	{
		dir_dup = strdup(single_dir);
		dup_slash = _strcat(dir_dup, "/");
		dir_cat = _strcat(dup_slash, argv);

		if (fileExists(dir_cat) == 0)
		{
			return(dir_cat);
		}

		single_dir = strtok(NULL, ":");
	}
	return (NULL);
}
