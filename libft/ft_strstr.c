/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:41:56 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/14 13:16:16 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle &&
			!ft_memcmp(haystack, needle, ft_strlen((char *)needle)))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
