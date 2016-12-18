/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 23:20:16 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/17 22:11:08 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_e_list
{
	int				fd;
	void			*content;
	size_t			content_size;
	struct s_e_list	*next;
}					t_a_list;

int					get_next_line(const int fd, char **line);
int					central(int fd, t_a_list *holder, char **line);
int					check_struct(t_a_list *holder, char **line);
int					read_buf(int fd, t_a_list *holder, char **line);
int					set_line(t_a_list *holder, char **line);

#endif
