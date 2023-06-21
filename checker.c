/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:33:12 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/21 10:05:59 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrc(t_checker *checker)
{
	rbc(checker);
	rac(checker);
}

int	keep_checking(t_checker *checker, char *line)
{
	if (ft_strncmp(line, "rrb\n", 5) == 0)
		rrbc(checker);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		rrac(checker);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		rrrc(checker);
	else if (ft_strncmp(line, "rr\n", 5) == 0)
		rrc(checker);
	else if (ft_strncmp(line, "ss\n", 5) == 0)
		ssc(checker);
	else if (ft_strncmp(line, "sb\n", 5) == 0)
		swap_bc(checker);
	else
		return (1);
	return (0);
}

void	check_sorted(t_checker *checker, int ac)
{
	int	i;

	i = -1;
	while (++i < ac - 2)
	{
		if (checker->apile[i] > checker->apile[i + 1])
		{
			free(checker->apile);
			free(checker->bpile);
			free(checker->apdump);
			exit (write(1, "K0\n", 3));
		}
	}
	free(checker->apile);
	free(checker->bpile);
	free(checker->apdump);
	exit (write(1, "0K\n", 3));
}

void	check_start(t_checker *checker)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line != NULL && ft_strncmp(line, "Error", 5) == 0)
			exit (0);
		else if (line == NULL || !line || line[0] == '\0')
			break ;
		else if (ft_strncmp(line, "sa\n", 5) == 0)
			swap_ac(checker);
		else if (ft_strncmp(line, "pa\n", 5) == 0)
			push_ac(checker);
		else if (ft_strncmp(line, "pb\n", 5) == 0)
			push_bc(checker);
		else if (ft_strncmp(line, "rb\n", 5) == 0)
			rbc(checker);
		else if (ft_strncmp(line, "ra\n", 5) == 0)
			rac(checker);
		else
			if (keep_checking(checker, line))
				break ;
		free(line);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_checker	checker;
	int			i;

	if (ac < 3)
		return (0);
	i = -1;
	checker.ap_tot = ac - 1;
	checker.bp_tot = 0;
	checker.apile = malloc(sizeof(int) * ac - 1);
	checker.bpile = malloc(sizeof(int) * ac - 1);
	checker.apdump = malloc(sizeof(int) * ac - 1);
	while (++i < checker.ap_tot)
	{
		checker.apile[i] = ft_atoi(av[i + 1]);
		checker.apdump[i] = ft_atoi(av[i + 1]);
	}
	check_start(&checker);
	check_sorted(&checker, ac);
}
