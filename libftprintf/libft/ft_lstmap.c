/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:37:28 by bmuni             #+#    #+#             */
/*   Updated: 2022/10/09 19:23:24 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copia;
	t_list	*uno;

	if (lst == NULL)
		return (NULL);
	copia = NULL;
	while (lst != NULL)
	{
		uno = ft_lstnew((*f)(lst->content));
		if (uno == NULL)
			ft_lstclear(&uno, (*del));
		else
			ft_lstadd_back(&copia, uno);
		lst = lst->next;
	}
	return (copia);
}
