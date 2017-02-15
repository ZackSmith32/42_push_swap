/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_funx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:59 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 12:51:27 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		ft_append_arr(int **a, int num, int len)
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
	i++;
	free(*a);
	*a = new;
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