/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:18 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:40:27 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_aa(t_array *array)
{
	int	i;

	i = 0;
	array->a_tot++;
	if (array->bdump != NULL)
	{
		array->astack3 = malloc (sizeof(int) * array->a_tot + 8);
		array->astack3[0] = array->bdump[0];
		while (++i < array->a_tot)
			array->astack3[i] = array->dump[i - 1];
		i = -1;
		while (++i < array->a_tot)
		{
			array->dump[i] = array->astack3[i];
		}
		ft_printf("pa\n");
		free(array->astack3);
	}
	else
		return ;
}

void	swap_a(t_array *array)
{
	int	*tmp;
	int	*dtmp;

	tmp = malloc(sizeof(int) * 1);
	dtmp = malloc(sizeof(int) * 1);
	*tmp = array->astack[1];
	*dtmp = array->dump[1];
	array->astack[1] = array->astack[0];
	array->astack[0] = *tmp;
	array->dump[1] = array->dump[0];
	array->dump[0] = *dtmp;
	free(tmp);
	free(dtmp);
	ft_printf("sa\n");
}

void	swap_b(t_array *array)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * 1);
	*tmp = array->bstack[2];
	array->bstack[1] = array->bstack[1];
	array->bstack[0] = *tmp;
	free(tmp);
}

void	ss(t_array *array)
{
	swap_a(array);
	swap_b(array);
}

void	push_a(t_array *array)
{
	int	i;

	i = 0;
	array->a_tot++;
	if (array->bdump != NULL)
	{
		array->astack3 = malloc (sizeof(int) * array->a_tot + 8);
		array->astack3[0] = array->bstack[0];
		while (++i < array->a_tot)
			array->astack3[i] = array->astack[i - 1];
		i = -1;
		while (++i < array->a_tot)
		{
			array->astack[i] = array->astack3[i];
		}
		ft_printf("pa\n");
		free(array->astack3);
		free(array->ab);
		free(array->b);
		delete_b(array);
	}
	else
		return ;
}
