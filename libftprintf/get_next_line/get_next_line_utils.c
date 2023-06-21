/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:48:46 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/21 10:13:51 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t size_of, size_t size)
{
	char	*alloc;
	size_t	i;

	i = 0;
	if (size_of == 0 || size == 0)
		return (NULL);
	alloc = malloc(size_of * size);
	if (!alloc)
		return (NULL);
	while (i < size)
	{
		alloc[i] = '\0';
		i++;
	}
	return (alloc);
}

int	ft_stlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[0] == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_stjoin(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*dest;

	i = -1;
	x = -1;
	if (s1 == NULL)
	{
		free(s1);
		return (s2);
	}
	if (s2 == NULL)
	{
		free(s2);
		return (s1);
	}
	dest = ft_calloc(1, ft_stlen(s1) + ft_stlen(s2) + 1);
	while (s1[++i])
		dest[i] = s1[i];
	free(s1);
	while (s2[++x])
		dest[i + x] = s2[x];
	free(s2);
	return (dest);
}

int	ft_checkn(char *str, int a)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	if ((a == 0 || a == 2))
		return (ft_stlen(str));
	if (str[0] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
