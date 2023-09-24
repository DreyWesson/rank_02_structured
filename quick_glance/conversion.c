#include <unistd.h>

// **** PRINT HEX *****
void	print_hex(int x)
{
	char	*ptr;

	ptr = "0123456789abcdef";
	if (x >= 16)
		print_hex(x / 16);
	write(1, &ptr[x % 16], 1);
}
// **** PRINT HEX END *****

// **** ATOI BASE *****
// char	to_lower(char c)
// {
// 	if (c >= 'A' && c <= 'Z')
// 		c += 32;
// 	return (c);
// }

// int	base(char c, int base)
// {
// 	char	*ptr;
// 	int		i;

// 	ptr = "0123456789abcdef";
// 	i = 0;
// 	while (i < base)
// 	{
// 		if (c == ptr[i])
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// int	atoi_base(const char *str, int str_base)
// {
// 	signed int	res;
// 	int			i;
// 	int			val;

// 	i = 0;
// 	res = 0;
// 	val = 0;
// 	while ((val = base(to_lower(str[i++]), str_base)) != -1)
// 	{
// 		res *= str_base;
// 		res += val;
// 	}
// 	return (res);
// }

int	base(int c, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	if (c >= 65 && c <= 97)
		c += 32;
	while (i < base)
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_base(char *str, int str_base)
{
	signed int	nbr;
	int			i;
	int			res;

	i = 0;
	while ((res = base(str[i++], str_base)) != -1)
		nbr = (nbr * str_base) + res;
	return (nbr);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}

// **** ATOI BASE END *****
int	main(int argc, char **argv)
{
	int x;

	// **** PRINT HEX *****
	if (argc == 2)
	{
		x = atoi(argv[1]);
		ft_putnbr(x);
		write(1, "\n", 1);
		print_hex(x);
	}
	write(1, "\n", 1);
	// **** ATOI BASE *****
	ft_putnbr(atoi_base("drey", 16));
	return (0);
}