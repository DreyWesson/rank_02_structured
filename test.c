/**
 * C program to find sum of prime numbers between 1 to n
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	n;

	n = 0;
	while (*str != '\0')
	{
		n = (n * 10) + (*str - '0');
		++str;
	}
	return (n);
}

int	base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int	atoi_base(char *str, int str_base)
{
	signed int	nbr;
	int			i;

	// char		is_neg;
	i = 0;
	nbr = 0;
	// trim_space(str, &i);
	// is_neg = handle_sign(str, &i);
	while (base(str[i], str_base) != -1)
	{
		nbr *= str_base;
		nbr += base(str[i], str_base);
		i++;
	}
	// if (is_neg == 'y')
	// 	return (-nbr);
	return (nbr);
}

int	ft_putnbr(int n)
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
	return (0);
}

int	add_prime(void)
{
	int i, j, end, isPrime, sum = 0;
	end = 5;
	i = 2;
	while (i <= end)
	{
		isPrime = 1;
		j = 2;
		while (j <= i / 2)
		{
			if (i % j == 0)
			{
				isPrime = 0;
				break ;
			}
			j++;
		}
		if (isPrime == 1)
			sum += i;
		i++;
	}
	printf("Sum of all prime numbers between 1 to %d = %d", end, sum);
	return (0);
}

int	ft_prime(int argc, char *argv[])
{
	int	i;
	int	number;

	if (argc == 2)
	{
		number = atoi(argv[1]);
		if (number == 1)
			printf("1");
		i = 2;
		while (number >= i)
		{
			if (number % i == 0)
			{
				printf("%d", i);
				if (number != i)
					printf("*");
				number /= i;
				i--;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}

int	main(void)
{
	printf("%d\n", atoi_base("d", 16));
	return (0);
}