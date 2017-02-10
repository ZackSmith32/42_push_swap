/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:19:08 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 16:04:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// need to free a
int		main(int argc, char **argv)
{
	int		*a;

	if (argc <= 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	a = (int *)ft_memalloc(sizeof(int) * 1);
	if (!data_validate(--argc, ++argv, &a))
	{
		ft_put_error("Error data validate\n");
		return (0);
	}
	tab = (char **)ft_memalloc(sizeof(char *) * 1);
	return (0);
}