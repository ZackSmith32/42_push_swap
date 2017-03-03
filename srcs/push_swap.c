/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:19:08 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/01 22:33:28 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Always remember:
**	> top of stack is front of stack (smallest index)
**	> top of stack should be smallest number
**	> stacks->alen = length (not index)
*/

/*
**	strat 0 = af bf
**	strat 1 = ar br
**	strat 2 = af br
**	strat 3 = ar bf
*/

void	make_move(t_stack *stacks, t_moves *moves)
{
	if (moves->strat == 0)
	{
		strat_zero(stacks, moves->af, moves->bf, moves);
	}
	if (moves->strat == 1)
	{
		strat_one(stacks, moves->ar, moves->br, moves);
	}
	if (moves->strat == 2)
	{
		strat_two(stacks, moves->af, moves->br, moves);
	}
	if (moves->strat == 3)
		strat_three(stacks, moves->ar, moves->bf, moves);
}

void	eval_moves(t_stack *stacks, t_moves *moves)
{
	int		i;
	t_moves	*min;

	min = (t_moves*)ft_memalloc(sizeof(t_moves));
	i = 0;
	while (i < stacks->alen)
	{
		min->af = i;
		min->ar = stacks->alen - i;
		calc_b(stacks, min, stacks->a[i]);
		calc_strategy(min->af, min->ar, min->bf, min);
		if (i == 0 || moves->total > min->total)
			*moves = *min;
		i++;
	}
	free(min);
}

void	output(t_stack *stacks)
{
	int		i;
	int		j;

	i = 0;
	while (stacks->operations[i] != 0)
	{
		j = 0;
		while (stacks->operations[i][j] != 0)
		{
			write(1, &stacks->operations[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	push_swap(int *a, int alen, int flag)
{
	t_stack		*stacks;
	t_moves		*moves;

	moves = (t_moves*)ft_memalloc(sizeof(t_moves));
	stacks = make_stack_obj(a, alen, flag);
	if (alen > 3 && !ck_srt_ascend(stacks->a, stacks->alen))
	{
		op_p(stacks, 'b');
		op_p(stacks, 'b');
	}
	while (stacks->alen > 3 && !ck_srt_ascend(stacks->a, stacks->alen))
	{
		eval_moves(stacks, moves);
		make_move(stacks, moves);
	}
	post_sort(stacks);
	output(stacks);
	ft_free_tab(stacks->operations);
	free(stacks->operations);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	free(moves);
}

int		main(int argc, char **argv)
{
	int		*a;
	int		num_flags;
	int		alen;

	if (argc <= 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	num_flags = check_flags(argc, argv);
	if (argc - num_flags == 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	a = (int *)ft_memalloc(sizeof(int) * 1);
	alen = parse(argc, argv, &a, num_flags);
	if (alen == 0)
		return (0);
	push_swap(a, alen, num_flags);
	return (0);
}
