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

/*
 *	Push_swap files:
 *	> push_swap
 *	> stack_calculation
 *	> strategies
 */

/*
 *	Always remember:
 *	> top of stack is end of stack (greatest index)
 *	> top of stack should be smallest number
 *	> stacks->alen = length (not index)
 */

void	make_move(t_stack *stacks, t_moves *moves)
{
	ft_printf("make_move\n");
	if (moves->strat == 0)
	{
		strat_zero(stacks, moves->af, moves->bf);
	}
	if (moves->strat == 1)
	{
		return ;
	}
	if (moves->strat == 2)
	{
		return ;
	}
	ft_printf("%@blue@s", "================================================================\n");
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
		// ft_printf("num: %d\n", stacks->a[i]);
		min->index = i;
		min->af = i;
		min->ar = stacks->alen - i;
		ft_printf("~~~~~ eval [%d] = %d~~~~~\n", i, stacks->a[i]);
		calc_b(stacks, min, stacks->a[i]);
		calc_strategy(min->af, min->ar, min->bf, min);
		printf("af=%d, ar=%d, bf=%d, br=%d tot=%d\n", min->af,min->ar,min->bf,min->br, min->total);
		if (i == 0 || moves->total > min->total)
		{
			ft_printf("%@green@s\n", "new min!");
			*moves = *min;
		}
		print_moves(moves);
		ft_printf("~~~~~           ~~~~~\n");
		// break;
		i++;
	}
	free(min);
}


void	push_swap(int *a, int alen)
{
	t_stack		*stacks;
	t_moves		*moves;

	moves = (t_moves*)ft_memalloc(sizeof(t_moves));
	stacks = make_stack_obj(a, alen);
	op_p(stacks, 'b');
	op_p(stacks, 'b');
	// op_p(stacks, 'b');
	// op_p(stacks, 'b');
	// op_p(stacks, 'b');
	while (stacks->alen != 0)
	{
		eval_moves(stacks, moves);
		make_move(stacks, moves) ;
		// break;
	}
	ft_printf("%@cyan@s\n", "~~~~~  FINAL ~~~~~");
	ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	ft_puttab(stacks->operations);
	ft_printf("%@cyan@s\n", "~~~~~  FINAL ~~~~~");
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}


// need to free a
// free moves
// free stacks
// free stacks->operatinos

int		ft_word_count2(char const *s, char c)
{
	int		w;
	int		i;
	printf("new lib\n");
	i = 0;
	w = 0;
	while (s[i] != '\0')
	{	
		if (i == 0 && s[i] != c)
		{
			i++;
			w++;
		}
		if (i == 0 && s[i] == c)
		{
			i++;
		}
		if (s[i - 1] == c && s[i] != c)
			w++;
		i++;
	}
	return (w);
}


int		main(int argc, char **argv)
{
	int		*a;

	if (argc <= 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	a = (int *)ft_memalloc(sizeof(int) * 1);
	if (argc == 2)
	{	
		argc = ft_word_count(argv[1], ' ');
		ft_printf("words = %d\n", argc);
	
		if (!data_validate(argc, ft_strsplit(argv[1], ' '), &a))
		{
			ft_put_error("Error data validate\n");
			return (0);
		}
	}
	// check for dupes
	else if (!data_validate(--argc, ++argv, &a))
	{
		ft_put_error("Error data validate\n");
		return (0);
	}
	push_swap(a, argc);
	return (0);
}


 // 4 5 16 7 50 1 8 51 



