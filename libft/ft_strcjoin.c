/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcjoin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 01:44:11 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 17:12:44 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s1, char const *s2, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	i += ft_strnlen(s2, c);
	if (!(str = ft_strnew(i + 1)))
		return (0);
	str = ft_strcpy(str, s1);
	str = ft_strccat(str, s2, c);
	return (str);
}
