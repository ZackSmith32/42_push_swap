/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:20:45 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/23 23:43:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"

typedef struct		s_swap
{
	int				*a;
	int				alen;
	int				*b;
	int				blen;
	char			**operations;
	// t_moves			**stacks_ptr;
}					t_stack;

typedef struct		s_list_moves
{
	int				af;
	int				ar;
	int				bf;
	int				br;
	int				total;
	int				strat;
	int				index;
	int				print_flag;
}					t_moves;

typedef struct		s_gnl
{
	int				fd;
	char			*content;
	size_t			content_size;
	struct s_gnl	*next;
}					t_gnl;

/*
 *	ft_putarr
 */
void	ft_putarr(int *a, int len);

/*
 *	ft_keyhook
 */
int			ft_keyhook(char key);
void		fun_stacks(t_stack *stacks, t_moves *moves, int anum, int bnum);

/*
 *	print_funx
 */
void		repeater_post(t_stack *stacks, char z, int a, void (*f)(t_stack*, char));

/*
 *	get_next_line
 */

int			get_next_line(const int fd, char **line);

/*
 *			post_sort.c
 */
void		post_sort(t_stack *stacks);

/*
 *			strategies.c
 */
void		repeater(t_stack *stacks, char z, int a, void (*f)(t_stack*, char), t_moves *moves);
void		strat_zero(t_stack *stacks, int af, int bf, t_moves *moves);
void		strat_one(t_stack *stacks, int ar, int br, t_moves *moves);
void		strat_two(t_stack *stacks, int ar, int br, t_moves *moves);
void		strat_three(t_stack *stacks, int ar, int br, t_moves *moves);

/*
**			stack calculatin
*/
void		calc_b(t_stack *stacks, t_moves *moves, int num);
void		calc_strategy(int af, int ar, int bf, t_moves *min);
int			find_max(int *stack, int len);
int			find_min(int *stack, int len);


/*
**			parse
*/
int			data_validate(int argc, char **argv, int **a, int num_flags);
t_stack		*make_stack_obj(int *a, int alen);
int			check_flags(int argc, char **argv);
int			parse(int argc, char **argv, int **a, int num_flags);


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
int			ret_greater(int a, int b);
void		print_moves(t_moves *moves);

/*
**			new_lib
*/
void		ft_put_error(char *str);
void		ft_free_tab(char **tab);
int			ft_greater_than(int a, int b);
void 		ft_put_two_arr(int *a, int alen, int *b, int blen);

/*
**		op_s
*/
void		op_s(t_stack *stacks, char c);
void		op_p(t_stack *stacks, char c);
void		op_r(t_stack *stacks, char c);
void		op_q(t_stack *stacks, char c);


#endif