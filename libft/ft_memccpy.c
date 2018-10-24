/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/22 17:41:43 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 17:17:07 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	t;
	unsigned char	*d;
	const char		*s;

	if (n == 0)
		return (NULL);
	t = (unsigned char)c;
	d = dst;
	s = src;
	while (n-- > 0)
	{
		*d = (unsigned char)*s;
		if (*d++ == t)
			return (d);
		s++;
	}
	return (NULL);
}
