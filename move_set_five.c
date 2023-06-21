/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:48:46 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/30 17:07:28 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_b(t_array *array)
{
	int	i;
	int	tot;
	int	*two;

	i = 0;
	tot = array->b_tot;
	two = malloc(sizeof(int) * tot + 4);
	while (i < tot - 1)
	{
		two[i] = array->bstack[i + 1];
		i++;
	}
	array->b_tot--;
	i = -1;
	while (++i <= array->b_tot)
		array->bstack[i] = two[i];
	free(two);
}

void	delete_dump(t_array *array)
{
	int	i;
	int	tot;
	int	*two;

	i = 0;
	tot = array->a_tot;
	two = malloc(sizeof(int) * tot);
	while (i < tot - 1)
	{
		two[i] = array->dump[i + 1];
		i++;
	}
	array->a_tot--;
	i = -1;
	while (++i <= array->a_tot)
		array->dump[i] = two[i];
	free(two);
}

void	delete_a(t_array *array)
{
	int	i;
	int	tot;
	int	*two;

	i = 0;
	tot = array->a_tot;
	two = malloc(sizeof(int) * tot);
	while (i < tot - 1)
	{
		two[i] = array->astack[i + 1];
		i++;
	}
	array->a_tot--;
	i = -1;
	while (++i < array->a_tot)
		array->astack[i] = two[i];
	free(two);
}

void	rafive(t_array *array)
{
	int	last;
	int	*tmp;
	int	i;

	last = array->a_tot - 1;
	i = -1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->dump[0];
	while (++i < last)
		array->dump[i] = array->dump[i + 1];
	array->dump[last] = *tmp;
	free(tmp);
	if (array->check == 0)
		ft_printf("ra\n");
}

void	push_b(t_array *array)
{
	int	i;

	i = 0;
	array->b_tot++;
	if (array->astack != NULL)
	{
		array->astack2 = malloc (sizeof(int) * array->b_tot + 4);
		array->astack2[0] = array->astack[0];
		while (++i < array->b_tot)
			array->astack2[i] = array->bstack[i - 1];
		i = -1;
		while (++i < array->b_tot)
			array->bstack[i] = array->astack2[i];
		ft_printf("pb\n");
		free(array->astack2);
		delete_a(array);
	}
	else
		return ;
}
