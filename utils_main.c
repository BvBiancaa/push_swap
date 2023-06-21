/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:36 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:45:02 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	take_x(t_array *array, int bpos, int apos, int alpos)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = -1;
	x = apos;
	fin(array, &i, bpos, &apos);
	alpos = array->a_tot - 1;
	while (++y < array->a_tot && array->bstack[bpos] < array->astack[alpos])
		alpos--;
	if (i == 0 && y == 0)
		return (take_x_p2(array, x));
	else if (i == y)
		return (x * -1);
	else if (i <= y && array->bstack[bpos] > array->astack[alpos]
		&& array->bstack[bpos] < array->astack[apos]
		&& array->astack[alpos] < array->astack[apos])
		return (x);
	else if (i <= y && array->bstack[bpos] < array->astack[alpos]
		&& array->bstack[bpos] < array->astack[apos])
		return (x);
	else
		return (x * -1);
}

void	mass(t_array *array, int i)
{
	int	x;

	x = 0;
	while (array->astack[x] != max(array))
		x++;
	if (x <= (array->a_tot) / 2)
		array->ab[i] = x + 1;
	else
		array->ab[i] = x - (array->a_tot - 1);
}

void	check_double(t_array *array)
{
	int	i;
	int	x;

	do_bee(array);
	i = -1;
	while (++i < array->b_tot)
	{
		x = 0;
		if (is_min(array, i) == 0)
			one(array, x, i);
		else if (is_max(array, i) == 0)
			mass(array, i);
		else if (array->bstack[i] < array->astack[x]
			&& array->bstack[i] < array->astack[array->a_tot - 1])
			three(array, i, 0);
		else if (array->bstack[i] > array->astack[x]
			&& array->bstack[i] > array->astack[array->a_tot - 1])
			two(array, i, x);
		else if (array->astack[x] > array->bstack[i]
			&& array->astack[array->a_tot - 1] < array->bstack[i])
			array->ab[i] = 0;
		else
			if_int_the_world(array, i, x);
	}
}

void	initi(t_array *array, int i)
{
	array->astack = malloc(sizeof(int) * i);
	array->dump = malloc(sizeof(int) * i);
	array->bdump = malloc(sizeof(int) * i);
	array->adump = malloc(sizeof(int) * i);
	array->b_tot = 0;
	array->check = 0;
	array->ck = 0;
}

void	check_ac(t_array *array, int argc, char **argv)
{
	int	i;
	int	y;

	y = 0;
	while (++y < argc)
	{
		i = 0;
		while (argv[y][i])
		{
			if (ft_isdigit(argv[y][i]) == 0
				&& argv[y][i] != '-' && argv[y][i] != '+')
			{
				write(2, "\033[0;31mError\n", 14);
				exit(0);
			}
			i++;
		}
	}
	if (check_if_sorted(argv, argc) == 1)
		exit(0);
	if (argc <= 4)
		sort_three(argc, argv);
	else if (argc == 6)
		sort_five(array, argc, argv);
}
