/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moonie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:48:36 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:45:02 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	canpush(t_array *array)
{
	int	shortest;
	int	i;

	i = 0;
	if (array->bdump[0] > max_five(array))
		pino_one(array, i);
	else if (array->bdump[0] == min_five(array))
	{
		shortest = array->dump[0];
		pino_two(array, i, shortest);
	}
	else
		pinot_all(array, i);
	return (0);
}

void	fin(t_array *array, int *i, int bpos, int *apos)
{
	while (*i < array->a_tot / 2 && array->bstack[bpos] < array->astack[*i])
	{
		*i += 1;
		*apos += 1;
	}	
}

void	if_int_the_world(t_array *array, int i, int x)
{
	while ((array->bstack[i] > array->astack[x]
			&& array->bstack[i] < array->astack[array->a_tot - x - 1]))
		x++;
	array->ab[i] = take_x(array, i, x,
			array->astack[array->a_tot - x - 1]);
}

void	order_array(t_array *array)
{
	int	p;

	p = -1;
	while (++p < array->a_tot)
	{
		if (array->astack[p] == max(array))
			break ;
	}
	if (p < (array->a_tot / 2))
	{
		while (--p >= -1)
			ra(array);
	}
	else
	{
		while (++p < array->a_tot)
			rraa(array);
	}
}
