/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:05:04 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/16 11:33:10 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	dispatcher(t_stack stacks, char* op)
{
	if (!ft_strcmp(op, "sa"))
		sa(stacks);
	else if (!ft_strcmp(op, "sb"))
		sb(stacks);
	else if (!ft_strcmp(op, "ss"))
		ss(stacks);
	else if (!ft_strcmp(op, "pa"))
		pa(stacks);
	else if (!ft_strcmp(op, "pb"))
		pb(stacks);
	else if (!ft_strcmp(op, "ra"))
		ra(stacks);
	else if (!ft_strcmp(op, "ra"))
		ra(stacks);
	else if (!ft_strcmp(op, "rb"))
		rb(stacks);
	else if (!ft_strcmp(op, "rr"))
		rr(stacks);
	else if (!ft_strcmp(op, "rra"))
		rra(stacks);
	else if (!ft_strcmp(op, "rrb"))
		rrb(stacks);
	else if (!ft_strcmp(op, "rrr"))
		rrr(stacks);
}


t_stack	*pop_stack_obj(int *a, int alen)
{
	ft_printf("pop_obj: in\n");
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

	stacks = pop_stack_obj(a, alen);
	i = 0;
	while (tab[i] != 0)
	{
		ft_printf("checker: top op: %s\n", ft_pop_str(tab));
	 	// dispatcher(stacks, ft_pop_str(tab));
	}

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
		i = ft_pusharr(a, ft_atoi(argv[i]), i);
	}
	return (1);
}

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
		ft_puttab(tab);
		free(line);
	}
	checker(a, argc, tab);
	ft_putarr(a, argc);
	return (0);	
}























