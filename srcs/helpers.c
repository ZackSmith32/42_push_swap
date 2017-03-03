/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:47:07 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/01 22:18:59 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_xor_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void	ft_rev_rotate(int **a, int len)
{
	int		i;
	int		*new;

	new = (int *)ft_memalloc(sizeof(int) * len);
	new[0] = (*a)[len - 1];
	i = 1;
	while (i < len)
	{
		new[i] = (*a)[i - 1];
		i++;
	}
	free(*a);
	*a = new;
}

int		ret_greater(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	print_moves(t_moves *moves)
{
	ft_printf("strat = %d\n", moves->strat);
	ft_printf("index = %d\n", moves->index);
	ft_printf("total = %d\n", moves->total);
	ft_printf("af = %d\n", moves->af);
	ft_printf("ar = %d\n", moves->ar);
	ft_printf("bf = %d\n", moves->bf);
	ft_printf("br = %d\n", moves->br);
}

int		check_dupes(int *a, int alen)
{
	int		i;
	int		j;

	i = 0;
	while (i < alen)
	{
		j = i + 1;
		while (j < alen)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
