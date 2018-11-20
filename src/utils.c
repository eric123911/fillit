/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 17:15:19 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 15:38:44 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		corr_index_xy(int (*index)[10], char z)
{
	if (z == 'x')
	{
		(*index)[1]++;
		(*index)[3]++;
		(*index)[5]++;
		(*index)[7]++;
	}
	if (z == 'y')
	{
		(*index)[0]++;
		(*index)[2]++;
		(*index)[4]++;
		(*index)[6]++;
	}
}

void		corr_index(int (*index)[10])
{
	size_t i;

	i = 0;
	while (i < 8)
	{
		if ((*index)[i] < 0)
		{
			if (i % 2)
				corr_index_xy(index, 'x');
			else
				corr_index_xy(index, 'y');
			i = -1;
		}
		i++;
	}
}

void		get_xmax_ymax(int (*index)[10])
{
	int i;

	i = 0;
	(*index)[8] = 0;
	(*index)[9] = 0;
	while (i < 8)
	{
		if ((*index)[i] > (*index)[8])
			(*index)[8] = (*index)[i];

		i+= 2;
	}
	i = 1;
	while (i < 9)
	{
		if ((*index)[i] > (*index)[9])
			(*index)[9] = (*index)[i];

		i+= 2;
	}
}

void		get_index_of_tetriminos(const t_flist *list, int (*index)[10])
{
	size_t	four;
	size_t	count;
	int		i;
	int		j;

	(*index)[0] = 0;
	(*index)[1] = 0;
	four = 4;
	j = 0;
	count = 0;
	while (four--)
	{
		i = -1;
		while (list->str[++i])
			if (list->str[i] == '#')
			{
				count += 2;
				(*index)[count - 2] = j - (*index)[0];
				(*index)[count - 1] = i - (*index)[1];
			}
		j++;
		list = list->next;
	}
	(*index)[0] = 0;
	(*index)[1] = 0;
}

t_idxlist	*ft_get_index(t_flist *list)
{
	t_idxlist	*lst_index;
	t_idxlist	*begin;

	if (!(lst_index = (t_idxlist*)malloc(sizeof(t_idxlist))))
		return (NULL);
	lst_index->prev = NULL;
	lst_index->next = NULL;
	begin = lst_index;
	while (list)
	{
		get_index_of_tetriminos(list, &lst_index->index);
		corr_index(&lst_index->index);
		get_xmax_ymax(&lst_index->index);
		if (!(lst_index->next = (t_idxlist*)malloc(sizeof(t_idxlist))))
			return (NULL);
		lst_index->next->prev = lst_index;
		lst_index = lst_index->next;
		list = list->next->next->next->next->next;
	}
	lst_index->prev->next = NULL;
	free(lst_index);
	return (begin);
}
