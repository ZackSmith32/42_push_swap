/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 22:26:43 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/17 00:56:03 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			parse_many_args(char **argv, char ***parsed_data)
{
	int		i;

	i = 0;
	while (argv[i] != 0)
	{
		printf("%s\n", argv[i]);
		if (!ft_isnum(argv[i]))
		{
			printf("not a number\n");
			return (0);
		}
		if (ft_strlen(argv[i]) > 19)
			return (0);
		i++;
	}
	*parsed_data = argv;
	return (1);
}



int			parse_string(char *stack, char ***parsed_data)
{
	char	**stack_tab;
	int		i;

	stack_tab = ft_strsplit(stack, ' ');
	if (ft_tablen(stack_tab) == 0)
		return (0);
	i = 0;
	while (stack_tab[i] != 0)
	{
		printf(">%s<\n", stack_tab[i]);
		if (!ft_isnum(stack_tab[i]))
		{
			ft_free_tab(stack_tab);
			free(stack_tab);
			printf("not a number\n");
			return (0);
		}
		if (ft_strlen(stack_tab[i]) > 19)
			return (0);
		i++;
	}
	*parsed_data = stack_tab;
	return (1);
}

int			parse_input_type(int argc, char **argv, char ***parsed_data)
{
	int		value_to_return;
	int		index;

	index = 1;
	if (ft_strequ(argv[1], "-v"))
	{
		index++;
		// set global to true!
	}
	if (argc - index == 0)
	{
		printf("no args\n");
		return (0);
	}
	if (argc - index > 1)
		value_to_return = parse_many_args(argv + index, parsed_data);
	else
		value_to_return = parse_string(argv[argc - 1], parsed_data);
	return (value_to_return);
}

int		populate_stack(char **parsed_data, int **a)
{
	int			array_index;
	long long	max_check;

	array_index = 0;
	while (parsed_data[array_index] != 0)
	{
		printf("%s\n", parsed_data[array_index]);
		max_check = ft_atol(parsed_data[array_index]);
		printf("MAX = %d\n", INT_MAX);
		printf("ck  = %lld\n", max_check);
		if (max_check > INT_MAX || max_check < INT_MIN)
		{
			ft_put_error("MAX Error\n");
			exit(1);
		}
		ft_append_arr(a, max_check, array_index + 1);
		array_index++;
	}
	return (array_index);
}























