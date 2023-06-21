/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:44:41 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 20:03:18 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shortino(t_array *array, int i)
{
	while (++i > array->a_tot / 2 && i < array->a_tot)
	{
		if (array->b_tot > 0)
		{
			if (array->astack[i] > array->bstack[0])
				rrr(array);
			else
				rraa(array);
		}
		else
			rraa(array);
	}
}

void	defaults(t_array *array, int i, int y)
{
	if (array->astack[i] != array->last_lis)
	{
		rraa(array);
		push_b(array);
	}
	order_array(array);
	array->bsub = malloc(sizeof(int) * y + 100);
	sorte(array);
}

void	cases(t_array *array, int *c, int i)
{
	check_shortest(array, i);
	*c = 1;
	push_b(array);
}

void	hello_darkness(t_array *array, int i, int x, int tot)
{
	array->adump[++x] = array->last_lis;
	array->bstack = malloc(sizeof(int) * (tot - x));
	array->tot_a = x;
	array->first_lis = array->astack[0];
	i = tot - x;
	array->tot_a = x + 1;
	divdi_et_impera(array, i);
}
