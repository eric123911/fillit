/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 17:53:48 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 17:19:08 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char    validate_file(const f_list *list)
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
            list = list->next;
        }
        printf("%zu\n", i);
        if ((i % 5 != 0) || (ft_strcmp(list->str, "\0") || !(p == 12 && d == 4)))
            return ('1');
        if (list->next)
            list = list->next;
    }
    return ('0');
}