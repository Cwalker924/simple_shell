#include "header.h"

int main(int ac, char *av[])
{
	pid_t child = fork();

	if (child < 0)
		perror("something went wrong with forking\n");
	if (child > 0)
	{
		wait(0);
		printf("hey im the parent(%d)\n", getpid());
	}
	else
	{
		printf("im the child(%d)\n", getpid());
		execl("/bin/echo", "echo", "hello", "world", NULL);
	}
}
