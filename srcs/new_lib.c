/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:25:54 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 12:55:37 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_put_error(char *str)
{
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}	
}

void	ft_keyhook(char c)
{
	char	buff[2];

	while (1)
	{
		ft_printf("in while");
		if (read(0, buff, 1))
			break;
	}
	write(1, "exited loop\n", 12);
}

int		ft_greater_than(int a, int b)
{
	if (a >= b)
		return 1;
	else
		return 0;
}

void 	ft_put_two_arr(int *a, int alen, int *b, int blen)
{
	int		i;

	i = 0;
	ft_printf("  A     B\n");
	while (i < (ft_greater_than(alen, blen) ? alen : blen))
	{
		if (i < alen)
			ft_printf("  %d", a[i]);
		ft_printf("     ");
		if (i < blen)
			ft_printf("%d", b[i]);
		ft_printf("\n");
		i++;
	}
}

void	ft_free_tab(char **tab)
{
	ft_printf("in free tab\n");
	int 	i;
	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

