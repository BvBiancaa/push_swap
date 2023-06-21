/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:14 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/30 17:07:39 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_array *array)
{
	int	last;
	int	*tmp;
	int	i;

	last = array->a_tot - 1;
	i = -1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->astack[0];
	while (++i < last)
		array->astack[i] = array->astack[i + 1];
	array->astack[last] = *tmp;
	free(tmp);
	if (array->check == 0)
		ft_printf("ra\n");
}

void	rraa(t_array *array)
{
	int	last;
	int	*tmp;

	last = array->a_tot - 1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->astack[last];
	while (last > 0)
	{
		array->astack[last] = array->astack[last - 1];
		last--;
	}
	array->astack[0] = *tmp;
	if (array->check == 0)
		ft_printf("rra\n");
	free(tmp);
}

void	rb(t_array *array)
{
	int	last;
	int	*tmp;
	int	i;

	last = array->b_tot;
	i = -1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->bstack[0];
	while (++i < last - 1)
		array->bstack[i] = array->bstack[i + 1];
	array->bstack[last - 1] = *tmp;
	free(tmp);
	if (array->check == 0)
		ft_printf("rb\n");
}

void	rrb(t_array *array)
{
	int	last;
	int	*tmp;

	last = array->b_tot - 1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->bstack[last];
	while (last > 0)
	{
		array->bstack[last] = array->bstack[last - 1];
		last--;
	}
	array->bstack[0] = *tmp;
	if (array->check == 0)
		ft_printf("rrb\n");
	free(tmp);
}

void	rrr(t_array *array)
{
	array->check = 1;
	rraa(array);
	rrb(array);
	ft_printf("rrr\n");
	array->check = 0;
}
