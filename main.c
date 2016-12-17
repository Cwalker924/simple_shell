#include "header.h"

int main(int argc, char *argv[], char *env)
{
	char *buffer, *cmd;
	size_t size = 100;
	int i, c = 1;
	pid_t input;

	const char delim[2] = " ";

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

		cmd = strtok(buffer, delim);
		while (cmd != NULL)
		{
			int ret;

			if (cmd == "ls")
				ret = execl("/bin/ls", "ls", NULL);
			cmd = strtok(NULL, delim);
		}
		/*adding here*/
		input = fork();
		if (input < 0)
		{
			perror("Error with fork");
			return(1);
		}
		if (input == 0)
		{
			/*add search input here*/
		}
		else
			wait(0);
	}
	return (0);
}
