/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 14:55:44 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/14 14:55:44 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	z;

	z = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	j = 0;
	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	while (dst[i])
		i++;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (z);
}
