/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/30 15:05:42 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:57:02 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*c_ptr;
	unsigned char		ind;
	int					i;

	i = ft_strlen((char *)s);
	ind = (unsigned char)c;
	c_ptr = (const unsigned char *)s;
	while (*c_ptr)
		c_ptr++;
	if (ind == '\0')
		return ((void *)c_ptr);
	while (i-- >= 0)
		if (*--c_ptr == ind)
			return ((void *)c_ptr);
	return (NULL);
}
