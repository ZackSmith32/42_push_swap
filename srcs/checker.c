/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:05:04 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/16 00:18:30 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	char	*buf;
	int		ret;
	int		i;

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
		ft_printf("main:%s\n", line);
		ft_printf("pre  &tab = %p\n", &tab);
		push_str(&tab, line);
		ft_printf("post &tab = %p\n", &tab);
		ft_printf("main\n");
		ft_puttab(tab);
		free(line);
	}
	// ft_printf("[%s]>>", tab[0]);
	// ft_printf("[%s]>>", tab[1]);
	// ft_printf("[%s]>>", tab[2]);
	// ft_printf("[%s]>>", tab[3]);
	// ft_printf("tab[0] = %s\n", tab[0]);
	// pushstr_tab(&tab, 0);
	ft_putarr(a, argc);
	return (0);	
}























