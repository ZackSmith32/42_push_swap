/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:05:04 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/19 22:13:17 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dispatcher(t_stack *stacks, char* op)
{
	// ft_printf("dispatcher: op = %s\n", op);
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
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
	// ft_printf("a: alen = %d\n", stacks->alen);
	// ft_put_arr(stacks->a, stacks->alen);
	// ft_printf("b: blen = %d\n", stacks->blen);
	// ft_put_arr(stacks->b, stacks->blen);
}

void	is_ordered(t_stack *stacks)
{
	int		i;

	if (stacks->b[0])
	{
		ft_printf("KO\n");
		return ;
	}
	i = 0;
	while (i < stacks->alen - 1)
	{
		if ((stacks->a)[i] > (stacks->a)[i + 1])
		{
			ft_printf("KO order\n");
			return ;
		}
		i++;
	}
	ft_printf("OK\n");
	return ;
}

void	checker(int *a, int alen, char **tab)
{
	int			i;
	t_stack		*stacks;

	// ft_printf("in checker\n");
	stacks = make_stack_obj(a, alen);
	i = 0;
	while (tab[0] != 0)
	{
		// ft_printf("command:");
		// ft_printf("++++++++++++++++++++++++++++++++\n");
		// ft_puttab(tab);
	 	dispatcher(stacks, ft_pop_str(tab));
	 	i++;
	}
	is_ordered(stacks);
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	ft_free_tab(tab);
	// ft_put_two_arr(stacks->a, stacks->alen, stacks->b, stacks->blen);
}

/*
**	issue discovered where the tab is populated with an empty space in it.
**	issue occurs once about every 10 runs, textbook memory leak
**	neet to check get_next_line for mem leaks and the tab parsing at the 
**	botom of main.
**	>> think I fixed this by modifyin push_arr, so that id str_dup's 
**	>> new entries
*/

int		main(int argc, char **argv)
{
	int		*a;
	char	*line;
	char	**tab;
	char	**temp;
	int 	j;
	int 	z;


	if (argc <= 1)
	{
		ft_put_error("Error: number of arguments\n");
		return (0);
	}
	a = (int *)ft_memalloc(sizeof(int) * 1);
	if (argc == 2)
	{	
		argc = ft_word_count(argv[1], ' ');
		temp = ft_strsplit(argv[1], ' ');
		if (!data_validate(argc, temp, &a))
		{
			ft_put_error("Error data validate\n");
			return (0);
		}
		ft_free_tab(temp);
		free(temp);
	}
	else if (!data_validate(--argc, ++argv, &a))
 	{
 		ft_put_error("Error data validate\n");
 		return (0);
 	}

	tab = (char **)ft_memalloc(sizeof(char *) * 1);
	j = 0;
	z = 0;
	while (get_next_line(0, &line) == 1)
	{
		// ft_printf("%s\n", line);
		ft_push_str(&tab, line);
		if (	!(
				!ft_strcmp(line, "pa") ||
				!ft_strcmp(line, "pb") ||
				!ft_strcmp(line, "sa") ||
				!ft_strcmp(line, "sb") ||
				!ft_strcmp(line, "ra") ||
				!ft_strcmp(line, "rb") ||
				!ft_strcmp(line, "rr") ||
				!ft_strcmp(line, "rra") ||
				!ft_strcmp(line, "rrb") ||
				!ft_strcmp(line, "rrr")
				)
			)
		{
			printf("NO line = %s  ***********************************\n", tab[j]);
			z = 1;
		}
		ft_bzero(line, ft_strlen(line));
		free(line);
		j++;
	}
	// int z = 0;
	// while (tab[j] != 0)
	// {
	// 	ft_printf("%s\n", tab[j]);
	// 	j++;
	// }
	// ft_puttab(tab);
	printf("count = %d\n", j);
	if (z == 1)
		ft_printf("there was an issue j = %d\n", j);
	checker(a, argc, tab);
	return (0);	
}























