/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:53:48 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 17:29:01 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_bool			error(t_flist *list)
{
	ft_flstdel(&list, &ft_strdel);
	ft_putendl("error");
	return (true);
}

/*
** Fonction qui valide les caracteres et la taille
** des tetriminos donnes et valide la fin du fichier
*/

static t_bool	validate_file_len(const t_flist *list)
{
	size_t	i;
	size_t	p;
	size_t	d;

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
				return (false);
			list = list->next;
		}
		if (i % 5 || !(p == 12 && d == 4))
			return (false);
		if (list->next)
			if (list->str[0] != '\n')
				return (false);
		list->next ? list = list->next : 0;
	}
	return (list->prev->str[0] == '\n' ? false : true);
}

/*
** Sous-fonction de `validate_patter`
** qui valide les dieses voisines.
*/

static t_bool	find_neighbour(char *s1, char *s2, char *s3, size_t i)
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
		if (!(count % 4) && !(n == 6 || n == 8))
			return (false);
		if (n >= 6 && !(count % 4))
			n = 0;
	}
	return (true);
}

/*
** Fontion qui valide les tetriminos.
*/

static t_bool	validate_patter(const t_flist *list)
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
					return (false);
			}
			else if (list->prev)
			{
				if (find_neighbour(list->prev->str, list->str, NULL, i))
					return (false);
			}
			else if (find_neighbour(NULL, list->str, list->next->str, i))
				return (false);
			i++;
		}
		list = list->next;
	}
	return (true);
}

/*
** fonction qui appelle les 2 fonctions permettant
** de savoir si le fichier transmis et resolvable
*/

t_bool			validate_file(const t_flist *list)
{
	if (!list)
		return (false);
	else if (validate_file_len(list))
		return (false);
	else if (validate_patter(list))
		return (false);
	else
		return (true);
}
