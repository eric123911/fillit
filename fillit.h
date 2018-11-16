/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 11:50:42 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 16:30:16 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <fcntl.h>

typedef struct			s_flist
{
	char				*str;
	struct s_flist		*next;
	struct s_flist		*prev;
}						t_flist;

typedef struct			s_idxlist
{
	int					index[8];
	struct s_idxlist	*next;
	struct s_idxlist	*prev;
}						t_idxlist;

int						error(t_flist *list);
char					validate_file(const t_flist *list);
char					**fillit(t_idxlist *l, size_t *s, char c, char **r);
char					**ft_tab_malloc(size_t size);
char					**replace0(char **tab, int size);
void					corr_index_xy(int (*index)[8], char z);
void					corr_index(int (*index)[8]);
void					get_index_of_tetriminos(const t_flist *l, int (*i)[8]);
void					ft_flstdel(t_flist **alst, void (*del)(char**));
t_idxlist				*ft_get_index(t_flist *list);
void					ft_idxlstdel(t_idxlist **alst);
void					ft_put_tab(char **tab);
void					free_tab(char ***tab, int size);
#endif
