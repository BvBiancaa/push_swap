/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:04 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/30 17:04:27 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_bb(t_array *array)
{
	int	i;

	i = 0;
	if (array->dump != NULL)
	{
		array->astack2 = malloc (sizeof(int) * array->b_tot + 4);
		array->astack2[0] = array->dump[0];
		while (++i < array->b_tot)
			array->astack2[i] = array->bdump[i - 1];
		i = -1;
		while (++i < array->b_tot)
			array->bdump[i] = array->astack2[i];
		ft_printf("pb\n");
		free(array->astack2);
		delete_dump(array);
	}
	else
		return ;
}

int	is_min(t_array *array, int i)
{
	int	a;

	a = -1;
	while (++a < array->a_tot)
	{
		if (array->astack[a] < array->bstack[i])
			return (1);
	}
	return (0);
}

int	is_max(t_array *array, int i)
{
	int	a;

	a = -1;
	while (++a < array->a_tot)
	{
		if (array->astack[a] > array->bstack[i])
			return (1);
	}
	return (0);
}

int	max(t_array *array)
{
	int	i;
	int	last;

	i = 0;
	last = array->astack[0];
	while (i < array->a_tot - 1)
	{
		if (array->astack[i] > last)
			last = array->astack[i];
		i++;
	}
	if (array->astack[array->a_tot - 1] > last)
		last = array->astack[array->a_tot - 1];
	return (last);
}

int	check(t_array *array, int x)
{
	int	i;

	i = -1;
	while (++i < array->tot_a)
	{
		if (array->adump[i] == x)
			return (1);
	}
	return (0);
}
