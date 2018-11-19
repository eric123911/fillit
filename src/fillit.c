/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 16:53:07 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 18:17:39 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** return == 1		si jamais un tetriminos est deja present
** return == 3 		arrive au bout de l'axe des X
** return == 2		idem pour Y
*/

static char		can_put_down(char **result, const int idx[10],
		const size_t offset[2])
{
	ssize_t id;

	id = 0;
	while (id <= 6)
	{
		if (result[offset[0] + idx[id]][offset[1] + idx[id + 1]])
			return (1);
		id += 2;
	}
	return (0);
}

static char		**put_down(const int idx[10], char **res, size_t ofs[2], char c)
{
	res[ofs[0] + idx[0]][ofs[1] + idx[1]] = c;
	res[ofs[0] + idx[2]][ofs[1] + idx[3]] = c;
	res[ofs[0] + idx[4]][ofs[1] + idx[5]] = c;
	res[ofs[0] + idx[6]][ofs[1] + idx[7]] = c;
	return (res);
}

/*
** res == 1		si jamais un tetriminos est deja present
** res == 3 	arrive au bout de l'axe des X
** res == 2		idem pour Y
*/

static t_bool	algo(int idx[10], char **result, size_t size, size_t (*ofs)[2])
{
	size_t	res;

	res = 1;
	while (res)
	{
		if ((*ofs)[0] + idx[8] >= size)
			return (false);
		else if ((*ofs)[1] + idx[9] >= size)
		{
			(*ofs)[1] = 0;
			(*ofs)[0]++;
		}
		else if ((res = can_put_down(result, idx, *ofs)))
			(*ofs)[1]++;
	}
	return (true);
}

/*
** offset[0] -> y
** offset[1] -> x
*/

char			**fillit(t_idxlist *list, size_t *size, char c, char **result)
{
	size_t	offset[2];
	char	**temp;

	offset[0] = 0;
	offset[1] = 0;
	if (!list || !result)
		return (replace0(result, *size));
	while (!algo(list->index, result, *size, &offset))
	{
		result = put_down(list->index, result, offset, c);
		if ((temp = fillit(list->next, size, c + 1, result)))
			return (temp);
		result = put_down(list->index, result, offset, '\0');
		offset[1]++;
	}
	if (list->prev == NULL && offset[0] + list->index[8] >= *size)
	{
		free_tab(&result, (*size)++);
		return (fillit(list, size, 'A', ft_tab_malloc(*size)));
	}
	return (NULL);
}
