#include <unistd.h>

void			print_bits(unsigned char octet);

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8; // bcos int is 8 bits
	while (i--)
	{
		// '0' to convert number to char printable by write,
		// >> to move thru each bit of octet
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

unsigned char	swap_bits(unsigned char octet)
{
	// sample swap in halfs try outer forms
	return ((octet >> 4) | (octet << 4));
}

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i > 0)
	{
		res = (res * 2) + (octet % 2);
		octet /= 2;
		i--;
	}
	return (res);
}

int	main(void)
{
	int i;

	i = 2;
	print_bits(i);
	write(1, "\n", 1);
	print_bits(swap_bits(i));
	write(1, "\n", 1);
	print_bits(reverse_bits(i));
	return (0);
}