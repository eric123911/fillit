/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:53:48 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 15:32:36 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int	validate_lastl(const f_list *list, int count)
{
	while (list->next)
		list = list->next;

	/* Valide le dernier \n si et seulement si pour `i` dans `validate_file`
	** l'expression		[(i + 1) % 5] == 0		est vraie.
	*/
	if (list->str && !ft_strcmp(list->str, "\0") && !(++count % 5))
		return (1);
	else
		return (0);
}

char    validate_file(const f_list *list)
{
    size_t  i;
    size_t  p;
    size_t  d;
	f_list	*head;
//	f_list	*last;

    i = 0;
	head = (f_list *)list;
    while (list->next)
    {
        p = 0;
        d = 0;
        while (list->next && ++i % 5)
        {
            p += ft_strccount(list->str, '.');
            d += ft_strccount(list->str, '#');
            list = list->next;
        }
		// Printf pour debug
		printf("%zu\n", i);
        if ((i % 5 && ft_strcmp(list->str, "\0")) || !(p == 12 && d == 4))
            return ('1');
        if (list->next)
            list = list->next;
    }
	if (validate_lastl(head, i))
		return ('0');
	else
		return ('1');
}
