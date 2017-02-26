/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_sort_funx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:09:12 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/25 20:47:14 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 	ft_bubsort_a(int **stack, int len)
{
	t_stack	*new;
	int		i;
	int		j;

	i = 0;
	new = (t_stack *)ft_memalloc(sizeof(int) * len);
	ft_memcpy(new, *stack, sizeof(int) * len);
	while (i < len - 1)
	{
		if (new->a[i] > new->a[i + 1] && new->a[i] != find_max(new->a, len))
			op_s(new, 'a');
		op_r(new, 'a');
	}

}

void	push_back(t_stack *stacks)
{
	int		*b;
	int		rot;
	
	// ft_printf("in: push_back\n");
	b = stacks->b;
	if (find_max(b, stacks->blen) - (stacks->blen - find_max(b, stacks->blen)) <= 0)
	{
		// ft_printf("bf time = %d\n", find_max(b, stacks->blen));
		repeater_post(stacks, 'b', find_max(b, stacks->blen), &op_r);
	}
	else
	{
		// ft_printf("br %d - %d = %d\n", stacks->blen, find_max(b, stacks->blen), stacks->blen - find_max(b, stacks->blen));
		repeater_post(stacks, 'b', stacks->blen - find_max(b, stacks->blen), &op_q);
	}
	// ft_printf("stack b should have biggest at the top\n");
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	while (stacks->blen != 0)
	{
		// ft_printf("push back\n");
		// ft_printf("wmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmw\n");
		// ft_printf("\nb[0] = %d, a[last] = %d\n", stacks->b[0], stacks->a[stacks->alen - 1]);
		// ft_printf("a[0] = %d, find_min(a) = %d\n", stacks->a[0], stacks->a[find_min(stacks->a, stacks->alen)]);
		// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
		if (	stacks->b[0] < stacks->a[find_min(stacks->a, stacks->alen)] &&
				stacks->a[0] == stacks->a[find_min(stacks->a, stacks->alen)])
		{
			// ft_printf("push_back: push to a 1\n");
			op_p(stacks, 'a');			
		}
		else if (stacks->b[0] > stacks->a[stacks->alen - 1])
		{
			// ft_printf("push_back: push to a 2\n");
			op_p(stacks, 'a');
		}
		else
			op_q(stacks, 'a');
	}
	// ft_printf("out: push back\n");
}

int	sorted(int *a, int len)
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
	// while (	i < len - 1) 
	// {

	// 	if (	a[i] > a[i + 1]) 
	// 		if (i == max_index && a[i + 1] == a[min])
	// 			return (1);
	// 		return (0);
	// 	i++;
	// }
	return (1);
}

void	orientate(t_stack *stacks)
{
	while (1)
	{
		if (stacks->a[0] == stacks->a[find_min(stacks->a, stacks->alen)])
			break ;
		op_q(stacks, 'a');
	}
}

void	post_sort(t_stack *stacks)
{
	// printf("in post sort\n");
	if (!sorted(stacks->a, stacks->alen))
	{
		// ft_printf("not sorted\n");
		op_s(stacks, 'a');
	}
	if (stacks->a[1] == stacks->a[find_min(stacks->a, stacks->alen)])
		op_r(stacks, 'a');
	if (stacks->a[2] == stacks->a[find_min(stacks->a, stacks->alen)])
		op_q(stacks, 'a');
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);

	push_back(stacks);
	orientate(stacks);

	// ft_printf("out: post_sort\n");
}












































