/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:10:26 by bmuni             #+#    #+#             */
/*   Updated: 2022/10/06 16:29:12 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		n;

	i = 0;
	n = -1;
	while (str[i])
	{
		if (str[i] == c)
			n = i;
		i++;
	}
	if (str[i] == c)
		return ((char *) str + i);
	else if (n == -1)
		return (NULL);
	else
		return ((char *) str + n);
}
