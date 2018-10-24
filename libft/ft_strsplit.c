/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 03:34:14 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 19:17:32 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countw(char *s, char c)
{
	int				i;
	int				j;
	unsigned int	nb;

	i = -1;
	nb = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			i += j;
			nb++;
		}
	}
	return (nb + 1);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**s_ptr;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (0);
	if (NULL == (s_ptr = ft_memalloc(sizeof(char *) * ft_countw((char *)s, c))))
		return (NULL);
	i = -1;
	j = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			s_ptr[++j] = ft_strsub(s, i, len);
			i += len;
			i--;
		}
	}
	s_ptr[++j] = 0;
	return (s_ptr);
}
