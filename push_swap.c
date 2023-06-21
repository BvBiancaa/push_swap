/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:21 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:44:08 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_match(t_array *array)
{
	int	i;
	int	a;
	int	b;
	int	c;
	int	x;

	i = -1;
	x = 0;
	while (++i < array->b_tot - 0)
	{
		a = array->ab[i];
		b = array->b[i];
		if ((a > 0 && b > 0) || (a < 0 && b < 0))
			findus(array, i, &x, &c);
		else
			findm(array, i, &c, &x);
	}
	return (x);
}

void	sorte(t_array *array)
{
	int	a;
	int	b;

	while (array->b_tot > 0)
	{
		check_double(array);
		a = find_best_match(array);
		b = array->b[a];
		a = array->ab[a];
		if (a >= 0 && b >= 0)
			ab_pos(array, a, b);
		else if (a <= 0 && b <= 0)
			ab_neg(array, a, b);
		else if (a >= 0 && b <= 0)
			apos_bneg(array, a, b);
		else if (a <= 0 && b >= 0)
			aneg_bpos(array, a, b);
		else if (a == 0 && b == 0)
			push_a(array);
	}
	order_array(array);
}

void	check_shortest(t_array *array, int i)
{
	if (i <= array->a_tot / 2)
	{
		while (--i > 0)
		{
			if (array->b_tot > 0)
			{
				if (array->astack[i] < array->bstack[0])
					rr(array);
				else
					ra(array);
			}
			else
				ra(array);
		}
	}
	else if (i == array->a_tot - 1)
		rraa(array);
	else
		shortino(array, i);
}

void	divdi_et_impera(t_array *array, int y)
{
	int	x;
	int	fin;
	int	i;
	int	c;

	x = -1;
	c = 0;
	fin = array->a_tot;
	while (++x < array->a_tot)
	{
		if (c == 1)
		{
			i = 0;
			c = 0;
			x = 0;
		}
		else
			i = x;
		if (check(array, array->astack[i]) == 0 && i <= fin)
			i++;
		if (i > x)
			cases(array, &c, i);
	}
	i--;
	defaults(array, i, y);
}

void	lis(int tot, t_array *array)
{
	int	i;
	int	x;
	int	longest;
	int	shortest;

	x = 0;
	i = 0;
	longest = minlis(array, 0);
	array->adump[0] = array->astack[longest];
	i = longest;
	shortest = array->astack[longest];
	while (array->astack[i] != array->last_lis)
	{
		if (array->astack[i] > shortest)
		{
			array->adump[++x] = array->astack[i];
			shortest = array->astack[i];
		}
		i++;
	}
	hello_darkness(array, i, x, tot);
}
