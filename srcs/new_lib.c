/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:25:54 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/16 00:22:16 by zsmith           ###   ########.fr       */
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



void	push_str(char ***tab, char *ptr)
{
	ft_printf("~~~~~pushstr_tab: in~~~~\n");
	ft_puttab(*tab);
	int		i;
	int		j;
	char	**new;

	printf("*tab = %p\n", *tab);
	printf("**tab = %s\n", **tab);
	printf("ptr = %s\n", ptr);

	if ((*tab)[0] == 0)
	{
		*tab = (char **)ft_memalloc(sizeof(char *) * 2);
		(*tab)[0] = ft_strdup(ptr);
		return ;
	}
	i = 0;
	while ((*tab)[i] != 0)
	{
		i++;
	}
	ft_printf("%d\n", i);
	ft_printf("%d\n", sizeof(char *) * (i + 2));
	new = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	j = 0;
	while (j < i)
	{
		new[j] = (*tab)[j];
		printf("while: j = %d, new[j] = %s, (*tab)[j]  = %s\n", j, new[j], (*tab)[j]);
		j++;
	}
	printf("j = %d\n", j);
	printf("ptr = %s\n", ptr);
	new[j] = ft_strdup(ptr);
	j++;
	new[j] = NULL;
	if (j == 2)
	{
		printf("new[%d] = %s\n", 0, new[0]);
		printf("new[%d] = %s\n", 1, new[1]);
		printf("new[%d] = %s\n", 2, new[2]);
	}
	ft_puttab(new);


	// free(*tab);
	*tab = new;
	ft_puttab(*tab);


}










































