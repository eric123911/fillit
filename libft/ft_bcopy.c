/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bcopy.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 17:42:45 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 17:55:46 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_bcopy(const void *src, void *dst, size_t len)
{
	unsigned int	i;

	if (!src || !dst)
		return ;
	i = 0;
	while (len > 0)
	{
		*((u_int8_t *)dst + i) = *((u_int8_t *)src + i);
		i++;
		len--;
	}
}
