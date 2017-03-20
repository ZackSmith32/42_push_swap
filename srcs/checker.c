/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:05:04 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/20 11:59:46 by zsmith           ###   ########.fr       */
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

char	**read_operations(void)
{
	int		num_ops;
	char	**tab;

	tab = (char **)ft_memalloc(sizeof(char *));
	num_ops = read_args(&tab);
	return (tab);
}

void	checker(int *a, int alen)
{
	int			i;
	t_stack		*stacks;
	char		**tab;
	int			tab_len;

	tab = read_operations();
	tab_len = ft_tablen(tab);
	stacks = make_stack_obj(a, alen);
	i = 0;
	while (tab[0] != 0)
	{
		dispatcher(stacks, ft_pop_str(tab));
		i++;
	}
	is_ordered(stacks);
	if (g_count_flag)
		ft_printf("operations count = %d\n", tab_len);
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
	char	**parsed_data;
	int		alen;

	if (argc <= 1)
	{
		ft_put_error("Error\n");
		return (0);
	}
	if (!parse_input_type(argc, argv, &parsed_data))
	{
		ft_put_error("Error\n");
		return (0);
	}
	alen = populate_stack(&parsed_data, &a);
	checker(a, alen);
	return (0);
}
