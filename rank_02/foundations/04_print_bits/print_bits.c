#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

void	reverse_bit(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 0;
	while (i++ < 8)
	{
		bit = (octet << i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main(void)
{
	print_bits(2);
	// write(1, "\n", 1);
	// reverse_bit(2);
	return (0);
}