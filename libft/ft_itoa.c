/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:30:38 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 18:36:54 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	ft_countn(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_itoa2(char *str, int neg, int i, int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (neg == 1)
	{
		n *= -1;
		str[0] = '-';
	}
	while (--i >= neg)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		ind;
	int		neg;
	char	*str;

	neg = 0;
	ind = ft_countn(n);
	if (n < 0)
	{
		neg++;
		ind++;
	}
	if (NULL == (str = malloc(sizeof(char) * (ind + 1))))
		return (NULL);
	str[ind] = '\0';
	return (ft_itoa2(str, neg, ind, n));
}
