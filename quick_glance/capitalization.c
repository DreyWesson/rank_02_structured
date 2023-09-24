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