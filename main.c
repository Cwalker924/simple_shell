#include "header.h"

int main()
{
	char *buffer;
	size_t bufsize = 80;
	size_t characters;

	buffer = malloc(bufsize * sizeof(char));
	if (!buffer)
	{
		perror("unable to allocate buffer");
		exit(1);
	}

	printf("$>> ");
	characters = getline(&buffer, &bufsize, stdin);
	printf("%zu characters were read.\n", characters);
	printf("you typed: %s\n", buffer);

	return (0);
}
