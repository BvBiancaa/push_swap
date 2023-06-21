/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:36:59 by bmuni             #+#    #+#             */
/*   Updated: 2022/11/06 12:34:12 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int		a;
	int		x;
	int		q;
	char	*ret;

	a = ft_nbrlen(n);
	x = 0;
	ret = malloc(sizeof(char) * (a + 1));
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		ret[x++] = 45;
	}
	while (a > x)
	{
		q = (n / (ft_potenza(((a - x) - 1))) % 10);
		if (q < 0)
			q *= -1;
		ret[x++] = q + 48;
	}
	ret[x] = '\0';
	return (ret);
}
