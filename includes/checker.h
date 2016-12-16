/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:59:49 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/15 18:16:56 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

/*
**		new_lib
*/
void		ft_put_error(char *str);
void		ft_putarr(int *a, int len);
int			ft_pusharr(int **a, int num, int len);
void		ft_pushtab(void *tab, void *ptr);

#endif