/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 19:58:18 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 15:48:22 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef	struct		s_gnline
{
	int				fd;
	char			*tmp;
	struct s_gnline	*next;
}					t_gnline;

int					get_next_line(const int fd, char **line);

#endif
