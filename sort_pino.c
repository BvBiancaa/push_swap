/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:33 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 19:44:39 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(int m, int l)
{
	if (m > l)
		ft_printf("ra\n");
	exit(0);
}

void	sort_three(int argc, char **argv)
{
	int	f;
	int	m;
	int	l;

	f = ft_atoi(argv[1]);
	m = ft_atoi(argv[2]);
	if (argc == 3)
		sort_two(f, m);
	l = ft_atoi(argv[3]);
	if (f < l && f < m && l < m)
		ft_printf("rra\nsa\n");
	else if (f > m && f < l && m < l)
		ft_printf("sa\n");
	else if (f < m && f > l && m > l)
		ft_printf("rra\n");
	else if (f > m && f > l && m < l)
		ft_printf("ra\n");
	else if (f > m && f > l && m > l)
		ft_printf("sa\nrra\n");
	else if (f < m && m < l)
		exit (0);
	else
		exit (write(2, "Error\n", 6));
	exit (0);
}

void	init_dump(t_array *array, int argc, char **argv)
{
	int	i;

	i = -1;
	array->a_tot = 5;
	array->astack = (int *) malloc(sizeof(int) * 6);
	array->dump = (int *) malloc(sizeof(int) * 6);
	array->bdump = (int *) malloc(sizeof(int) * 6);
	array->b_tot = 2;
	while (++i < argc - 1)
	{
		array->dump[i] = ft_atoi(argv[i + 1]);
		array->astack[i] = ft_atoi(argv[i + 1]);
	}
	array->check = 0;
}

int	max_five(t_array *array)
{
	int	i;
	int	last;

	i = 0;
	last = array->dump[0];
	while (i < array->a_tot - 1)
	{
		if (array->dump[i] > last)
			last = array->dump[i];
		i++;
	}
	if (array->dump[array->a_tot - 1] > last)
		last = array->dump[array->a_tot - 1];
	return (last);
}

void	sort_five(t_array *array, int argc, char **av)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	ye_init(array, argc, av);
	while (x <= 1)
	{
		if (array->bdump[0] > array->dump[1 + x])
		{
			push_aa(array);
			rafive(array);
		}
		else
			lollo(array, i, x);
		i = 0;
		array->bdump[0] = array->bdump[1];
		canpush(array);
		x++;
	}
	the_final_func_show(array);
	exit(0);
}
