/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:14:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/21 00:48:51 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	the move counts, which are used as a proxy for number position, can be
**	off if the number that needs to move needs to go back to the
**	position is in to start. i.e. if the number in last position needs to 
**	go back to the last position  
*/

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
	moves->bf == stacks->blen ? (bnum = stacks->blen - 1) : (bnum = (stacks->b)[moves->bf]); // somehow bf == blen
	if (a == 0)
		return ;
	if (g_verbose_flag != 0)
		fun_stacks(stacks, anum, bnum);
	while (i < a)
	{
		f(stacks, z);
		if (g_verbose_flag != 0)
			fun_stacks(stacks, anum, bnum);
		i++;
	}
}

void	strat_zero(t_stack *stacks, int af, int bf, t_moves *moves)
{
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
