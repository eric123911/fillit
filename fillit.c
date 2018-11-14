/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 16:53:07 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 18:01:04 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** return == 1		si jamais un tetriminos est deja present
** return == 3 		arrive au bout de l'axe des X
** return == 2		idem pour Y
*/

int			can_put_down(char **result, const int index[8], const size_t size,
						const size_t offset[2])
{
	size_t four;
	size_t id;

	four = 4;
	id = 0;
	while (four--)
	{
		if (offset[0] + index[id] >= size)
			return (2);
		else if (offset[1] + index[id + 1] >= size)
			return (3);
		else if (result[offset[0] + index[id]][offset[1] + index[id + 1]])
			return (1);
		id += 2;
	}
	return (0);
}

char		**put_down(const int index[8], char **res, size_t offset[2], char c)
{
	size_t four;
	size_t id;

	id = 0;
	four = 4;
	while (four--)
	{
		res[offset[0] + index[id]][offset[1] + index[id + 1]] = c;
		id += 2;
	}
	return (res);
}

/*
** res == 1		si jamais un tetriminos est deja present
** res == 3 	arrive au bout de l'axe des X
** res == 2		idem pour Y
*/

size_t		algo(int index[8], char **result, size_t size, size_t (*offset)[2])
{
	size_t	res;

	while ((res = can_put_down(result, index, size, *offset)))
	{
		if (res == 1)
			(*offset)[1]++;
		if (res == 3)
		{
			(*offset)[1] = 0;
			(*offset)[0]++;
		}
		if (res == 2)
			return (2);
	}
	return (0);
}

/*
** offset[0] -> y
** offset[1] -> x
*/

char		**fillit(t_idxlist *list, size_t size, char c, char **result)
{
	size_t	offset[2];
	int		res;
	char	**temp;

	res = 0;
	temp = NULL;
	offset[0] = 0;
	offset[1] = 0;
	if (!list)
		return (replace0(result, size));
	while (temp == NULL && offset[0] < size)
	{
		res = algo(list->index, result, size, &offset);
		if (res == 0)
		{
			result = put_down(list->index, result, offset, c);
			if ((temp = fillit(list->next, size, c + 1, result)))
				return (temp);
			result = put_down(list->index, result, offset, '\0');
		}
		offset[1]++;
	}
	if (list->prev == NULL && offset[0] >= size)
		return (fillit(list, size + 1, 'A', ft_tab_malloc(size + 1)));
	return (NULL);
}
