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
**	strat 1 = ar bf
**	strat 2 = af br
**	strat 3 = ar bf
*/

int		abs(int n)
{
	if (n < 0)
		n = n * -1;
	return n;
}


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