/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:35:50 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 22:03:39 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min(t_stack *stacks)
{
	int		i;
	int		min_index;

	i = 0;
	min_index = 0;
	while (i < stacks->blen)
	{
		// printf("blen = %d\n", stacks->blen);
		if ((stacks->b)[i] < (stacks->b)[min_index])
		{
			min_index = i;
			// ft_printf("min if, min = %d\n", min_index);
		}
		i++;
	}
	// ft_printf("in min min = %d\n", min_index);
	return (min_index);
}

static int	find_max(t_stack *stacks)
{
	int		i;
	int		max_index;

	i = 0;
	max_index = 0;
	while (i < stacks->blen)
	{
		if ((stacks->b)[i] > (stacks->b)[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

static void	regular_calc(t_stack *stacks, t_moves *moves, int num)
{
	int		i;

	i = 0;
	if (num > (stacks->b)[0] && num < (stacks->b)[stacks->blen])
	{
		moves->bf = 0;
		moves->br = 0;
		return ;
	}
	while (i < stacks->blen - 1)
	{
		if (num < (stacks->b)[i] && num > (stacks->b)[i + 1])
		{
			moves->bf = i + 1;
			moves->br = stacks->blen - i;
			return ;
		}
		i++;
	}
}

// num is the number we are looking at in stack a
void	calc_b(t_stack *stacks, t_moves *moves, int num)
{
	int		i;
	int		min;
	int		max;

	min = find_min(stacks);
	max = find_max(stacks);
	i = 0;
	if (num < (stacks->b)[min])
	{
		moves->bf = i;
		moves->br = stacks->blen - i;
	}
	else if (num > (stacks->b)[max])
	{
		ft_printf("max num = %d, max = %d\n", num, max);
		moves->bf = i;
		moves->br = stacks->blen - i + 1;
	}
	else
	{
		ft_printf("regular num = %d\n", num);
		regular_calc(stacks, moves, num);
	}
}

void	calc_strategy(int af, int ar, int bf, t_moves *min)
{
	int		br;

	br = min->br;
	min->total = ret_greater(af, bf);
	min->strat = 0;
	if (ret_greater(ar, br) < min->total)
	{
		min->strat = 1;
		min->total = ret_greater(af, bf);
	}
	if (af + br < min->total)
	{
		min->strat = 2;
		min->total = af + br;
	}
	if (ar + bf < min->total)
	{
		min->strat = 3;
		min->total = ar + bf;
	}
}














































