int	alpha_mirror(int argc, char **argv)
{
	int	i;

	(void)argc;
	(void)argv;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = 'Z' - argv[1][i] + 'A';
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] = 'z' - argv[1][i] + 'a';
			write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}

void	rostring(void)
{
	// trim init spaces
	// save start and end of word
	// trim next spaces
	// loop through and write char but
}

void	rot_13(char *str)
{
	int j;

	while (*str)
	{
		j = *str;
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			j = *str + 13;
			if (*str >= 'a' && *str <= 'z' && j > 'z')
				j += 96 - 122;
			if (*str >= 'A' && *str <= 'Z' && j > 'Z')
				j += 64 - 90;
		}
		write(1, &j, 1);
		str++;
	}
}