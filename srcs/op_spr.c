/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_spr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:33:34 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/02 13:38:21 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_s(t_stack *stacks, char c)
{
	if (c == 'a')
	{
		if (stacks->alen == 0 || stacks->alen == 1)
			return ;
		ft_xor_swap(&(stacks->a[0]), &(stacks->a[1]));
		ft_push_str(&stacks->operations, "sa");
	}
	if (c == 'b')
	{
		if (stacks->blen == 0 || stacks->blen == 1)
			return ;
		ft_xor_swap(&(stacks->b[0]), &(stacks->b[1]));
		ft_push_str(&stacks->operations, "sb");
	}
	if (c == 'c')
	{
		if (stacks->blen == 0 || stacks->blen == 1 ||
			stacks->alen == 0 || stacks->alen == 1)
			return ;
		ft_xor_swap(&(stacks->a[0]), &(stacks->a[1]));
		ft_xor_swap(&(stacks->b[0]), &(stacks->b[1]));
		ft_push_str(&stacks->operations, "ss");
	}
}

void	op_p(t_stack *stacks, char c)
{
	if (c == 'a' && stacks->blen != 0)
	{
		ft_push_arr(&(stacks->a), ft_pop_arr(&(stacks->b), stacks->blen),
			stacks->alen);
		stacks->alen++;
		stacks->blen--;
		ft_push_str(&stacks->operations, "pa");
	}
	if (c == 'b' && stacks->alen != 0)
	{
		ft_push_arr(&stacks->b, ft_pop_arr(&(stacks->a), stacks->alen),
			stacks->blen);
		stacks->blen++;
		stacks->alen--;
		ft_push_str(&stacks->operations, "pb");
	}
}

void	op_r(t_stack *stacks, char c)
{
	int		top;
	char	*str;

	if ((c == 'a' || c == 'r') && stacks->alen > 1)
	{
		top = ft_pop_arr(&stacks->a, stacks->alen);
		stacks->a[stacks->alen - 1] = top;
		c == 'a' ? ft_push_str(&stacks->operations, "ra")
			: ft_push_str(&stacks->operations, "rr");
	}
	if ((c == 'b' || c == 'r') && stacks->blen > 1)
	{
		top = ft_pop_arr(&stacks->b, stacks->blen);
		stacks->b[stacks->blen - 1] = top;
		if (c == 'b')
			ft_push_str(&stacks->operations, "rb");
	}
}

void	op_q(t_stack *stacks, char c)
{
	if ((c == 'a' || c == 'r') && stacks->alen > 1)
	{
		ft_rev_rotate(&stacks->a, stacks->alen);
		c == 'a' ? ft_push_str(&stacks->operations, "rra")
			: ft_push_str(&stacks->operations, "rrr");
	}
	if ((c == 'b' || c == 'r') && stacks->blen > 1)
	{
		ft_rev_rotate(&stacks->b, stacks->blen);
		if (c == 'b')
			ft_push_str(&stacks->operations, "rrb");
	}
}
