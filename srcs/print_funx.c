/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:40:34 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/21 20:43:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void 	ft_put_two_arr(int *a, int alen, int *b, int blen)
// {
// 	int		i;

// 	i = 0;
// 	ft_printf("  A     B\n");
// 	while (i < (ft_greater_than(alen, blen) ? alen : blen))
// 	{
// 		if (i < alen)
// 			ft_printf("  %d     ", a[i]);
// 		else 
// 			ft_printf("        ");
// 		if (i < blen)
// 			ft_printf("%d", b[i]);
// 		ft_printf("\n");
// 		i++;
// 	}
// }

void	repeater_post(t_stack *stacks, char z, int a, void (*f)(t_stack*, char))
{
	int		i;

	i = 0;
	while (i < a)
	{
		f(stacks, z);
		i++;
	}
}
