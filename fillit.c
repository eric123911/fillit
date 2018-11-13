/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 16:53:07 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 16:37:32 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

// la variable size correspond à la taille du carré actuel

char **		replace0(char **tab, int size)
{
	int i;
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

void	get_index_of_tetriminos(const f_list *list, int (*index)[8])
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

int		can_put_down(char **result ,const int index[8],const size_t size,const size_t offset[2])
{
	size_t four;
	size_t id;

	four = 4;
	id = 0;
	while (four--)
	{
		if (offset[0] + index[id] >= size) // au bout de l'axe Y
			return (2);
		else if (offset[1] + index[id + 1] >= size) // au bout de l'axe X
			return (3);
		else if (result[offset[0] + index[id]][offset[1] + index[id + 1]])
			return (1); // un tetriminos est déjà présent
		id += 2;
	}
	return (0);
}

char **put_down(const int index[8], char **result, size_t offset[2], char c)
{
	size_t four;
	size_t id;

	id = 0;
	four = 4;
	while (four--)
	{
		result[offset[0] + index[id]][offset[1] + index[id + 1]] = c;
		id += 2;
	}
	return (result);
}

char **take_up(const int index[8], char **result, size_t offset[2])
{
	size_t four;
	size_t id;

	id = 0;
	four = 4;
	while (four--)
	{
		result[offset[0] + index[id]][offset[1] + index[id + 1]] = '\0';
		id += 2;
	}
	return (result);
}

size_t	algorithme(const int index[8], char **result, size_t size, size_t (*offset)[2])
{
	size_t	res;

	while ((res = can_put_down(result, index,  size, *offset)))
	{
		if (res == 1) // si jamais un tetriminos est déjà present
			(*offset)[1]++;
		if (res == 3) // X
		{
			(*offset)[1] = 0;
			(*offset)[0]++;
		}
		if (res == 2)
			return (2);
	}

	return (0);
}

char	**fillit(const index_list *list, size_t size, char c, char **result)
{
	size_t	offset[2];
	int		res;
	char	**temp;

	res = 0;
	temp = NULL;
	offset[0] = 0; // y
	offset[1] = 0; // x
	if (!list)
		return (replace0(result, size));
	while (temp == NULL &&  offset[0] < size)
	{
		res = algorithme(list->index, result, size, &offset);
		if (res == 0)
		{
			result = put_down(list->index, result, offset, c);
			if ((temp = fillit(list->next, size, c + 1, result)))
				return (temp);
			result = take_up(list->index, result, offset);
		}
		offset[1]++;
	}
	if (list->prev == NULL && offset[0] >= size)
		return (fillit(list, size + 1, 'A', ft_tab_malloc(size + 1)));
	return (NULL);
}
