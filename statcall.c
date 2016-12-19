#include "header.h"

/**
 * Check if a file exists
 * @return true if and only if the file exists, false else
 */
int fileExists(const char *file)
{
	struct stat buf;
	if (stat(file, &buf) == 0)
	{
		/*printf("the file was found.\n");*/
		return (0);
	}
	else
	{
		/*printf("file does NOT exist");*/
		return (1);
	}
	return (0);
}
/*
int main(void)
{

	fileExists("/bin/ls");
	return (0);
}
*/
