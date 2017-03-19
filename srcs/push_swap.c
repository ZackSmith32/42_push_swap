/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:19:08 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/18 17:42:19 by zsmith           ###   ########.fr       */
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
	char	*op;
	char	*str;
	char	*temp;

	i = 0;
	str = ft_memalloc(1);
	while (stacks->operations[i] != 0)
	{
		op = ft_strjoin(stacks->operations[i], "\n");
		temp = str;
		str = ft_strjoin(str, op);
		free(temp);
		i++;
	}
	write(1, str, ft_strlen(str));
	free(str);
}

void	push_swap(int *a, int alen)
{
	t_stack		*stacks;
	t_moves		*moves;

	moves = (t_moves*)ft_memalloc(sizeof(t_moves));
	stacks = make_stack_obj(a, alen);
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
	char	**parsed_data;
	int		alen;

	if (argc <= 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	if (!parse_input_type(argc, argv, &parsed_data))
	{
		printf("Error\n");
		return (0);
	}
	alen = populate_stack(&parsed_data, &a);
	push_swap(a, alen);
	return (0);
}














