/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:53:48 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 15:50:00 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			error(void)
{
	ft_putendl("error");
	return (0);
}

/*
** Fonction qui valide les caracteres et la taille
** des tetriminos donnes et valide la fin du fichier
*/

static char	validate_file_len(const f_list *list)
{
	size_t					i;
	size_t					p;
	size_t					d;

	i = 0;
	while (list->next)
	{
		p = 0;
		d = 0;
		while (list && ++i % 5)
		{
			p += ft_strccount(list->str, '.');
			d += ft_strccount(list->str, '#');
			if (ft_strlen(list->str) != 5)
				return (1);
			list = list->next;
		}
		if (i % 5 || !(p == 12 && d == 4))
			return (1);
		if (list->str[0] != '\n' && list->next)
			return (1);
		if (list->next)
			list = list->next;
	}
	return (list->prev->str[0] == '\n' ? 1 : 0);
}

/*
** Sous-fonction de `validate_patter`
** qui valide les dieses voisines.
*/

static char	find_neighbour(char *s1, char *s2, char *s3, size_t i)
{
	static size_t	n = 0;
	static size_t	count = 0;

	if (s2[i] == '#')
	{
		if (i > 0)
			if (s2[i - 1] == '#')
				n++;
		if (i < 3)
			if (s2[i + 1] == '#')
				n++;
		if (s1)
			if (s1[i] == '#')
				n++;
		if (s3)
			if (s3[i] == '#')
				n++;
		count++;
		if (count % 4 == 0 && !(n == 6 || n == 8))
			return (1);
		if (n >= 6 && count % 4 == 0)
			n = 0;
	}
	return (0);
}

/*
** Fontion qui valide les tetriminos.
*/

static char	validate_patter(const f_list *list)
{
	size_t	i;

	while (list->next)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->prev && list->next)
			{
				if (find_neighbour(list->prev->str,
									list->str, list->next->str, i))
					return (1);
			}
			else if (list->prev)
			{
				if (find_neighbour(list->prev->str, list->str, NULL, i))
					return (1);
			}
			else if (find_neighbour(NULL, list->str, list->next->str, i))
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

/*
** fonction qui appelle les 2 fonctions permettant
** de savoir si le fichier transmis et resolvable
*/

char		validate_file(const f_list *list)
{
	if (!list)
		return (1);
	else if (validate_file_len(list))
		return (1);
	else if (validate_patter(list))
		return (1);
	else
		return (0);
}
