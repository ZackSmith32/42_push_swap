/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:14:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/01 22:39:06 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	repeater(t_stack *stacks, t_move_dir data, void (*f)(t_stack*, char),
			t_moves *moves)
{
	int		i;
	int		anum;
	int		bnum;
	int		a;
	char	z;

	i = 0;
	a = data.a;
	z = data.z;
	anum = stacks->a[moves->af];
	bnum = stacks->b[moves->bf];
	if (a == 0)
		return ;
	if (stacks->print_flag != 0)
		fun_stacks(stacks, moves, anum, bnum);
	while (i < a)
	{
		f(stacks, z);
		if (stacks->print_flag != 0)
			fun_stacks(stacks, moves, anum, bnum);
		i++;
	}
}

void	strat_zero(t_stack *stacks, int af, int bf, t_moves *moves)
{
	t_move_dir	data;
	int			i;
	int			diff;

	diff = af - bf;
	if (diff <= 0)
	{
		repeater(stacks, make_md('r', af), &op_r, moves);
		repeater(stacks, make_md('b', bf - af), &op_r, moves);
	}
	if (diff > 0)
	{
		repeater(stacks, make_md('r', bf), &op_r, moves);
		repeater(stacks, make_md('a', af - bf), &op_r, moves);
	}
	op_p(stacks, 'b');
}

void	strat_one(t_stack *stacks, int ar, int br, t_moves *moves)
{
	int		i;
	int		diff;

	diff = ar - br;
	if (diff <= 0)
	{
		repeater(stacks, make_md('r', ar), &op_q, moves);
		repeater(stacks, make_md('b', br - ar), &op_q, moves);
	}
	if (diff > 0)
	{
		repeater(stacks, make_md('r', br), &op_q, moves);
		repeater(stacks, make_md('a', ar - br), &op_q, moves);
	}
	op_p(stacks, 'b');
}

void	strat_two(t_stack *stacks, int ar, int br, t_moves *moves)
{
	repeater(stacks, make_md('a', ar), &op_r, moves);
	repeater(stacks, make_md('b', br), &op_q, moves);
	op_p(stacks, 'b');
}

void	strat_three(t_stack *stacks, int ar, int br, t_moves *moves)
{
	repeater(stacks, make_md('a', ar), &op_q, moves);
	repeater(stacks, make_md('b', br), &op_r, moves);
	op_p(stacks, 'b');
}
