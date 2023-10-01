int	atoi(char *ptr)
{
	int		res;
	char	sign;

	res = 0;
	sign = 1;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-')
		sign = -1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr)
	{
		res = (res * 10) + (*ptr - '0');
		ptr++;
	}
	return (res * sign);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	n = (n % 10) + '0';
	write(1, &n, 1);
}

void	print_bits(unsigned char octet)
{
	unsigned char	c;
	int				i;

	i = 8;
	while (i--)
	{
		c = (octet >> i & 1) + '0';
		write(1, &c, 1);
	}
}

char	*ft_itoa(int nbr)
{
	// check if its out of bound
	// check number_len and if negative add 1 more to len
	// allocate memory and null terminate it
	// if num is zero allocate zero to index 0 and return
	//  if num is -ve allocate the sign to 0 index and multiply number by
	// -ve sign
	// do d conversion
	// while (nbr)
	// {
	// 	res[i--] = (nbr % 10) + '0';
	// 	nbr /= 10;
	// }
}