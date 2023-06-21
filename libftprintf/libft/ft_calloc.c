/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:34:15 by bmuni             #+#    #+#             */
/*   Updated: 2022/10/05 17:39:14 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t num, size_t dim)
{
	void	*ret;

	ret = (void *)malloc(dim * num);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, num * dim);
	return (ret);
}
