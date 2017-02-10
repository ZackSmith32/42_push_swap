/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:19:08 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 22:14:41 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	make_move(t_stack *stacks, t_moves *moves)
{
	if (moves->strat = 0)
	{
		strat_one(stacks, moves->af, moves->bf);
	}
	if (moves->strat = 1)
	{
		
	}
	if (moves->strat = 2)
	{
		
	}

}

/*
**	strat 0 = af bf
**	strat 1 = ar bf
**	strat 2 = af br
**	strat 3 = ar bf
*/

void	eval_moves(t_stack *stacks, t_moves *moves)
{
	int		i;
	t_moves	*min;

	min = (t_moves*)ft_memalloc(sizeof(t_moves));
	ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	i = 0;
	while (i < stacks->alen)
	{
		ft_printf("num: %d\n", stacks->a[i]);
		min->index = i;
		min->af = i;
		min->ar = stacks->alen - i;
		calc_b(stacks, min, stacks->a[i]);
		calc_strategy(min->af, min->ar, min->bf, min);
		printf("af=%d, ar=%d, bf=%d, br=%d\n", min->af,min->ar,min->bf,min->br);
		if (!moves->total || moves->total < min->total)
		{
			*moves = *min;
		}
		break;
	}
}


void	push_swap(int *a, int alen, char **tab)
{
	t_stack		*stacks;
	t_moves		*moves;

	moves = (t_moves*)ft_memalloc(sizeof(t_moves));
	stacks = make_stack_obj(a, alen);
	op_p(stacks, 'b');
	op_p(stacks, 'b');
	op_p(stacks, 'b');
	op_p(stacks, 'b');
	op_p(stacks, 'b');
	while (stacks->alen != 0)
	{
		eval_moves(stacks, moves);
		print_moves(moves);
		// make_move(stacks, moves) 
		break;
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	ft_free_tab(tab);
}


// need to free a
// free tab
// free moves
int		main(int argc, char **argv)
{
	int		*a;
	char	**tab;

	if (argc <= 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	a = (int *)ft_memalloc(sizeof(int) * 1);
	// check for dupes
	if (!data_validate(--argc, ++argv, &a))
	{
		ft_put_error("Error data validate\n");
		return (0);
	}
	tab = (char **)ft_memalloc(sizeof(char *) * 1);
	push_swap(a, argc, tab);
	return (0);
}