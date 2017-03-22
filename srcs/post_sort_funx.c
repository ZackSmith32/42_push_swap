/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort_funx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:09:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/22 11:35:17 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_back(t_stack *stacks)
{
	int		*b;

	b = stacks->b;
	if (find_max(b, stacks->blen) - (stacks->blen - find_max(b, stacks->blen))
		<= 0)
		repeater_post(stacks, 'b', find_max(b, stacks->blen), &op_r);
	else
		repeater_post(stacks, 'b', stacks->blen - find_max(b, stacks->blen),
			&op_q);
	while (stacks->blen != 0)
	{
		// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
		// printf("\n");
		if (stacks->b[0] < stacks->a[find_min(stacks->a, stacks->alen)] &&
				stacks->a[0] == stacks->a[find_min(stacks->a, stacks->alen)])
			op_p(stacks, 'a');
		else if (stacks->b[0] > stacks->a[stacks->alen - 1])
			op_p(stacks, 'a');
		else
			op_q(stacks, 'a');
	}
}

int		sorted(int *a, int len)
{
	int		i;
	int		max_index;
	int		min_index;

	max_index = find_max(a, len);
	min_index = find_min(a, len);
	i = 0;
	if (max_index == 0 && min_index == 2)
		return (0);
	else if (max_index == 1 && min_index == 0)
		return (0);
	else if (max_index == 2 && min_index == 1)
		return (0);
	return (1);
}

void	orientate(t_stack *stacks)
{
	while (1)
	{
		if (stacks->a[0] == stacks->a[find_min(stacks->a, stacks->alen)])
			break ;
		// printf("index 0= %d, min = %d\n", stacks->a[0], stacks->a[find_min(stacks->a, stacks->alen)]);
		op_q(stacks, 'a');
	}
}

void	post_sort(t_stack *stacks)
{
	if (stacks->alen == 2)
	{
		if (stacks->a[0] < stacks->a[1])
			return ;
		op_s(stacks, 'a');
		return ;
	}
	if (!sorted(stacks->a, stacks->alen))
		op_s(stacks, 'a');
	if (stacks->a[1] == stacks->a[find_min(stacks->a, stacks->alen)])
		op_r(stacks, 'a');
	if (stacks->a[2] == stacks->a[find_min(stacks->a, stacks->alen)])
		op_q(stacks, 'a');
	push_back(stacks);
	// ft_putarr(stacks->a, stacks->alen);
	orientate(stacks);
}
