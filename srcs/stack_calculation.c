/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:35:50 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/16 09:42:42 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(int *stack, int len)
{
	int		i;
	int		min_index;

	i = 0;
	min_index = 0;
	while (i < len)
	{
		if (stack[i] < stack[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

//	returns max index
int	find_max(int *stack, int len)
{
	int		i;
	int		max_index;

	i = 0;
	max_index = 0;
	while (i < len)
	{
		if (stack[i] > stack[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

static void	regular_calc(t_stack *stacks, t_moves *moves, int num)
{
	int		i;

	i = 0;
	if (num > (stacks->b)[0] && num < (stacks->b)[stacks->blen - 1])
	{
		ft_printf("regular_calc >> num in between front and end\n");
		ft_printf("num = %d, stacks[0] = %d, stacks[%d] = %d\n", num, stacks->b[0], stacks->blen, (stacks->b)[stacks->blen]);
		ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
		moves->bf = 0;
		moves->br = 0;
		return ;
	}
	while (i < stacks->blen - 1)
	{
		if (num < (stacks->b)[i] && num > (stacks->b)[i + 1])
		{
			moves->bf = i + 1;
			moves->br = stacks->blen - i - 1;
			return ;
		}
		i++;
	}
}

// num is the number we are looking at in stack 'a'
void	calc_b(t_stack *stacks, t_moves *moves, int num)
{
	int		i;
	int		min_index;
	int		max_index;

	min_index = find_min(stacks->b, stacks->blen);
	max_index = find_max(stacks->b, stacks->blen);
	i = 0;
	if (num < (stacks->b)[min_index])
	{
		ft_printf("%@red@s\n", "min");
		moves->bf = min_index + 1;
		moves->br = stacks->blen - min_index - 1;
	}
	else if (num > (stacks->b)[max_index])
	{
		ft_printf("%@red@s\n", "max");
		ft_printf("max num = %d, max index = %d\n", num, max_index);
		moves->bf = max_index;
		moves->br = stacks->blen - max_index;
	}
	else
	{
		ft_printf("%@red@s %@red@d\n", "regular num =", num);
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
		min->total = ret_greater(ar, br);
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














































