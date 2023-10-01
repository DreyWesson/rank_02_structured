/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:09:07 by gcomlan           #+#    #+#             */
/*   Updated: 2023/09/30 23:55:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> // For va_lis, va_start, va_arg, va_copy, va_end
#include <unistd.h> // For malloc, free, write
#include <stdio.h>

void ft_putstr(char *str, int *len)
{	
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void putnbr(long long int nbr, int base, int *len)
{
	char *ptr = "0123456789abcdef";
	
	if (nbr < 0)
	{
		nbr = -nbr;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		putnbr((nbr / base), base, len);
	*len += write(1, &ptr[nbr % base], 1);
}

int ft_printf(const char *format, ...)
{
	int len;
	va_list args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &len);
			else if (*format == 'd')
				putnbr((long long int)va_arg(args, int), 10, &len);
			else if (*format == 'x')
				putnbr((long long int)va_arg(args, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

int main()
{
	char *i = "drey\n";
    int j = 0;

	j = ft_printf("%s\n", i);
	printf("%d\n", j);
	return (0);
}