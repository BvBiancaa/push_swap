/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:04:47 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/09 16:40:42 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_charjoin(char const *s1, char c)
{
	int		i;
	char	*ret;

	i = -1;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!ret)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	if (c != '\0')
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}
