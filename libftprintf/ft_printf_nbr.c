/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:24:12 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/15 18:17:55 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(uintptr_t p, int fd)
{
	long int	hex;

	hex = (long int)p;
	if (p == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write(fd, "0x", 2);
	if (hex <= -1)
	{
		write(1, "f", 1);
		return (ft_puthex(hex, 1, 'x') + 3);
	}
	return (ft_puthex(p, 1, 'x') + 2);
}

char	ft_assign(long unsigned int a, char c)
{
	char	reverse;

	reverse = '\0';
	if (a % 16 < 10)
		reverse = a % 16 + 48;
	else if (c == 'X')
		reverse = a % 16 + 55;
	else if (c == 'x')
		reverse = a % 16 + 87;
	return (reverse);
}

int	ft_nbrlen_printf(long int a)
{
	int	i;

	i = 1;
	if (a == -2147483648)
		return (11);
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	while (a > 9)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int a, int fd)
{
	int		sign;
	char	c;

	sign = 1;
	if (a < 0)
	{
		write(fd, "-", 1);
		sign = -1;
	}
	if (a / 10)
		ft_putnbr(a / 10 * sign, fd);
	c = '0' + a % 10 * sign;
	write(fd, &c, 1);
	return (ft_nbrlen_printf(a));
}

int	ft_putunbr(unsigned int a, int fd)
{
	char	c;

	if (a / 10)
		ft_putunbr(a / 10, fd);
	c = '0' + a % 10;
	write(fd, &c, 1);
	return (ft_nbrlen_printf(a));
}
