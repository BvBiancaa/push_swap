/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:33:21 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:42:07 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(t_array *array)
{
	int	i;
	int	x;

	i = 0;
	while (i < array->a_tot)
	{
		x = 0;
		while (x < i)
		{
			if (array->astack[x] > array->astack[i])
				return ;
			x++;
		}
		i++;
	}
	exit (0);
}

void	check_rep(t_array *array)
{
	int	i;
	int	current;

	current = 0;
	while (current < array->a_tot - 1)
	{
		i = current + 1;
		while (array->dump[current] != array->dump[i] && i < array->a_tot - 1)
			i++;
		if (array->dump[current] == array->dump[i])
		{
			array->ck = 1;
			free_all(array);
			exit (write(2, "Error\n", 6));
		}
		current++;
	}
	is_sorted(array);
}
