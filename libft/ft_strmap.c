/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 02:00:35 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:11:17 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_ptr;
	size_t	i;

	if (!s || !f)
		return (0);
	i = -1;
	if (NULL == (s_ptr = ft_strdup((const char *)s)))
		return (NULL);
	while (s[++i])
		s_ptr[i] = f(s_ptr[i]);
	return (s_ptr);
}
