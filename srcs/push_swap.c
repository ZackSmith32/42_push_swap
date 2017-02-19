/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:19:08 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/18 19:22:47 by zsmith           ###   ########.fr       */
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
 *	> top of stack is front of stack (smallest index)
 *	> top of stack should be smallest number
 *	> stacks->alen = length (not index)
 */

/*
**	strat 0 = af bf
**	strat 1 = ar br
**	strat 2 = af br
**	strat 3 = ar bf
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
		strat_one(stacks, moves->ar, moves->br);
	}
	if (moves->strat == 2)
	{
		strat_two(stacks, moves->af, moves->br);
	}
	if (moves->strat == 3)
		strat_three(stacks, moves->ar, moves->bf);
	// ft_printf("%@blue@s", "===============================\n");
}


void	eval_moves(t_stack *stacks, t_moves *moves)
{
	int		i;
	t_moves	*min;

	min = (t_moves*)ft_memalloc(sizeof(t_moves));
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	i = 0;
	while (i < stacks->alen)
	{
		min->af = i;
		min->ar = stacks->alen - i;
		// ft_printf("~~~~~ eval [%d] = %d~~~~~\n", i, stacks->a[i]);
		calc_b(stacks, min, stacks->a[i]);
		calc_strategy(min->af, min->ar, min->bf, min);
		// printf("af=%d, ar=%d, bf=%d, br=%d tot=%d\n", min->af,min->ar,min->bf,min->br, min->total);
		if (i == 0 || moves->total > min->total)
		{
			// ft_printf("%@green@s\n", "new min!");
			*moves = *min;
		}
		// ft_printf("moves: %p, min: %p\n", moves, min);
		// print_moves(moves);
		i++;
	}
	free(min);
}

void	output(t_stack *stacks)
{
	int		i;
	int		j;

	i = 0;
	while (stacks->operations[i] != 0)
	{
		j = 0;
		while (stacks->operations[i][j] != 0)
		{
			write(0, &stacks->operations[i][j], 1);
			j++;
		}
		write(0, "\n", 1);
		// ft_printf("%s\n", *stacks->operations);
		// free(*(stacks->operations));
		// (stacks->operations)++;
		i++;
	}
}

void	push_swap(int *a, int alen)
{
	t_stack		*stacks;
	t_moves		*moves;
	int			i;

	ft_printf("in: push_swap\n");
	moves = (t_moves*)ft_memalloc(sizeof(t_moves));
	stacks = make_stack_obj(a, alen);
	op_p(stacks, 'b');
	op_p(stacks, 'b');
	// ft_printf("after ops\n");
	while (stacks->alen > 3)
	{
		eval_moves(stacks, moves);
		make_move(stacks, moves) ;
	}
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	post_sort(stacks);
	// ft_puttab(stacks->operations);
	output(stacks);
	// ft_printf("%@cyan@s\n", "~~~~~~~~~~~~~~~~~~~~~~~~~~  FINAL ~~~~~~~~~~~~~~~~~~~~~~~~~~");
	ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	// i = 0;
	while ((stacks->operations)[i] != 0)
		i++;
	ft_printf("%s%d\n", "count = ", i);
	// ft_puttab(stacks->operations);
	// ft_printf("%@cyan@s\n", "~~~~~~~~~~~~~~~~~~~~~~~~~~  FINAL ~~~~~~~~~~~~~~~~~~~~~~~~~~");
	ft_free_tab(stacks->operations);
	free(stacks->operations);
	// free(a);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	free(moves);
}


// need to free a
// free moves
// free stacks
// free stacks->operatinos

int		ft_word_count2(char const *s, char c)
{
	int		w;
	int		i;

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
	char	**temp;

	if (argc <= 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	// temp = (char **)ft_memalloc(sizeof(char *));
	a = (int *)ft_memalloc(sizeof(int) * 1);
	if (argc == 2)
	{	
		argc = ft_word_count(argv[1], ' ');
		ft_printf("words = %d\n", argc);
		temp = ft_strsplit(argv[1], ' ');
		if (!data_validate(argc, temp, &a))
		{
			ft_put_error("Error data validate\n");
			return (0);
		}
		ft_free_tab(temp);
		free(temp);
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




