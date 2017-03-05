/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 23:20:16 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/28 17:48:54 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 32

typedef struct		s_gnl
{
	int				fd;
	char			*content;
	size_t			content_size;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
void				free_gnl(t_gnl **head, int fd);

#endif
