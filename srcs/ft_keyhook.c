/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:54:20 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/22 10:58:00 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_keyhook(char key)
{
	int		bytes;
	char	*buff;

	buff = ft_memalloc(BUFF_SIZE);
	while ((bytes = read(0, buff, 1)))
	{
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (bytes);
}
