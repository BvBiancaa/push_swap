/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:40 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:42:53 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	take_x_p2(t_array *array, int x)
{
	if (array->astack[0] > array->astack[x]
		&& array->astack[array->a_tot - 1] > array->astack[array->a_tot - x])
		return (x *= -1);
	else
		return (x);
}

void	one(t_array *array, int x, int i)
{
	while (x < array->a_tot)
	{
		x++;
		if (array->astack[x] == max(array))
			break ;
	}
	if (x < (array->a_tot) / 2)
		array->ab[i] = x + 1;
	else
		array->ab[i] = x - (array->a_tot - 1);
}

void	do_bee(t_array *array)
{
	int	i;

	array->b = malloc(sizeof(int) * array->b_tot);
	array->ab = malloc(sizeof(int) * array->b_tot);
	i = -1;
	while (++i <= array->b_tot - 1)
	{
		if (i <= (array->b_tot) / 2)
			array->b[i] = i;
		else
			array->b[i] = i - (array->b_tot);
	}
}

void	two(t_array *array, int i, int x)
{
	while ((array->bstack[i] > array->astack[x]
			&& array->bstack[i] > array->astack[array->a_tot -1 - x]))
		x++;
	if (array->bstack[i] > array->astack[x]
		&& array->astack[array->a_tot - 1 - x] == max(array))
	{
		while (array->bstack[i] > array->astack[x])
			x++;
		if (x > array->a_tot / 2)
			array->ab[i] = x - (array->a_tot);
		else
			array->ab[i] = x;
	}
	else
		array->ab[i] = take_x(array, i, x, array->astack[array->a_tot - 1 - x]);
}

void	three(t_array *array, int i, int x)
{
	while ((array->bstack[i] < array->astack[x]
			&& array->bstack[i] < array->astack[array->a_tot - 1 - x]))
		x++;
	if (array->bstack[i] < array->astack[array->a_tot - 1 - x]
		&& array->bstack[i] > array->astack[x])
	{
		while (array->bstack[i] > array->astack[x])
			x++;
		if (x > array->a_tot / 2)
			array->ab[i] = x - (array->a_tot);
		else
			array->ab[i] = x;
	}
	else
		array->ab[i] = take_x(array, i, x, array->astack[array->a_tot - 1 - x]);
}
