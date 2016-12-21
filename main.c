#include "header.h"

extern char **environ;

int main(int ac, char **av)
{
	char *buffer, *cmd, *argv[1024];
	/*char *dir = "/bin/";*/
	size_t size = 100;
	int c = 1, i;
	pid_t input;

	ac--;
	while (1)
	{
		buffer = malloc(sizeof(char) * size);
		if (buffer == NULL)
		{
			free(buffer);
			exit(1);
		}

		printf("#cisfun$ ");
		c = getline(&buffer, &size, stdin);

		if (c == EOF)
		{
			printf("EOF\n");
			free(buffer);
			exit(0);
		}

		/* add tok and args */
		argv[0] = strtok(buffer, " \t\n");
		for (i = 1; argv[i - 1] != NULL; i++)
		{
			argv[i] = strtok(NULL, " \t\n");
		}
		i--;

		if (_strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}
/* attach buffer to fork here */
		input = fork();
		if (input < 0)
		{
			perror("Error with fork");
			exit(-1);
		}
		if (input == 0)
		{
			if (_strcmp(argv[0], "env") == 0)
			{
				execl("/usr/bin/env", "env", NULL);
			}
			cmd = pars_path_dir(argv[0]);
			if (fileExists(cmd) == 0)
			{
				if (execve(cmd, argv, NULL) == -1)
				{
					perror(av[0]);
				}
			}
			else
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror(av[0]);
				}
			}
		}
		else
		{
			wait(0);
		}
	}
	free(buffer);
	return (0);
}
