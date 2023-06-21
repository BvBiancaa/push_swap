/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:09 by bmuni             #+#    #+#             */
/*   Updated: 2022/12/30 17:06:22 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_array *array)
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
	ft_printf("ra\n");
}

void	rotate_sub(t_array *array)
{
	int	last;
	int	*tmp;
	int	i;

	last = array->b_tot;
	i = -1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->bsub[1];
	while (++i < last)
		array->bsub[i] = array->bsub[i + 1];
	array->bsub[last] = *tmp;
	free(tmp);
}

void	rotate_b(t_array *array, int i)
{
	int	last;
	int	*tmp;

	last = array->b_tot;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->bstack[1];
	while (++i < last)
		array->bstack[i] = array->bstack[i + 1];
	array->bstack[last] = *tmp;
	free(tmp);
}

void	rr(t_array *array)
{
	array->check = 1;
	rb(array);
	ra(array);
	ft_printf("rr\n");
	array->check = 0;
}

void	rra(t_array *array)
{
	int	last;
	int	*tmp;

	last = array->a_tot - 1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = array->dump[last];
	while (last > 0)
	{
		array->dump[last] = array->dump[last - 1];
		last--;
	}
	array->dump[0] = *tmp;
	ft_printf("rra\n");
	free(tmp);
}
