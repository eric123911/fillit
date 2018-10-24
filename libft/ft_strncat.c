/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 16:46:56 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:56:13 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, char *src, size_t n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (j < (int)n && src[++j])
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
