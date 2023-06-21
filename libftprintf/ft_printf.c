/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:01:03 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/11 13:59:44 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int a, int fd)
{
	write(fd, &a, 1);
	return (1);
}

int	ft_puthex(unsigned long int a, int fd, char c)
{
	char	*reverse;
	int		i;
	int		b;

	i = -1;
	if (a == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	a *= 16;
	reverse = malloc(1 * 21);
	while ((a / 16) != 0)
	{
		a /= 16;
		reverse[++i] = ft_assign(a, c);
	}
	reverse[++i] = ft_assign(a, c);
	b = i;
	while (--i >= 0)
		write(fd, &reverse[i], 1);
	free(reverse);
	return (b);
}

int	ft_putstr(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		c = s[i];
		ft_putchar(c, fd);
		i++;
	}
	return (i);
}

int	ft_checkletter(const char *s, int i, va_list a)
{
	int	ret;

	ret = 0;
	if (s[i] == 'c')
		ret += ft_putchar(va_arg(a, int), 1);
	else if (s[i] == 's')
		ret += ft_putstr(va_arg(a, char *), 1);
	else if (s[i] == 'p')
		ret += ft_putvoid(va_arg(a, uintptr_t), 1);
	else if (s[i] == 'd' || s[i] == 'i')
		ret += ft_putnbr(va_arg(a, int), 1);
	else if (s[i] == 'u')
		ret += ft_putunbr(va_arg(a, unsigned int), 1);
	else if (s[i] == 'x')
		ret += ft_puthex(va_arg(a, unsigned int), 1, 'x');
	else if (s[i] == 'X')
		ret += ft_puthex(va_arg(a, unsigned int), 1, 'X');
	else if (s[i] == '%')
		ret += ft_putchar('%', 1);
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	a;
	int		i;
	int		fd;
	int		len;

	len = 0;
	fd = 1;
	i = -1;
	va_start(a, s);
	while (s[++i])
	{
		if (s[i] == '%')
			len += ft_checkletter(s, ++i, a);
		else
		{
			write(fd, &s[i], 1);
			len++;
		}
	}
	va_end(a);
	return (len);
}
