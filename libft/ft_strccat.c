/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strccat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 00:32:44 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 01:39:38 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

char	*ft_strccat(char *dest, const char *src, int c)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = -1;
	while (dest[i])
		i++;
	while (src[++j] && src[j] != c)
		dest[i++] = src[j];
	dest[i] = '\0';
	return (dest);
}
