/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:40:34 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/25 21:10:07 by zsmith           ###   ########.fr       */
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

void	fun_stacks(t_stack *stacks, t_moves *moves, int anum, int bnum)
{
	int		i;
	int		j;

	j = 0;
	i = ft_greater_than(stacks->alen, stacks->blen) ? stacks->alen : stacks->blen;
	ft_printf("\033[2J\033[1;1H");
	ft_printf("%@underline@5s %@underline@s%@underline@4s\n", "A", "B", "");
	while (j < i)
	{
		if (stacks->a[j] == anum && j < stacks->alen)
			ft_printf("%@green@5d ", stacks->a[j]);
		else if (j < stacks->alen)
			ft_printf("%5d ", stacks->a[j]);
		else
			ft_printf("      ");
		if (stacks->b[j] == bnum && j < stacks->blen)
			ft_printf("%@magenta@d", stacks->b[j]);
		else if (j < stacks->blen)
			ft_printf("%d", stacks->b[j]);
		printf("\n");
		j++;
	}
	printf("\n");
	ft_keyhook('\n');
}

t_move_dir make_md(char z, int a)
{
	t_move_dir	data;

	data.a = a;
	data.z = z;
	return (data);
}