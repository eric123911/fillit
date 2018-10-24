/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 02:20:16 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:12:04 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_ptr;
	size_t	i;

	if (!s || !f)
		return (0);
	i = -1;
	if (NULL == (s_ptr = ft_strdup((const char *)s)))
		return (NULL);
	while (s[++i])
		s_ptr[i] = f((unsigned int)i, s_ptr[i]);
	return (s_ptr);
}
