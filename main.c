#include "header.h"

int main(int argc, char **argv, char **env)
{
	char *buffer, *tok;
	char *dir = "/bin/";
	size_t size = 100;
	int c = 1;
	pid_t input;

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

/*attach buffer to fork here*/
		if (buffer != NULL)
		{
			input = fork();
			if (input < 0)
			{
				perror("Error with fork");
				return(1);
			}
			if (input == 0)
			{
				/* Token buffer */
				tok = strtok(buffer, " ");
				while (tok != NULL)
				{
					dir = _strcat(dir, tok);
					if (fileExhist(dir) == 0)
						execve(dir, tok, NULL);
					tok = strtok(NULL, " ");
				}
			}
			else
			{
				wait(0);
			}
		}
	}
	return (0);
}
