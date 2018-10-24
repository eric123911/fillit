/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 02:39:51 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 03:22:58 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_ptr;

	if (s)
	{
		if (NULL == (s_ptr = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(s_ptr, s + start, len);
		s_ptr[len] = '\0';
		return (s_ptr);
	}
	return (NULL);
}
