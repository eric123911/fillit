/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/22 18:03:40 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 15:00:41 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	t;
	unsigned char	*sp;

	if (n == 0)
		return (NULL);
	t = (unsigned char)c;
	sp = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*sp == t)
			return ((void *)sp);
		sp++;
	}
	return (NULL);
}
