/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:14:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/22 11:13:24 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 *	> moves
 *		> operation
 *		> next operation
 *		> number we're working on A
 *		> number we're working on B
 *		ft_printf("\033[2J\033[1;1H");
 *	


void	handle_colors(t_stacks *stacks, t_moves *moves, int i)
{
	int		*a;
	int		*b;

	a = stacks->a;
	b = stacks->b;
	if (i < alen)
		if (a[i] == anum && (moves->strat = 1 || moves->strat == 3))
			ft_printf("                         %@blue@d     ", a[i]);
		else if (a[i] == anum && (moves->strat == 0 || moves->strat == 2))
			ft_printf("                         %@magenta@d     ", a[i]);
		else
			ft_printf("                         %d     ", a[i]);
	else 
		ft_printf("                               ");
	if (i <= 9)
		ft_printf(" ")
	if (i < blen)
		if (b[i] == bnum && (moves->strat = 1 || strat == 3))
			ft_printf("%@cyan@d     ", a[i]);
		else if (b[i] == bnum && (strat == 0 || strat == 2))
			ft_printf("%@magenta@d     ", a[i]);
		else
			ft_printf("%d     ", a[i]);
}
 */
void	fun_stacks(t_stack *stacks, t_moves *moves, int anum, int bnum)
{
	int		i;
	int		j;

	j = 0;
	i = ft_greater_than(stacks->alen, stacks->blen) ? stacks->alen : stacks->blen;
	ft_printf("%@underline@5s %@underline@s%@underline@4s\n", "A", "B", "");
	while (j < i)
	{
		if (stacks->a[j] == anum && j < stacks->alen)
			ft_printf("%@green@5d ", stacks->a[j]);
		else if (j < stacks->alen)
			ft_printf("%5d ", stacks->a[j]);
		else
			ft_printf("      ");
		if (stacks->b[j] == bnum && j < stacks->blen)
			ft_printf("%@magenta@d", stacks->b[j]);
		else if (j < stacks->blen)
			ft_printf("%d", stacks->b[j]);
		printf("\n");
		
		j++;
	}
	printf("\n");
	ft_keyhook('\n');


}

void	repeater(t_stack *stacks, char z, int a, void (*f)(t_stack*, char), t_moves *moves)
{
	int		i;
	int		which_stack;
	int		anum;
	int		bnum;

	i = 0;
	anum = stacks->a[moves->af];
	bnum = stacks->b[moves->bf];

	printf("anum = %d, bnum = %d\n", anum, bnum);
	printf("before while\n");
	fun_stacks(stacks, moves, anum, bnum);
	while (i < a)
	{
		printf("in while");
		f(stacks, z);
		fun_stacks(stacks, moves, anum, bnum);
		i++;
	}
	ft_printf("%@blue@s\n\n", "==========================================================");

}

/*
**	strat 0 = af bf
**	strat 1 = ar br
**	strat 2 = af br
**	strat 3 = ar bf
*/

void	strat_zero(t_stack *stacks, int af, int bf, t_moves *moves)
{
	ft_printf("strat 0\n");
	int		i;
	int		diff;
	diff = af - bf;
	if (diff <= 0)
	{
		repeater(stacks, 'r', af, &op_r, moves);
		repeater(stacks, 'b', bf - af, &op_r, moves);
	}
	if (diff > 0)
	{
		repeater(stacks, 'r', bf, &op_r, moves);
		repeater(stacks, 'a', af - bf, &op_r, moves);
	}
	// ft_printf("before put\n");
	op_p(stacks, 'b');
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);	
}

void	strat_one(t_stack *stacks, int ar, int br, t_moves *moves)
{
	ft_printf("strat 1\n");
	int		i;
	int		diff;

	diff = ar - br;
	if (diff <= 0)
	{
		repeater(stacks, 'r', ar, &op_q, moves);
		repeater(stacks, 'b', br - ar, &op_q, moves);
	}
	if (diff > 0)
	{
		repeater(stacks, 'r', br, &op_q, moves);
		repeater(stacks, 'a', ar - br, &op_q, moves);
	}
	op_p(stacks, 'b');
}

void	strat_two(t_stack *stacks, int ar, int br, t_moves *moves)
{
	ft_printf("strat 2\n");
	repeater(stacks, 'a', ar, &op_r, moves);
	repeater(stacks, 'b', br, &op_q, moves);
	op_p(stacks, 'b');
}

void	strat_three(t_stack *stacks, int ar, int br, t_moves *moves)
{
	ft_printf("strat 3\n");
	repeater(stacks, 'a', ar, &op_q, moves);
	repeater(stacks, 'b', br, &op_r, moves);
	op_p(stacks, 'b');
}









































