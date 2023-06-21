/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enacoid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:44:48 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:44:39 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pinot_all(t_array *array, int i)
{
	if (array->bdump[0] > array->dump[3]
		&& array->bdump[0] < array->dump[0])
		push_aa(array);
	else if (array->bdump[0] < array->dump[3]
		&& array->bdump[0] > array->dump[0]
		&& array->dump[0] < array->dump[1])
		pino_three(array, i);
	else if (array->bdump[0] > array->dump[3]
		&& array->bdump[0] > array->dump[0]
		&& array->dump[0] < array->dump[1])
		pino_four(array, i);
	else if (array->bdump[0] < array->dump[3]
		&& array->bdump[0] < array->dump[0]
		&& array->dump[0] < array->dump[1])
		pino_five(array, i);
	else
	{
		rafive(array);
		push_aa(array);
	}
}

void	five_func(t_array *array, int i)
{
	while (i < 5 && array->bdump[0] > array->dump[i])
		i++;
	if (i < 3)
	{
		while (i > 0)
		{
			rafive(array);
			i--;
		}
	}
	else
	{
		while (i - 4 < 0)
		{
			rra(array);
			i++;
		}
	}
	push_aa(array);
}

void	five_func_two(t_array *array, int i, int x)
{
	while (i > -5 && array->bdump[0] < array->dump[1 + x - i])
		i--;
	if (i >= -3)
	{
		while (i < 0)
		{
			rra(array);
			i++;
		}
	}
	else
	{
		while (i + 5 > 0)
		{
			rafive(array);
			i--;
		}
	}
	push_aa(array);
}

void	ye_init(t_array *array, int argc, char **av)
{
	init_dump(array, argc, av);
	check_five(array);
	push_bb(array);
	push_bb(array);
	sort_three_from_five(array);
}

void	the_final_func_show(t_array *array)
{
	if (array->dump[0] != min_five(array))
		order_five(array);
	if (array->dump[0] == max_five(array))
		rafive(array);
	free(array->astack);
	free(array->dump);
	free(array->bdump);
}
