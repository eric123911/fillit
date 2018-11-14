/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_flist			                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 18:02:12 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 18:04:18 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void	ft_lstdel(t_flist **alst, void (*del)(void*))
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
