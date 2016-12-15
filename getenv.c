#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int main(void)
{
	printf("%s\n", _getenv("PATH"));
	return (0);
}
