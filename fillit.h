/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 11:50:42 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:50:10 by eschnell    ###    #+. /#+    ###.fr     */
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

typedef struct			i_list
{
	int					index[8];
	struct i_list		*next;
	struct i_list		*prev;
}						index_list;

int						error(void);
char					validate_file(const f_list *list);
char					**fillit(const index_list *lst, size_t size, char c, char **res);
char					**ft_tab_malloc(size_t size);
void					get_index_of_tetriminos(const f_list *list, int (*index)[8]);
#endif
