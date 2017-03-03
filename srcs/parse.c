/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:43:31 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/01 23:09:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int		ft_is_num(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		check_flags(int argc, char **argv)
{
	int		num_flags;

	num_flags = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
		num_flags++;
	return (num_flags);
}

/*
**	check if the first num arg is a num
**		if yes: then the input is separate num args
**		if no: then input is string of nums
**	num_args: number of elements to be sorted
**	args: just the elements to be sorted
*/

int		parse(int argc, char **argv, int **a, int num_flags)
{
	char	**temp;
	int		num_args;
	char	**args;

	num_args = argc - num_flags - 1;
	args = argv + num_flags + 1;
	if (ft_strlen(*args) == 0)
	{
		ft_put_error("Error\n");
		return (0);
	}
	if (!ft_is_num(args[0]))
	{
		num_args = ft_word_count2(args[0], ' ');
		temp = ft_strsplit(args[0], ' ');
		if (!ft_put_error_bool(data_validate(num_args, temp, a), "Error\n"))
			return (0);
		ft_free_tab(temp);
		free(temp);
	}
	else if (!ft_put_error_bool(data_validate(num_args, args, a), "Error\n"))
		return (0);
	return (num_args);
}

/*
**	num flags is for if there are flag arguments in argv, if there aren't
**	any, then num_flags is 0
**	should I return the length of the arr?  no, but I will do that in
**	the calling function (parse) by returning argc.
*/

int		data_validate(int num_args, char **args, int **a)
{
	int			i;
	int			j;
	long long	k;

	i = 0;
	while (i < num_args)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (ft_isdigit(args[i][j]))
				j++;
			else
				return (0);
		}
		k = ft_atol(args[i]);
		if (k > INT_MAX)
			return (0);
		i = ft_append_arr(a, k, i);
	}
	if (check_dupes(*a, num_args) == 0)
		return (0);
	return (1);
}
