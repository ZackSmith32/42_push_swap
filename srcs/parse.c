/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:43:31 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/25 21:13:45 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*make_stack_obj(int *a, int alen, int num_flags)
{
	t_stack		*stacks;
	char		*temp;

	// temp = (char *)ft_memalloc(sizeof(char));
	stacks = (t_stack *)ft_memalloc(sizeof(t_stack));
	stacks->a = a;
	stacks->alen = alen;
	stacks->b = (int *)ft_memalloc(sizeof(int));
	stacks->blen = 0;
	stacks->operations = (char **)ft_memalloc(sizeof(char*));
	stacks->print_flag = num_flags;
	// stacks->operations[0] = temp;
	return (stacks);
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
	if (strcmp(argv[1],  "-v") == 0)
		num_flags++;
	return (num_flags);
}

/*
 *	check if the first num arg is a num
 *		if yes: then the input is separate num args
 *		if no: then input is string of nums
 */
int		parse(int argc, char **argv, int **a, int num_flags)
{
	char	**temp;
	int		num_args;
	char	**args;

	// count of number arguments
	num_args = argc - num_flags - 1;
	// args starts with where the number arguments start
	args = argv + num_flags + 1;
	if (!ft_is_num(args[0]))
	{
		num_args = ft_word_count(args[0], ' ');
		temp = ft_strsplit(args[0], ' ');
		if (!ft_put_error_bool(data_validate(num_args, temp, a), "Error data validate\n"))
			return (0);
		ft_free_tab(temp);
		free(temp);
	}
	else
		if (!ft_put_error_bool(data_validate(num_args, args, a), "Error data validatee\n"))
			return (0);
	return (num_args);
}

/*
 *	num flags is for if there are flag arguments in argv, if there aren't
 *	any, then num_flags is 0
 *	should I return the length of the arr?  no, but I will do that in 
 *	the calling function (parse) by returning argc.
 */

int		data_validate(int num_args, char **args, int **a)
{
	int		i;
	int		j;

	i = 0;
	// ft_printf("data validate args[0] = %\n", args[0]);
	while (i < num_args)
	{
		// ft_printf("arg[%d] = %s\n", i, argv[i]);
		j = 0;
		while (args[i][j] != '\0')
		{
			if (ft_isdigit(args[i][j]))
				j++;
			else 
				return (0);
		}
		i = ft_append_arr(a, ft_atoi(args[i]), i);
	}
	// ft_printf("stack parsed:\n");
	// ft_put_arr(*a, i);
	return (1);
}



// need to redo the entire entrance sequence, parsing input and making sure that the 
// flags are captured in the struct

























