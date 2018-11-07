/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:53:48 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 16:59:24 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_lastl(const f_list *list, int count)
{
	/* Valide le dernier \n si et seulement si pour `i` dans `validate_file`
	** l'expression		[(i + 1) % 5] == 0		est vraie.
	*/
	if (list->str && !ft_strcmp(list->str, "\0") && !(++count % 5))
		return (0);
	else
		return (1);
}

static char	validate_file_len(const f_list *list)
{
    size_t  i;
    size_t  p;
    size_t  d;

    i = 0;
    while (list->next)
    {
        p = 0;
        d = 0;
        while (list->next && ++i % 5)
		{
            p += ft_strccount(list->str, '.');
			d += ft_strccount(list->str, '#');
			if (ft_strlen(list->str) != 4)
				return (1);
            list = list->next;
        }
        if ((i % 5 && ft_strcmp(list->str, "\0")) || !(p == 12 && d == 4))
            return (1);
		if (list->next)
            list = list->next;
	}
	return(validate_lastl(list, i));
}

static char	find_neighbour(char *s1, char *s2, char *s3, size_t i)
{
	if (s2[i] == '#')
	{
		if (i > 0)
			if (s2[i - 1] == '#')
				return (0);
		if (i < 3)
			if (s2[i + 1] == '#')
				return (0);
		if (s1)
			if (s1[i] == '#')
				return (0);
		if (s3)
			if (s3[i] == '#')
				return (0);
		return (1);
	}
	return (0);
}

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
				if (find_neighbour(list->prev->str, list->str, list->next->str, i))
					return (1);
			}
			else if (list->prev)
			{
				if (find_neighbour(list->prev->str, list->str, NULL , i))
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

// fonction qui appelle les 2 fonctions permettant de savoir si le fichier transmis et resolvable 
char		validate_file(const f_list *list)
{
	//verifie la bonne taille du file et des lignes ainsi que le bon nombres de . et de #
	if (!list)
		return (1);
	else if (validate_file_len(list))
		return (1);
	else if (validate_patter(list))
		return (1);
	else
		return (0);
}
