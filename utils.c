/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 17:15:19 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 17:25:31 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**replace0(char **tab, int size)
{
	int	i;
	int j;

	i = -1;
	if (!tab)
		return (NULL);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tab[i][j] == '\0')
				tab[i][j] = '.';
		}
	}
	return (tab);
}

void		corr_index_xy(int (*index)[8], char z)
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

void		corr_index(int (*index)[8])
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

void		get_index_of_tetriminos(const t_flist *list, int (*index)[8])
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
