#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int do_op(int argc, char *argv[])
{
    /// @note needs ATOI and PUTNBR
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			printf("%d", (atoi(argv[1]) + atoi(argv[3])));
		if (argv[2][0] == '-')
			printf("%d", (atoi(argv[1]) - atoi(argv[3])));
		if (argv[2][0] == '*')
			printf("%d", (atoi(argv[1]) * atoi(argv[3])));
		if (argv[2][0] == '/')
			printf("%d", (atoi(argv[1]) / atoi(argv[3])));
		if (argv[2][0] == '%')
			printf("%d", (atoi(argv[1]) % atoi(argv[3])));
	}
	printf("\n");
	return (0);
}

int is_prime(int num)
{
    /// @note needs ATOI and PUTNBR
    int i = 0;
    int res = 0;

    while (i <= num)
    {
        if ((i % 2 && i != 1) || i == 2)
            res += i;
        i++;
    }
    printf("%d\n", res);
    return (res);
}

void ft_prime(int num)
{
    int i;

    if (num == 1)
    {
        write(1, "1", 1);
        return ;
    }
    i = 2;
    while (num >= i)
    {
        if (num % i == 0)
        {
            printf("%d", i);
            if (num != i)
                printf("*");
            num /= i;
            i--;
        }
        i++;
    }
    
}

int is_power_2(int num)
{
    if (num == 0)
        return (0);
    while (num % 2 == 0)
        num /= 2;
    return (num == 1 ? 1 : 0);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int n;

    if (a == 0 || b == 0)
        return (0);
    n = (a > b) ? a : b;
    while (1)
    {
        if (n % a == 0 && n % b == 0)
            return (n);
        n++;
    }
}

int		pgcd(int tab, int len)
{
	int i;

	i = tab < len ? tab : len;
	while (i)
	{
		if (tab % i == 0 && len % i == 0)
			return (i);
		i--;
	}
	return (0);
}

int     *ft_range(int start, int end)
{
	int range;
	int *ptr;
	int i;

	range = (end - start);
	range = (range < 0) ? (range * -1) : range;
	printf("%d\n", range);
	ptr = (int *)malloc((sizeof(int) * range) + 1);
	i = 0;
	if (start > end)
	{
		while (start >= end)
		{
			ptr[i] = start;
			i++;
			start--;
		}
	}
	else
	{
		while (start <= end)
		{

			ptr[i] = start;
			i++;
			start++;
		}
	}
	
	return (ptr);
}

int *ft_rrange(int start, int end)
{
	int *range;
	int i = 0;
	int n = end - start + 1;

	if (start > end)
		return (ft_rrange(end, start));
	range = (int *)malloc(sizeof(int) * n);
	if (range)
	{
		while (i < n)
		{
			range[i] = end;
			end--;
			i++;
		}
	}
	return (range);
}

int		max(int* tab, unsigned int len)
{
	int max;
	int i;

	max = tab[0];
	i = 0;
	while (i < len)
	{
		max = max > tab[i] ? max : tab[i];
		i++;
	}
	return (max);
}

int main()
{
    is_prime(5);
    return (0);
}