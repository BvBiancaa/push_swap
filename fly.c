/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fly.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:46:46 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:44:39 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lollo(t_array *array, int i, int x)
{
	if (array->bdump[0] > array->dump[i])
		five_func(array, i);
	else if (array->bdump[0] < array->dump[1 + x - i]
		&& array->bdump[0] != min_five(array))
		five_func_two(array, i, x);
	else
		push_aa(array);
}

void	sort_three_from_five(t_array *array)
{
	int	f;
	int	m;
	int	l;

	f = array->dump[0];
	m = array->dump[1];
	l = array->dump[2];
	if (f < l && f < m && l < m)
	{
		rra(array);
		swap_a(array);
	}
	else if (f > m && f < l && m < l)
		swap_a(array);
	else if (f < m && f > l && m > l)
		rra(array);
	else if (f > m && f > l && m < l)
		rafive(array);
	else if (f > m && f > l && m > l)
	{
		swap_a(array);
		rra(array);
	}
}

int	min_five(t_array *array)
{
	int	i;
	int	last;

	i = 0;
	last = array->dump[0];
	while (i < array->a_tot - 1)
	{
		if (array->dump[i] < last)
			last = array->dump[i];
		i++;
	}
	if (array->dump[array->a_tot - 1] < last)
		last = array->dump[array->a_tot - 1];
	if (array->bdump[0] < last)
		last = array->bdump[0];
	return (last);
}

void	check_five(t_array *array)
{
	int	i;
	int	current;

	current = 0;
	while (current < 4)
	{
		i = current + 1;
		while (array->dump[current] != array->dump[i] && i < 4)
			i++;
		if (array->dump[current] == array->dump[i])
		{
			free(array->astack);
			free(array->dump);
			free(array->bdump);
			exit (write(2, "Error\n", 6));
		}
		current++;
	}
}

void	order_five(t_array *array)
{
	int	p;

	p = -1;
	while (++p < array->a_tot - 1)
	{
		if (array->dump[p] == max_five(array))
			break ;
	}
	if (p == 0)
		rafive(array);
	else if (p <= array->a_tot / 2)
	{
		while (--p >= -1)
			rafive(array);
	}
	else
	{
		while (++p <= array->a_tot)
			rra(array);
	}
}
