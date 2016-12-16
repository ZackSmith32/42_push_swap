/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:25:54 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/16 11:23:36 by zsmith           ###   ########.fr       */
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

int		ft_push_str(char ***tab, char *ptr)
{
	int		i;
	int		j;
	char	**new;

	if ((*tab)[0] == 0)
	{
		*tab = (char **)ft_memalloc(sizeof(char *) * 2);
		(*tab)[0] = ft_strdup(ptr);
		return (0);
	}
	i = 0;
	while ((*tab)[i] != 0)
		i++;
	new = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	j = 0;
	while (j < i)
	{
		new[j] = (*tab)[j];
		j++;
	}
	new[j] = ft_strdup(ptr);
	new[++j] = NULL;
	*tab = new;
	return(j);
}

char	*ft_pop_str(char **tab)
{
	int		i;
	char	*ret;

	i = 0;
	while (tab[i] != 0)
		i++;
	i--;
	ret = ft_strdup(tab[i]);
	free(tab[i]);
	tab[i] = 0;
	return(ret);
}


void	ft_keyhook(void)
{
	char	buff[2];
	while (1)
	{
		if (read(0, buff, 1))
			break;
	}
	write(1, "exited loop\n", 12);
}








































