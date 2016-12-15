#include "header.h"
#include <stdio.h>

int main(int argc, char *argv[], char *env)
{
	if (check_arg1(argc) == 1)
		return (1);

	while (1)
	{
		printf("cidfun$ ");
		raw_in = read_line(0);
		if (str_len(raw_in) != 0)
		{
			
		}
	}
}

int check_arg1(char argc)
{
	if (argc < 1)
	{
		printf("No args were entered");
		return (1)
	}
	return (0);
}
