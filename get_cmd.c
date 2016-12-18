int get_command(char tok, /*va_list *ap*/)
{
	int i;
	find_cmd flags[] = {
		{"ls", /*env*/},
		{"", env},
		{"", env},
		{"", env},
		{"", env},
		{NULL, NULL}
	};

	for (i = 0; flags[i].cmd != NULL; i++)
	{
		if (flags[i].cmd == tok)
		{
			return (flags[i].ex_ec(/*ap*/));
		}
	}
	return (0);
}
