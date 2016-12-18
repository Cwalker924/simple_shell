#include "header.h"

extern char **environ;
char *_getenv(const char *name)
{
	int i;
	char *env;

	for (i = 0; environ[i] != NULL; i++)
	{
		env = strtok(environ[i], "=");
		if (strcmp(env, name) == 0)
		{
			env = strtok(NULL, "=");
			return(env);
		}
	}

	return(NULL);
}

/**
 * bin_search - finds commands in bin dir
 *
 *
 *
 */
char *bin_search(void)
{
	char *path, *tok;
	int i;

	path = _getenv("SHELL");
	tok = strtok(path, ":");

	for (i = 0; tok != '\0'; i++)
	{
		return (tok);
		tok = strtok(NULL, ":");
	}
        return (NULL);
}



char main(void)
{
	char *bin, *tok, *dir;
	int i;

	dir = "bin";
	bin = bin_search();
	tok = strtok(bin, "/");
	for(i = 0; tok != NULL; i++)
	{
		/*printf("%s\n", tok);*/
		if ((strcmp(bin, tok) == 0))
			return (tok);
		/*printf("Ive got the bin and this is it >> %s", tok);*/
		tok = strtok(NULL, "/");
	}
	return(NULL);
}
