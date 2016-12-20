#include "header.h"

int main(int argc, char **argv[])
{
	int ret;

	printf("Calling execl...\n");
	ret = execl("/usr/bin/env", "env", NULL);
	printf("failed to call execl... ret = %d\n", ret);

	return (0);
}
