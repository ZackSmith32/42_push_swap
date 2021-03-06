/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_srt_ascend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:54:18 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/03 15:27:14 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ck_srt_ascend(int *a, int alen)
{
	int		i;

	i = 0;
	if (!a)
		return (0);
	while (i < (alen - 1))
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
