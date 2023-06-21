/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuni <bmuni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:26 by bmuni             #+#    #+#             */
/*   Updated: 2023/06/18 20:08:54 by bmuni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libftprintf/ft_printf.h"

typedef struct s_checker
{
	int	*apdump;
	int	*apile;
	int	*bpile;
	int	ap_tot;
	int	bp_tot;
	int	*apile2;
	int	*apile3;
}	t_checker;

typedef struct s_array
{
	int	*astack;
	int	*b;
	int	*ab;
	int	*astack2;
	int	*astack3;
	int	*bstack;
	int	*dump;
	int	*bdump;
	int	*bsub;
	int	*adump;
	int	a_tot;
	int	check;
	int	b_tot;
	int	first_lis;
	int	last_lis;
	int	tot_a;
	int	ck;
}	t_array;

void	rotate_sub(t_array *array);
void	push_b(t_array *array);
void	push_a(t_array *array);
void	ss(t_array *array);
void	swap_b(t_array *array);
void	swap_a(t_array *array);
void	rra(t_array *array);
void	rr(t_array *array);
void	rotate_b(t_array *array, int i);
void	rotate_sub(t_array *array);
void	rotate_a(t_array *array);
void	delete_b(t_array *array);
void	ra(t_array *array);
void	rraa(t_array *array);
void	push_bb(t_array *array);
void	rb(t_array *array);
void	rrr(t_array *array);
void	rrb(t_array *array);
int		is_min(t_array *array, int i);
int		check(t_array *array, int x);
int		take_x(t_array *array, int bpos, int apos, int alpos);
void	check_double(t_array *array);
void	order_array(t_array *array);
void	ab_pos(t_array *array, int a, int b);
void	ab_neg(t_array *array, int a, int b);
void	apos_bneg(t_array *array, int a, int b);
void	aneg_bpos(t_array *array, int a, int b);
void	free_all(t_array *array);
void	lis(int tot, t_array *array);
void	divdi_et_impera(t_array *array, int y);
void	sorte(t_array *array);
int		find_best_match(t_array *array);
void	findus(t_array *array, int i, int *x, int *c);
void	findm(t_array *array, int i, int *c, int *x);
int		take_x_p2(t_array *array, int x);
void	one(t_array *array, int x, int i);
void	do_bee(t_array *array);
void	two(t_array *array, int i, int x);
void	three(t_array *array, int i, int x);
void	initi(t_array *array, int i);
void	sort_three(int argc, char **argv);
void	sort_five(t_array *array, int argc, char **argv);
void	check_ac(t_array *array, int argc, char **argv);
void	rafive(t_array *array);
void	delete_a(t_array *array);
int		max(t_array *array);
int		minlis(t_array *array, int a);
int		is_max(t_array *array, int i);
void	push_aa(t_array *array);
void	check_rep(t_array *array);
int		max_five(t_array *array);
void	delete_a_checker(t_checker *checker);
void	delete_b_checker(t_checker *checker);
void	swap_ac(t_checker *checker);
void	push_ac(t_checker *checker);
void	push_bc(t_checker *checker);
void	rac(t_checker *checker);
void	rrac(t_checker *checker);
void	rbc(t_checker *checker);
void	rrbc(t_checker *checker);
void	rrrc(t_checker *checker);
void	rrc(t_checker *checker);
void	delete_dump(t_array *array);
void	shortino(t_array *array, int i);
void	defaults(t_array *array, int i, int y);
void	cases(t_array *array, int *c, int i);
void	check_shortest(t_array *array, int i);
void	hello_darkness(t_array *array, int i, int x, int tot);
void	pino_one(t_array *array, int i);
void	pino_two(t_array *array, int i, int shortest);
void	pino_three(t_array *array, int i);
void	pino_four(t_array *array, int i);
void	pino_five(t_array *array, int i);
void	pinot_all(t_array *array, int i);
void	five_func(t_array *array, int i);
void	five_func_two(t_array *array, int i, int x);
void	ye_init(t_array *array, int argc, char **av);
void	sort_three_from_five(t_array *array);
void	check_five(t_array *array);
void	init_dump(t_array *array, int argc, char **argv);
void	the_final_func_show(t_array *array);
int		min_five(t_array *array);
void	order_five(t_array *array);
void	lollo(t_array *array, int i, int x);
int		canpush(t_array *array);
void	fin(t_array *array, int *i, int bpos, int *apos);
void	if_int_the_world(t_array *array, int i, int x);
int		check_if_sorted(char **argv, int argc);
void	ssc(t_checker *checker);
void	swap_bc(t_checker *checker);

#endif
