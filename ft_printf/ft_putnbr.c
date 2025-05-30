/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:23:08 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/11/09 17:23:13 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		count += ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
		count += ft_putnbr(n);
	}
	else if (n > 9)
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	else
	{
		count += ft_putchar(n + '0');
	}
	return (count);
}

int	ft_putdouble(int number)
{
	int		i;
	int		count;
	int		int_part;

	count = 0;
	i = 0;
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
		if (number == -2147483648)
			return (count + ft_putstr("2147483648"));
	}
	if (number == 2147483647)
		return (count + ft_putstr("2147483647"));
	int_part = (int)number;
	count += ft_putnbr(int_part);
	return (count);
}

int	ft_putunsigned(unsigned int number)
{
	int	count;

	count = 0;
	if (number >= 10)
		count += ft_putunsigned(number / 10);
	count += ft_putchar(number % 10 + '0');
	return (count);
}
