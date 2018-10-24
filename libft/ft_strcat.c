/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/28 01:15:49 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 03:16:46 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char		*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (src[++j])
		dest[i + j] = src[j];
	dest[i + j] = src[j];
	return (dest);
}
