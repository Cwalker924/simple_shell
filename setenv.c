#include "header.h"

extern char **environ;

char *_getenv(const char *name)
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

int _setenv(const char *name, const char *value, int overwrite)
{
	int i;
	char *match;

	match = getenv(name);

	if (match == NULL)
	{
		/*add env;*/
		for (i = 0; environ[i] != NULL; i++)
		{
			;
		}
		environ[i] = ;
	}
	else
	{
		/**/
	}
	return(0);
}
