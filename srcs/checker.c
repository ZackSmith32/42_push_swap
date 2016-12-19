/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:05:04 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/16 17:30:10 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	dispatcher(t_stack *stacks, char* op)
{
	ft_printf("dispatcher: op = %s\n", op);
	if (!ft_strcmp(op, "sa"))
		op_s(stacks, 'a');
	else if (!ft_strcmp(op, "sb"))
		op_s(stacks, 'b');
	else if (!ft_strcmp(op, "ss"))
		op_s(stacks, 'c');
	else if (!ft_strcmp(op, "pa"))
		op_p(stacks, 'a');
	else if (!ft_strcmp(op, "pb"))
		op_p(stacks, 'b');
	else if (!ft_strcmp(op, "ra"))
		op_r(stacks, 'a');
	else if (!ft_strcmp(op, "rb"))
		op_r(stacks, 'b');
	else if (!ft_strcmp(op, "rr"))
		op_r(stacks, 'r');
	else if (!ft_strcmp(op, "rra"))
		op_q(stacks, 'a');
	else if (!ft_strcmp(op, "rrb"))
		op_q(stacks, 'b');
	else if (!ft_strcmp(op, "rrr"))
		op_q(stacks, 'r');
	ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	// ft_printf("a: alen = %d\n", stacks->alen);
	// ft_put_arr(stacks->a, stacks->alen);
	// ft_printf("b: blen = %d\n", stacks->blen);
	// ft_put_arr(stacks->b, stacks->blen);
}


t_stack	*make_stack_obj(int *a, int alen)
{
	// ft_printf("make_stack_obj: in\n");
	t_stack		*stacks;

	stacks = (t_stack *)ft_memalloc(sizeof(t_stack));
	stacks->a = a;
	stacks->alen = alen;
	stacks->b = (int *)ft_memalloc(sizeof(int));
	stacks->blen = 0;
	return (stacks);
}

void	checker(int *a, int alen, char **tab)
{
	int			i;
	t_stack		*stacks;

	stacks = make_stack_obj(a, alen);
	i = 0;
	while (tab[0] != 0)
	{
		ft_printf("command:");
		ft_puttab(tab);
	 	dispatcher(stacks, ft_pop_str(tab));
	 	i++;
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	ft_free_tab(tab);
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
}

int		data_validate(int argc, char **argv, int **a)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else 
				return (0);
		}
		i = ft_push_arr(a, ft_atoi(argv[i]), i);
	}
	ft_printf("stack parsed:\n");
	ft_put_arr(*a, i);
	return (1);
}

/*
**	issue discovered where the tab is populated with an empty space in it.
**	issue occurs once about every 10 runs, textbook memory leak
**	neet to check get_next_line for mem leaks and the tab parsing at the 
**	botoom of main.
*/

int		main(int argc, char **argv)
{
	int		*a;
	char	*line;
	char	**tab;

	if (argc <= 1)
	{
		ft_put_error("Error: number of arguments\n");
		return (0);
	}
	a = (int *)ft_memalloc(sizeof(int) * 1);
	if (!data_validate(--argc, ++argv, &a))
	{
		ft_put_error("Error\n");
		return (0);
	}
	tab = (char **)ft_memalloc(sizeof(char *));
	while (get_next_line(0, &line) == 1)
	{
		ft_push_str(&tab, line);
		free(line);
	}
	checker(a, argc, tab);
	return (0);	
}























