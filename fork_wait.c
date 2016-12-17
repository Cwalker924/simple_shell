#include "header.h"

int main(int ac, char *av[], char *env)
{
	pid_t child, child2, child3, child4, child5;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	child = fork();
	if (child < 0)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		/*printf("child");*/
		child2 = fork();
		if (child2 < 0)
		{
			perror("Error:");
			return (1);
		}
		if (child2 == 0)
		{
			/*printf("child2");*/
			child3 = fork();
			if (child3 < 0)
			{
				perror("Error:");
				return (1);
			}
			if (child3 == 0)
			{
				/*printf("child3");*/
				child4 = fork();
				if (child4 < 0)
				{
					perror("Error:");
					return (1);
				}
				if (child4 == 0)
				{
					/*printf("child4");*/
					child5 = fork();
					if (child5 < 0)
					{
						perror("Error:");
						return (1);
					}
					if (child5 == 0)
					{
						/*printf("child5");*/
						if (execve(argv[0], argv, NULL) == -1)
						{
							perror("Error:");
						}
					}
					else
					{
						wait(0);
					}
					if (execve(argv[0], argv, NULL) == -1)
					{
						perror("Error:");
					}
				}
				else
				{
					wait(0);
				}
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error:");
				}
			}
			else
			{
				wait(0);
			}
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(0);
		}
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
