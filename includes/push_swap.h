/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:20:45 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 15:43:33 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"

typedef struct		s_swap
{
	int				*a;
	int				alen;
	int				*b;
	int				blen;
}	
				t_stack;
/*
**			parse
*/
int			data_validate(int argc, char **argv, int **a);
t_stack		*make_stack_obj(int *a, int alen);

/*
**			arr_funx
*/
void		ft_put_arr(int *a, int len);
int			ft_push_arr(int **a, int num, int len);
int			ft_append_arr(int **a, int num, int len);
int			ft_pop_arr(int **a, int len);

/*
**			str_funx
*/
int			ft_push_str(char ***tab, char *ptr);
char		*ft_pop_str(char **tab);

/*
**			helpers
*/
void		ft_xor_swap(int *a, int *b);
void		ft_rev_rotate(int **a, int len);

/*
**			new_lib
*/
void		ft_put_error(char *str);
void		ft_free_tab(char **tab);
int			ft_greater_than(int a, int b);
void		ft_keyhook(char c);
void 		ft_put_two_arr(int *a, int alen, int *b, int blen);

/*
**		op_s
*/
void		op_s(t_stack *stacks, char c);
void		op_p(t_stack *stacks, char c);
void		op_r(t_stack *stacks, char c);
void		op_q(t_stack *stacks, char c);


#endif