/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:25:54 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/15 18:16:36 by zsmith           ###   ########.fr       */
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

void	ft_putarr(int *a, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d\n", a[i]);
		i++;
	}
}

int		ft_pusharr(int **a, int num, int len)
{
	int		*new;
	int		i;

	new = (int *)ft_memalloc(sizeof(int) * len + 1);
	i = 0;
	while (i < len)
	{
		new[i] = (*a)[i];
		i++;
	}
	new[i] = num;
	free(*a);
	*a = new;
	i++;
	return (i);
}

/*
**	tab comes in as a tripple pointer
**	this is so we can updae the tab without changing its address
*/
void	ft_pushtab(void *tab, void *ptr)
{
	int		i;
	int		j;
	void	*new;

	i = 0;
	while (*tab != 0)
		i++;
	new = (void *)ft_memalloc(sizeof(char *) * (i + 1));
	j = -1;
	while (++j < i)
		new[j] = (*tab)[j];
	new[j] = ptr;
	new[++j] = 0;
}
