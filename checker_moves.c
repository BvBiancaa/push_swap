/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:03:03 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 20:15:21 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_bc(t_checker *checker)
{
	int	*tmp;

	if (!checker->bpile)
		return ;
	tmp = malloc(sizeof(int) * 1);
	*tmp = checker->bpile[1];
	checker->bpile[1] = checker->bpile[0];
	checker->bpile[0] = *tmp;
	free(tmp);
}

void	ssc(t_checker *checker)
{
	swap_ac(checker);
	swap_bc(checker);
}
