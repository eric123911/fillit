/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_flist.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 18:35:27 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 09:48:12 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_flstdel(t_flist **alst, void (*del)(char**))
{
	t_flist		*tmp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		del(&(*alst)->str);
		free(*alst);
		*alst = tmp;
	}
}

void	ft_idxlstdel(t_idxlist **alst)
{
	t_idxlist		*tmp;

	if (alst)
		return ;
	while ((*alst)->next)
	{
		tmp = (*alst)->next;
		free(*alst);
		*alst = tmp;
	}
	free(*alst);
	*alst = NULL;
}

void	free_tab(char ***tab, int size)
{
	int i;

	i = -1;
	if (!*tab)
		return ;
	while (++i < size)
	{
		ft_strdel(&(*tab)[i]);
	}
	free(*tab);
}
