/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:35:28 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/15 19:02:37 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			free_gnl(t_gnl **head, int fd)
{
	t_gnl	*h;
	t_gnl	*g;

	h = *head;
	if (h->fd == fd)
	{
		*head = h->next;
		free(h);
		free(h->content);
	}
	else
		while (h->next != 0)
		{
			g = h->next;
			if (g->fd == fd)
			{
				h->next = g->next;
				free(g->content);
				free(g);
				break ;
			}
			h = h->next;
		}
}
