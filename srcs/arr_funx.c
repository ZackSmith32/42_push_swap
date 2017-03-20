/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_funx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:59 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/20 12:02:38 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_push_arr(int **a, int num, int len)
{
	int		*new;
	int		i;

	new = (int *)ft_memalloc(sizeof(int) * (len + 1));
	new[0] = num;
	i = 1;
	len++;
	while (i < len)
	{
		new[i] = (*a)[i - 1];
		i++;
	}
	free(*a);
	*a = new;
	return (i);
}

int		ft_append_arr(int **a, int num, int len)
{
	int		*new;
	int		i;

	new = (int *)ft_memalloc(sizeof(int) * (len + 1));
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
	int		*new;
	int		ret;
	int		i;

	ret = (*a)[0];
	new = (int *)ft_memalloc(sizeof(int) * (len - 1));
	i = 1;
	while (i < len)
	{
		new[i - 1] = (*a)[i];
		i++;
	}
	new[i - 1] = 0;
	free(*a);
	*a = new;
	return (ret);
}

t_stack	*make_stack_obj(int *a, int alen)
{
	t_stack		*stacks;

	stacks = (t_stack *)ft_memalloc(sizeof(t_stack));
	stacks->a = a;
	stacks->alen = alen;
	stacks->b = (int *)ft_memalloc(sizeof(int));
	stacks->blen = 0;
	stacks->operations = (char **)ft_memalloc(sizeof(char*));
	return (stacks);
}
