/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_spr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:33:34 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/16 17:23:30 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	op_s(t_stack *stacks, char c)
{
	if (c == 'a' )
	{
		if (stacks->alen == 0 || stacks->alen == 1)
			return;
		ft_xor_swap(&(stacks->a[0]), &(stacks->a[1]));
	}
	if (c == 'b')
	{
		if (stacks->blen == 0 || stacks->blen == 1)
			return ;
		ft_xor_swap(&(stacks->b[0]), &(stacks->b[1]));
	}
	if (c == 'c')
	{
		if (stacks->blen == 0 || stacks->blen == 1 ||
			stacks->alen == 0 || stacks->alen == 1)
			return ;
		ft_xor_swap(&(stacks->a[0]), &(stacks->a[1]));
		ft_xor_swap(&(stacks->b[0]), &(stacks->b[1]));
	}
}

void	op_p(t_stack *stacks, char c)
{
	if (c == 'a')
	{
		ft_push_arr(&(stacks->a), ft_pop_arr(&(stacks->b), stacks->blen),
			stacks->alen);
		stacks->alen++;
		stacks->blen--;
	}
	if (c == 'b')
	{
		ft_push_arr(&(stacks->b), ft_pop_arr(&(stacks->a), stacks->alen),
			stacks->blen);
		stacks->blen++;
		stacks->alen--;
	}
}