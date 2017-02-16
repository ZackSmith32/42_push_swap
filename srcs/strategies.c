/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:14:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 22:48:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	repeater(t_stack *stacks, char z, int a, void (*f)(t_stack*, char))
{
	int		i;

	i = 0;
	while (i < a)
	{
		f(stacks, z);
		i++;
	}
}

/*
**	strat 0 = af bf
**	strat 1 = ar br
**	strat 2 = af br
**	strat 3 = ar bf
*/

void	strat_zero(t_stack *stacks, int af, int bf)
{
	int		i;
	int		diff;

	diff = af - bf;

	if (diff <= 0)
	{
		repeater(stacks, 'r', af, &op_r);
		repeater(stacks, 'b', bf - af, &op_r);
	}
	if (diff > 0)
	{
		repeater(stacks, 'r', bf, &op_r);
		repeater(stacks, 'a', af - bf, &op_r);
	}
	op_p(stacks, 'b');
}

void	strat_one(t_stack *stacks, int ar, int br)
{
	int		i;
	int		diff;

	diff = ar - br;
	if (diff <= 0)
	{
		repeater(stacks, 'r', ar, &op_q);
		repeater(stacks, 'b', br - ar, &op_q);
	}
	if (diff > 0)
	{
		repeater(stacks, 'r', br, &op_q);
		repeater(stacks, 'a', ar - br, &op_q);
	}
	op_p(stacks, 'b');
}

void	strat_two(t_stack *stacks, int ar, int br)
{
	repeater(stacks, 'a', ar, &op_r);
	repeater(stacks, 'b', br, &op_q);
	op_p(stacks, 'b');
}

void	strat_three(t_stack *stacks, int ar, int br)
{
	repeater(stacks, 'a', ar, &op_q);
	repeater(stacks, 'b', br, &op_r);
	op_p(stacks, 'b');
}









































