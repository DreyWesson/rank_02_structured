#include <unistd.h>
#include <stdio.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}


void reverse_bit(unsigned char octet)
{
	int	i = 0;
	unsigned char 	bit;

	while (i++ < 8)
	{
		bit = (octet << i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main(void)
{
	print_bits(2);
	// write(1, "\n", 1);
	// reverse_bit(2);
	return (0);
}