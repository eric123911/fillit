/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 00:23:13 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 02:44:28 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t s)
{
	void	*s_ptr;

	if (NULL == (s_ptr = (void *)malloc(sizeof(void *) * s)))
		return (NULL);
	ft_bzero(s_ptr, s);
	return (s_ptr);
}
