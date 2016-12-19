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
	// ft_printf("push: in: num = %d; len = %d\n", num, len);
	// ft_put_arr(*a, len);

	int		*new;
	int		i;

	new = (int *)ft_memalloc(sizeof(int) * len + 1);
	new[0] = num;
	i = 1;
	len++;
	while (i < len)
	{
		new[i] = (*a)[i - 1];
		i++;
	}
	free(*a);
	/*
	**	need to figure out what the difference is between the following line
	**	an a = &new
	**	answer: a is the address of *a, the address of *a is used outside this funchtion
	**	when you do a = &new you are pointin a somewhere else, but what you want is 
	**	to change the memory that a is already pointing at.  hence the notation bellow.
	*/
	*a = new;
	// ft_printf("push: out: i = %d\n", i);
	// ft_put_arr(*a, i);
	return (i);
}

int		ft_pop_arr(int **a, int len)
{
	// ft_printf("pop_arr: in: len = %d\n", len);
	// ft_put_arr(*a, len);
	int		*new;
	int		ret;
	int		i;

	ret = (*a)[0]; 
	new = (int *)ft_memalloc(sizeof(int) * len - 1);
	i = 1;
	while (i < len)
	{
		new[i - 1] = (*a)[i];
		i++;
	}
	new[i - 1] = 0;
	free(*a);
	*a = new;
	// ft_printf("pop_arr: out: ret = %d\n", ret);
	// ft_put_arr(*a, len);
	return (ret);
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
	free(*tab);
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



































