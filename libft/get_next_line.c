/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoze <gdoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:38:49 by gdoze             #+#    #+#             */
/*   Updated: 2019/12/23 13:38:33 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 10000

t_fd			*newlist(const int fd)
{
	t_fd		*new;

	if (!(new = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->remain = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char			*check_remain(char **new_string, char *remain)
{
	char		*str;

	if ((*new_string = ft_strchr(remain, '\n')) != NULL)
	{
		str = ft_strsub(remain, 0, *new_string - remain);
		ft_strcpy(remain, ++(*new_string));
	}
	else
	{
		str = ft_strnew(ft_strlen(remain) + 1);
		ft_strcat(str, remain);
		ft_strclr(remain);
	}
	return (str);
}

int				get_line(const int fd, char **line, char *remain)
{
	char		buf[BUFF_SIZE + 1];
	char		*new_string;
	char		*tmp;
	int			what_read;

	new_string = NULL;
	what_read = 1;
	*line = check_remain(&new_string, remain);
	while (new_string == 0 && ((what_read = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[what_read] = '\0';
		if ((new_string = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(remain, ++new_string);
			ft_strclr(--new_string);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || what_read < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(remain) || what_read) ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd	*list;
	t_fd		*tmp;
	int			ret;

	if (fd < 0 || line == 0 || BUFF_SIZE == 10000000)
		return (-1);
	if (!list)
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
		{
			if (((tmp->next = newlist(fd)) == NULL))
				return (-1);
		}
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->remain);
	return (ret);
}
