/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 20:52:05 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:56:47 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*tmp;

	if (!len)
		return (dest);
	tmp = dest;
	while (len--)
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = 0;
	return (tmp);
}
