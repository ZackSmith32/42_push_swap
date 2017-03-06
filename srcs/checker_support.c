/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_support.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 23:01:17 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/06 11:19:41 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	ft_printf("OK\n");
	return ;
}

int		check_line(char *line)
{
	if (!ft_strcmp(line, "sa")
		|| !ft_strcmp(line, "sb")
		|| !ft_strcmp(line, "ss")
		|| !ft_strcmp(line, "pa")
		|| !ft_strcmp(line, "pb")
		|| !ft_strcmp(line, "ra")
		|| !ft_strcmp(line, "rb")
		|| !ft_strcmp(line, "rr")
		|| !ft_strcmp(line, "rra")
		|| !ft_strcmp(line, "rrb")
		|| !ft_strcmp(line, "rrr"))
		return (1);
	return (0);
}

int		read_args(char ***tab)
{
	char	*line;
	int		j;

	j = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!check_line(line))
		{
			ft_printf("%@red@s %s\n", "GNL Error", line);
			// exit(1);
		}
		// ft_printf("%s\n", line);
		ft_push_str(tab, line);
		// ft_bzero(line, ft_strlen(line));
		free(line);
		j++;
	}
	// printf("op count = %d\n", j);
	// ft_printf("%d\n", j);
	free(line);
	return (j);
}

int		check_flags_checker(int argc, char **argv)
{
	int		num_flags;

	num_flags = 0;
	if (ft_strcmp(argv[1], "-n") == 0)
		num_flags++;
	return (num_flags);
}
