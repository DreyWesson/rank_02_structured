void	ulstr(char *str)
{
	int j;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			j = *str - 32;
		if (*str >= 'A' && *str <= 'Z')
			j = *str + 32;
		write(1, &j, 1);
		str++;
	}
}

int camel_to_snake(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while(argv[1][i])
		{
			if(argv[1][i] >= 65 && argv[1][i] <= 90)
			{
				argv[1][i] = argv[1][i] + 32;
				write (1, "_", 1);
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}

int snake_to_camel(int argc, char **argv)
{
	int i = 0;
	
	if (argc ==2 )
	{
		while(argv[1][i] != '\0')
		{
			if (argv[1][i] == '_')
			{
				i++;
				argv[1][i] = argv[1][i]-32;
			}
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
