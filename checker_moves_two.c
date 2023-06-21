/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bianca <bianca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:22 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/19 21:00:56 by bianca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_a_checker(t_checker *checker)
{
	int	i;
	int	tot;
	int	*twos;

	i = 0;
	tot = checker->ap_tot;
	twos = malloc(sizeof(int) * tot);
	while (i < tot - 1)
	{
		twos[i] = checker->apile[i + 1];
		i++;
	}
	checker->ap_tot--;
	i = -1;
	while (++i < checker->ap_tot)
		checker->apile[i] = twos[i];
	free(twos);
}

void	delete_b_checker(t_checker *checker)
{
	int	i;
	int	tot;
	int	*two;

	i = 0;
	tot = checker->bp_tot;
	two = malloc(sizeof(int) * tot + 4);
	while (i < tot - 1)
	{
		two[i] = checker->bpile[i + 1];
		i++;
	}
	checker->bp_tot--;
	i = -1;
	while (++i < checker->bp_tot)
		checker->bpile[i] = two[i];
	free(two);
}

void	swap_ac(t_checker *checker)
{
	int	*tmp;
	int	*dtmp;

	tmp = malloc(sizeof(int) * 1);
	dtmp = malloc(sizeof(int) * 1);
	*tmp = checker->apile[1];
	*dtmp = checker->apdump[1];
	checker->apile[1] = checker->apile[0];
	checker->apile[0] = *tmp;
	checker->apdump[1] = checker->apdump[0];
	checker->apdump[0] = *dtmp;
	free(tmp);
	free(dtmp);
}

void	push_ac(t_checker *checker)
{
	int	i;

	i = 0;
	if (checker->bp_tot == 0)
		return ;
	checker->ap_tot++;
	checker->apile3 = malloc (sizeof(int) * checker->ap_tot + 8);
	checker->apile3[0] = checker->bpile[0];
	while (++i < checker->ap_tot)
		checker->apile3[i] = checker->apile[i - 1];
	i = -1;
	while (++i < checker->ap_tot)
	{
		checker->apile[i] = checker->apile3[i];
	}
	free(checker->apile3);
	delete_b_checker(checker);
}

void	push_bc(t_checker *checker)
{
	int	i;

	i = 0;
	if (checker->ap_tot == 0)
		return ;
	checker->bp_tot++;
	checker->apile2 = malloc (sizeof(int) * checker->bp_tot + 4);
	checker->apile2[0] = checker->apile[0];
	while (++i < checker->bp_tot)
		checker->apile2[i] = checker->bpile[i - 1];
	i = -1;
	while (++i < checker->bp_tot)
		checker->bpile[i] = checker->apile2[i];
	free(checker->apile2);
	delete_a_checker(checker);
}
