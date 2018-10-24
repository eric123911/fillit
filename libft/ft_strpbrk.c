/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strpbrk.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 18:36:34 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 18:46:09 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	unsigned int	i;

	i = ft_strcspn(s, charset);
	if (i == ft_strlen(s))
		return (NULL);
	return ((char *)s + i);
}
