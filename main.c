/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:18:47 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:50:57 by eschnell    ###    #+. /#+    ###.fr     */
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

f_list	*ft_read(char *av)
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

int		main(void)//int ac, char **av)
{
	f_list	*list;
	char	**tab;
	size_t	size;

	//printf("%zu\n", map_size(_____));

	size = 2;
	if (ac != 2)
		return (1); 	// <========== FAT USAGE A METTER ICI
	list = ft_read(av[1]);
	if (validate_file(list))
		return (error());
	tab = fillit(list, size, 'A', ft_tab_malloc(size));
	ft_put_tab(tab);
	return (0);
}
