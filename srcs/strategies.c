/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:14:55 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 22:25:47 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	strategy_one(t_stack stacks, int af, int bf)
{
	int		i;
	int		diff;

	diff = af - bf;
	if (af > bf)
	{
		i = 0;
		while (i < bf)
		{
			op_r(stacks, 'r');
			i++;
		}
		i = 0
		while (i < af - bf)
		{
			op_r(stacks, 'a');
			i++;
		}
	}

}