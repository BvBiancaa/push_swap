/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:55:24 by bmuni             #+#    #+#             */
/*   Updated: 2022/10/09 19:05:17 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*uno;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	uno = ft_lstlast(*lst);
	uno->next = new;
}
