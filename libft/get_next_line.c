/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 14:00:43 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 17:52:54 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_buff(t_gnline *list, char *buf, char **line)
{
	char				*tmp;
	unsigned long long	i;

	tmp = ft_strdup(*line);
	ft_strdel(line);
	i = (unsigned long long)ft_strnlen(buf, '\n');
	if (ft_strrchr(buf, '\n'))
	{
		*line = ft_strcjoin(tmp, buf, '\n');
		list->tmp = ft_strsub(buf, i + 1, ft_strlen(buf) - 1);
		ft_strdel(&buf);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strjoin(tmp, buf);
	ft_strclr(buf);
	ft_strdel(&tmp);
	return (0);
}

static t_gnline	*ft_start_list(t_gnline *list, const int fd)
{
	t_gnline	*st1;
	t_gnline	*st2;

	st1 = list;
	st2 = NULL;
	while (list && list->fd != fd)
	{
		st2 = list;
		list = list->next;
	}
	if (!list)
	{
		if (!(list = ft_memalloc(sizeof(t_gnline))))
			return (NULL);
		list->fd = fd;
	}
	if (st2)
		st2->next = list->next;
	if (list != st1)
		list->next = st1;
	return (list);
}

static int		ft_gnl_end(t_gnline *list, char *buf, char **line)
{
	ft_strdel(&buf);
	if (**line)
		return (1);
	list->fd = 0;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnline	*list = NULL;
	char			*buf;
	long			i;

	i = 0;
	if (!line || !(buf = ft_strnew(BUFF_SIZE)) ||
		read(fd, 0, 0) == -1 || fd < 0 || !(*line = ft_strnew(0)) ||
		BUFF_SIZE < 1 || !(list = ft_start_list(list, fd)))
		return (-1);
	if (list->tmp && ft_check_buff(list, list->tmp, line))
		return (1);
	ft_strdel(&list->tmp);
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		if (ft_check_buff(list, buf, line))
			return (1);
		if (i < BUFF_SIZE)
			return (1);
	}
	if (ft_gnl_end(list, buf, line))
		return (1);
	return (0);
}
