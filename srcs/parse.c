/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:43:31 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/24 00:02:27 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*make_stack_obj(int *a, int alen)
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
 *	Use argc as the length of the array
 */
int		parse(int argc, char **argv, int **a, int num_flags)
{
	char	**temp;

	if (ft_is_num(argv[num_flags + 1]))
		data_validate(argc -= (num_flags + 1), argv += (num_flags + 1), a, num_flags);
	else
	{
		argc = ft_word_count(argv[num_flags + 1], ' ');
		temp = ft_strsplit(argv[num_flags + 1], ' ');
		if (!data_validate(argc, temp, a, num_flags))
		{
			ft_put_error("Error data validate\n");
			return (0);
		}
		ft_free_tab(temp);
		free(temp);
		return (argc);
	}
	return (argc - num_flags);
}

/*
 *	num flags is for if there are flag arguments in argv, if there aren't
 *	any, then num_flags is 0
 *	should I return the length of the arr?  no, but I will do that in 
 *	the calling function (parse) by returning argc.
 */

int		data_validate(int argc, char **argv, int **a, int num_flags)
{
	int		i;
	int		j;

	i = num_flags + 1;
	while (i < argc)
	{
		// ft_printf("arg[%d] = %s\n", i, argv[i]);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else 
				return (0);
		}
		ft_printf("%s\n", argv[i]);
		i = ft_append_arr(a, ft_atoi(argv[i]), i);
	}
	ft_printf("stack parsed:\n");
	ft_put_arr(*a, i);
	return (1);
}



// need to redo the entire entrance sequence, parsing input and making sure that the 
// flags are captured in the struct

























