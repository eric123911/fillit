/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_flist.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 18:35:27 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 18:36:01 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_flstdel(t_flist **alst, void (*del)(void*))
{
	t_flist		*tmp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		del((*alst)->str);
		free(*alst);
		*alst = tmp;
	}
	*alst = NULL;
}
