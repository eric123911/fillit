/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:18:47 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 16:13:50 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_put_tab(char **tab)
{
	int i;

	i = -1;
	if (!tab)
	{
		error();
		return ;
	}
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}
}

f_list	*ft_read(char *av, size_t *line)
{
	int		f;
	f_list	*list;
	f_list	*begin;

	f = open(av, O_RDONLY);
	list = malloc(sizeof(f_list));
	list->prev = NULL;
	begin = list;
	while (get_next_line(f, &list->str) > 0)
	{
		(*line)++;
		list->next = malloc(sizeof(f_list));
		list->next->prev = list;
		list = list->next;
	}
	list->next = NULL;
	return (begin);
}


char	**ft_tab_malloc(size_t size)
{
	size_t i;
	char **tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if(!(tab[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

size_t	map_size(short d)
{
	size_t	res;

	res = ft_sqrt(d);
	return ((res * res == (size_t)d) ? res : res + 1);
}

index_list	*ft_get_index(f_list *list)
{
	index_list	*lst_index;
	index_list	*begin;

	lst_index = malloc(sizeof(index_list));
	lst_index->prev = NULL;
	begin = lst_index;

	while (list)
	{
		get_index_of_tetriminos(list, &lst_index->index);
		lst_index->next = malloc(sizeof(index_list));
		lst_index->next->prev = lst_index;
		lst_index = lst_index->next;

		list = list->next->next->next->next->next;
	}
	lst_index->prev->next = NULL;
	return (begin);
}

int		main(int ac, char **av)
{
	f_list		*list;
	index_list	*lst_index;
	char		**tab;
	size_t		line;
	size_t		size;

	line = 1;
	if (ac != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(av[0]);
		ft_putendl(" file_name");
		return (1);
	}
	list = ft_read(av[1], &line);
	lst_index = ft_get_index(list);
	if (validate_file(list))
		return (error());
	size = map_size((line / 5) * 4);
	tab = fillit(lst_index, size, 'A', ft_tab_malloc(size));
	ft_put_tab(tab);
	return (0);
}
