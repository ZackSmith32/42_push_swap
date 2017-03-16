/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:38:58 by zsmith            #+#    #+#             */
/*   Updated: 2017/03/08 09:27:41 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_struct(t_gnl *temp, char **line)
{
	int		i;
	int		str_len;
	char	*str;

	if (ft_strlen(temp->content) == 0)
		return (0);
	i = 0;
	while (temp->content[i] != '\n' && temp->content[i] != '\0')
		i++;
	free(*line);
	*line = (char *)ft_memalloc(i + 1);
	ft_memcpy(*line, temp->content, (size_t)i);
	if (temp->content[i] == 0)
	{
		ft_bzero(temp->content, i);
		free(temp->content);
		return (0);
	}
	str_len = ft_strlen(temp->content) - i;
	str = ft_memalloc(str_len);
	ft_memcpy(str, temp->content + (i + 1), (size_t)str_len);
	free(temp->content);
	temp->content = str;
	return (1);
}

static int		reading(int fd, char **line, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		j = 0;
		if (i == -1)
			return (-1);
		buff[i] = '\0';
		while (buff[j] != '\n' && buff[j] != '\0')
			j++;
		temp = ft_strccat(*line, buff, '\n');
		free(*line);
		(*line) = temp;
		if (j != BUFF_SIZE)
			break ;
	}
	return (i);
}

static int		read_buf(int fd, t_gnl *item, char **line)
{
	char	*buff;
	char	*hld;
	int		i;
	int		j;

	j = 0;
	buff = (char *)ft_memalloc(BUFF_SIZE + 1);
	i = reading(fd, line, buff);
	hld = ft_strchr(buff, '\n');
	if (hld)
	{
		item->content = ft_strdup(hld + 1);
	}
	free(buff);
	if (i == -1)
		return (-1);
	if (i != BUFF_SIZE)
		return (0);
	return (1);
}

static int		central(t_gnl *temp, char **line, t_gnl **head)
{
	t_gnl	*h;
	t_gnl	*g;
	int		ret;

	// printf("line = %s, leftovers = %s\n", *line, temp->content);
	if (check_struct(temp, line))
		return (1);
	// printf("after struct line = %s\n", *line);
	ret = read_buf(temp->fd, temp, line);
	// printf("ret = %d, line = %s, temp->content = %s\n", ret , *line, temp->content);
	if (ret)
		return (ret);
	if (ft_strlen(*line) != 0)
		return (1);
	free_gnl(head, temp->fd);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*temp;

	if (fd < 0 || line == 0)
		return (-1);
	*line = (char *)ft_memalloc(1);
	if (head == NULL)
	{
		head = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		head->fd = fd;
	}
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
		{
			temp->next = (t_gnl *)ft_memalloc(sizeof(t_gnl));
			temp = temp->next;
			temp->fd = fd;
			break ;
		}
		temp = temp->next;
	}
	return (central(temp, line, &head));
}
