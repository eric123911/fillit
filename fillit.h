/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 11:50:42 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:45:52 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <fcntl.h>


# include <stdio.h>

typedef struct			p_list
{
	char				*str;
	struct p_list		*next;
	struct p_list		*prev;
}						f_list;

char    validate_file(const f_list *list);
char	**fillit(const f_list *list, size_t size, char c, char **result);
char	**ft_tab_malloc(size_t size);
#endif
