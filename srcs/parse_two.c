/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 22:26:43 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/22 11:56:38 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			parse_many_args(char **argv, char ***parsed_data)
{
	int		i;

	i = 0;
	*parsed_data = ft_memalloc(sizeof(char *) * ft_tablen(argv));
	while (argv[i] != 0)
	{
		if (!ft_isnum(argv[i]))
		{
			ft_free_tab(*parsed_data);
			free(*parsed_data);
			return (0);
		}
		if (ft_strlen(argv[i]) > 19)
			return (0);
		ft_push_str(parsed_data, argv[i]);
		i++;
	}
	return (1);
}

int			parse_string(char *stack, char ***parsed_data)
{
	int		i;

	*parsed_data = ft_strsplit(stack, ' ');
	if (ft_tablen(*parsed_data) == 0)
		return (0);
	i = 0;
	while ((*parsed_data)[i] != 0)
	{
		if (!ft_isnum((*parsed_data)[i]))
		{
			ft_free_tab(*parsed_data);
			free(*parsed_data);
			return (0);
		}
		if (ft_strlen((*parsed_data)[i]) > 19)
			return (0);
		i++;
	}
	return (1);
}

int			parse_input_type(int argc, char **argv, char ***parsed_data)
{
	int		value_to_return;
	int		index;

	index = 1;
	if (ft_strequ(argv[1], "-v") || ft_strequ(argv[1], "-n"))
	{
		if (ft_strequ(argv[1], "-v"))
			g_verbose_flag = 1;
		if (ft_strequ(argv[1], "-n"))
			g_count_flag = 1;
		index++;
	}
	if (argc - index == 0)
		return (0);
	if (argc - index > 1)
		value_to_return = parse_many_args(argv + index, parsed_data);
	else
		value_to_return = parse_string(argv[argc - 1], parsed_data);
	return (value_to_return);
}

void		check_duplicates(int *a, int alen)
{
	int		i;
	int		j;

	i = 0;
	while (i < alen)
	{
		j = i;
		while (++j < alen)
			if (a[i] == a[j])
			{
				free(a);
				ft_put_error("Error\n");
				exit(1);
			}
		i++;
	}
}

int			populate_stack(char ***parsed_data, int **a)
{
	int			array_index;
	long long	max_check;

	array_index = 0;
	while ((*parsed_data)[array_index] != 0)
	{
		max_check = ft_atol((*parsed_data)[array_index]);
		if (max_check > INT_MAX || max_check < INT_MIN)
		{
			ft_put_error("Error\n");
			exit(1);
		}
		ft_append_arr(a, max_check, array_index);
		array_index++;
	}
	ft_free_tab(*parsed_data);
	free(*parsed_data);
	check_duplicates(*a, array_index);
	return (array_index);
}
