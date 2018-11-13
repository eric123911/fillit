/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 13:18:47 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 14:23:21 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		error(void)
{
	ft_putendl("error");
	return (0);
}

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

int		main(int ac, char **av)
{
	f_list	*list;
	char	**tab;
	size_t	size;

	size = 4;
	if (ac != 2)
		return (1);
	list = ft_read(av[1]);
	if (validate_file(list))
		return (error());
	tab = fillit(list, size, 'A', ft_tab_malloc(size));
	ft_put_tab(tab);
	return (0);
}
