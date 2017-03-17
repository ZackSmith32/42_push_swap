/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:05:04 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 19:26:57 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dispatcher(t_stack *stacks, char *op)
{
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
	free(op);
}

void	checker(int *a, int alen, char **tab, int num_flags)
{
	int			i;
	t_stack		*stacks;

	stacks = make_stack_obj(a, alen, num_flags);
	i = 0;
	while (tab[0] != 0)
	{
		dispatcher(stacks, ft_pop_str(tab));
		i++;
	}
	is_ordered(stacks);
	free(stacks->a);
	free(stacks->b);
	ft_free_tab(stacks->operations);
	free(stacks->operations);
	free(stacks);
	ft_free_tab(tab);
	free(tab);
}

int		main(int argc, char **argv)
{
	int		*a;
	char	**tab;
	int		j;
	int		num_flags;
	int		operations;

	j = 0;
	if (argc <= 1)
	{
		return (0);
	}
	a = (int *)ft_memalloc(sizeof(int) * 1);
	num_flags = check_flags_checker(argv);
	argc = parse(argc, argv, &a, num_flags);
	if (argc == 0)
		return (0);
	tab = (char **)ft_memalloc(sizeof(char *) * 1);
	operations = read_args(&tab);
	checker(a, argc, tab, num_flags);
	if (num_flags)
		ft_printf("%@white@s %d\n", "operations:", operations);
	return (0);
}
