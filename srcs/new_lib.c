/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:25:54 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/16 17:26:24 by zsmith           ###   ########.fr       */
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

void	ft_put_arr(int *a, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d\n", a[i]);
		i++;
	}
}

/*
**	This is a realloc for an int pointer
**	Update: take in an in pointer, make possible to add multiple ints
*/
int		ft_push_arr(int **a, int num, int len)
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

int		ft_pop_arr(int **a, int len)
{
	int		*new;
	int		i;

	new = (int *)ft_memalloc(sizeof(int) * len);
	i = 1;
	while (i < len)
	{
		new[i - 1] = (*a)[i];
		i++;
	}
	i = (*a)[0];
	return (i);
}

/*
**	This is a realloc for a double pointer.  Pass in &tab, the function will place the address 
**	to a new memory allocation in the place where the old pointer was.
**	Update: create a realloc funcion.
*/
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
	// ft_printf("pop_str: in:\n");
	// ft_puttab(tab);
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (tab[i] != 0)
		i++;
	ret = ft_strdup(tab[0]);
	while (j < i)
	{
		free(tab[j]);
		tab[j] = ft_strdup(tab[j + 1]);
		j++;
	}
	free(tab[j]);
	tab[j] = 0;
	// ft_puttab(tab);
	// ft_printf("pop_str: out:\n");
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

void	ft_xor_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}






































