/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 03:27:31 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:47:14 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t			len;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (ft_isblank(s[i]) || s[i] == '\n')
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && (ft_isblank(s[len]) || s[len] == '\n'))
		len--;
	if (len < i)
		return (ft_strdup(""));
	return (ft_strsub(s, i, len - (size_t)i + 1));
}
