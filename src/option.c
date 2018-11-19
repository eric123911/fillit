/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   option.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:28:16 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 12:52:17 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "unicode.h"

int	parse_opt2(t_fopt store, int i, char **args)
{
	if (i == 2)
		ft_put_tab(store.tab, 1);
	else if (!ft_strcmp(args[1], "-u") || !ft_strcmp(args[1], "--unicode"))
		ft_put_uni(MAPNAME, store.tab);
	else
	{
		ft_putstr("unknown option: ");
		ft_putendl(args[1]);
		return (error(store.list));
	}
	free_tab(&store.tab, store.size);
	return (1);
}

int	parse_opt(int i, char **args)
{
	t_fopt		store;
	t_idxlist	*lst_idx;
	size_t		line;

	store.tab = NULL;
	line = 1;
	if (!ft_strcmp(args[1], "-p") || !ft_strcmp(args[1], "--palette"))
	{
		ft_put_palette();
		return (1);
	}
	(i == 2) ? store.list = ft_read(args[1], &line) : 0;
	(i == 3) ? store.list = ft_read(args[2], &line) : 0;
	if (line == 1 || line > 130 || validate_file(store.list))
		return (error(store.list));
	lst_idx = ft_get_index(store.list);
	ft_flstdel(&store.list, &ft_strdel);
	store.size = map_size((line / 5) * 4);
	store.tab = fillit(lst_idx, &store.size, 'A', ft_tab_malloc(store.size));
	ft_idxlstdel(&lst_idx);
	return (parse_opt2(store, i, args));
}
