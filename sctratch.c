/* child in forking */
if (input == 0)
{
	for (a = 0; argv[a] != NULL; a++)
	{
		cmd = _strcat(dir, argv[a]);
		if (fileExists(cmd) == 0)
			if (execve(argv[a], argv, NULL) == -1)
			{
				perror(av[1]);
			}
	}
}
