#include "header.h"

int main(int ac, char *av[], char *env)
{
	pid_t child = fork();
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	if (child < 0)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		printf("child");
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(0);
	}
	return (0);
}
