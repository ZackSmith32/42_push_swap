/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:47:07 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 12:56:25 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

