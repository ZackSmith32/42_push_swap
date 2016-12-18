/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:59:49 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/17 22:01:11 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

typedef struct		s_swap
{
	int				*a;
	int				alen;
	int				*b;
	int				blen;
}					t_stack;

/*
**		new_lib
*/
void		ft_put_error(char *str);
void		ft_put_arr(int *a, int len);

int			ft_push_arr(int **a, int num, int len);
int			ft_pop_arr(int **a, int len);

int			ft_push_str(char ***tab, char *ptr);
char		*ft_pop_str(char **tab);
void		ft_xor_swap(int *a, int *b);

/*
**		op_s
*/
void		op_s(t_stack *stacks, char c);
void		op_p(t_stack *stacks, char c);




#endif