/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 13:47:28 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 16:01:56 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "unicode.h"

static void			print_uni2(const char *s, size_t i)
{
	*(s + i) == 'N' ? _N : 0;
	*(s + i) == 'O' ? _O : 0;
	*(s + i) == 'P' ? _P : 0;
	*(s + i) == 'Q' ? _Q : 0;
	*(s + i) == 'R' ? _R : 0;
	*(s + i) == 'S' ? _S : 0;
	*(s + i) == 'T' ? _T : 0;
	*(s + i) == 'U' ? _U : 0;
	*(s + i) == 'V' ? _V : 0;
	*(s + i) == 'W' ? _W : 0;
	*(s + i) == 'X' ? _X : 0;
	*(s + i) == 'Y' ? _Y : 0;
	*(s + i) == 'Z' ? _Z : 0;
	*(s + i) == '.' ? _VOID : 0;
	*(s + i) != '\n' && *(s + i) != '.' ? ft_putstr(_SQU) : 0;
}

static void			print_uni(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		*(s + i) == 'A' ? _A : 0;
		*(s + i) == 'B' ? _B : 0;
		*(s + i) == 'C' ? _C : 0;
		*(s + i) == 'D' ? _D : 0;
		*(s + i) == 'E' ? _E : 0;
		*(s + i) == 'F' ? _F : 0;
		*(s + i) == 'G' ? _G : 0;
		*(s + i) == 'H' ? _H : 0;
		*(s + i) == 'I' ? _I : 0;
		*(s + i) == 'J' ? _J : 0;
		*(s + i) == 'K' ? _K : 0;
		*(s + i) == 'L' ? _L : 0;
		*(s + i) == 'M' ? _M : 0;
		print_uni2(s, i);
		i++;
	}
	ft_putendl("");
}

static int			ft_create_tmp(const char *path, char **tab)
{
	int fd;

	if ((fd = open(path, O_RDWR | O_CREAT
				| O_TRUNC, 00644)) == -1)
		return (error(NULL));
	else
		ft_put_tab(tab, fd);
	close(fd);
	return (1);
}

int					ft_put_uni(const char *path, char **tab)
{
	char	*line;
	int		fd;

	if (ft_create_tmp(path, tab))
	{
		fd = open(path, O_RDWR);
		while (get_next_line(fd, &line))
			print_uni(line);
		close(fd);
	}
	_0;
	return (1);
}

int					ft_put_palette(void)
{
	char	c;
	char	*str;

	c = 'A';
	ft_putendl("The currently in-use palette :");
	ft_putendl("");
	while (c <= 'Z')
	{
		ft_putchar(c);
		ft_putstr(": ");
		str = ft_strnew(3);
		str[0] = c;
		str[1] = c;
		str[2] = c;
		print_uni(str);
		_0;
		c++;
	}
	free(str);
	return (0);
}
