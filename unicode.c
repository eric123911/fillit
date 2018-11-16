/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 14:17:57 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 20:22:04 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "unicode.h"

static void	print_uni2(const char *s, size_t i)
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
	!ft_isalpha(*(s + i)) && *(s + i) != '\n' ? _VOID : 0;
}

static void	print_uni(const char *s)
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

static int		ft_create_tmp(const char *path, char **tab)
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

int				ft_put_uni(const char *path, char **tab)
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
	return (1);
}


int		ft_put_palette(void)
{
	ft_putendl("The currently in-use palette :");
	ft_putendl("");
	ft_putstr("A: "), print_uni("AAA"), _0;
	ft_putstr("B: "), print_uni("BBB"), _0;
	ft_putstr("C: "), print_uni("CCC"), _0;
	ft_putstr("D: "), print_uni("DDD"), _0;
	ft_putstr("E: "), print_uni("EEE"), _0;
	ft_putstr("F: "), print_uni("FFF"), _0;
	ft_putstr("G: "), print_uni("GGG"), _0;
	ft_putstr("H: "), print_uni("HHH"), _0;
	ft_putstr("I: "), print_uni("III"), _0;
	ft_putstr("J: "), print_uni("JJJ"), _0;
	ft_putstr("K: "), print_uni("KKK"), _0;
	ft_putstr("L: "), print_uni("LLL"), _0;
	ft_putstr("M: "), print_uni("MMM"), _0;
	ft_putstr("N: "), print_uni("NNN"), _0;
	ft_putstr("O: "), print_uni("OOO"), _0;
	ft_putstr("P: "), print_uni("PPP"), _0;
	ft_putstr("Q: "), print_uni("QQQ"), _0;
	ft_putstr("R: "), print_uni("RRR"), _0;
	ft_putstr("S: "), print_uni("SSS"), _0;
	ft_putstr("T: "), print_uni("TTT"), _0;
	ft_putstr("U: "), print_uni("UUU"), _0;
	ft_putstr("V: "), print_uni("VVV"), _0;
	ft_putstr("W: "), print_uni("WWW"), _0;
	ft_putstr("X: "), print_uni("XXX"), _0;
	ft_putstr("Y: "), print_uni("YYY"), _0;
	ft_putstr("Z: "), print_uni("ZZZ"), _0;
	return (0);
}
