/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:25:54 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/01 22:32:38 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_put_error(char *str)
{
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
}

int		ft_put_error_bool(int bool, char *str)
{
	if (bool)
		return (1);
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
	return (0);
}

int		ft_greater_than(int a, int b)
{
	if (a >= b)
		return (1);
	else
		return (0);
}

void	ft_put_two_arr(int *a, int alen, int *b, int blen)
{
	int		i;

	i = 0;
	ft_printf("  A     B\n");
	while (i < (ft_greater_than(alen, blen) ? alen : blen))
	{
		if (i < alen)
			ft_printf("  %d     ", a[i]);
		else
			ft_printf("        ");
		if (i < blen)
			ft_printf("%d", b[i]);
		ft_printf("\n");
		i++;
	}
}

void	ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	while (*tab != 0)
	{
		free(*tab);
		(tab)++;
		i++;
	}
	free(*tab);
}
