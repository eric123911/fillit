/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:34:39 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 13:37:32 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	int		ft_getline(const int fd, char **tab)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	ret = 1;
	while (!ft_strchr(*tab, '\n') && ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			temp = ft_strjoin(*tab, buff);
			free(*tab);
			*tab = temp;
		}
	}
	return (ret);
}

static	void	ft_newline(char *tab, char **line)
{
	int		i;
	char	*temp;
	int		newl;

	i = 0;
	newl = 0;
	if (!tab[0])
	{
		*line = NULL;
		return ;
	}
	while (tab[i] && tab[i] != '\n')
		i++;
	if (tab[i] == '\n')
		newl = 1;
	*line = ft_strsub(tab, 0, i);
	temp = ft_strsub(tab, i + newl, ft_strlen(tab));
	tab = ft_strcpy(tab, temp);
	free(temp);
}

int				get_next_line(const int fd, char **line)
{
	static char *tab[0];
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!tab[fd])
		tab[fd] = ft_strnew(1);
	ret = ft_getline(fd, &tab[fd]);
	ft_newline(tab[fd], line);
	if (*line)
		return (1);
	else
		return (ret);
}
