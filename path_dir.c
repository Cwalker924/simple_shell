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

char *pars_path_dir(const char *name)
{
	char *dir, *single_dir;

	dir = getenv(name);

	single_dir = strtok(dir, ":");
	while (single_dir != NULL)
	{
		printf("%s\n", single_dir);
		single_dir = strtok(NULL, ":");
	}
	return(NULL);
}
/*
int main(void)
{
	/*printf("%s\n", getenv("PATH"));*/
	/*printf("%s\n", pars_path_dir("PATH"));*/
//	pars_path_dir("PATH");
//	return (0);
//}
