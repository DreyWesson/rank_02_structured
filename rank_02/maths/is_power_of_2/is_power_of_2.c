int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	return ((n == 1) ? 1 : 0);
}

long	ft_pow(int d, int e)
{
	long	res;

	res = 1;
	if (e == 0)
		return (1);
	e--;
	while (e-- >= 0)
		res *= d;
	return (res);
}
