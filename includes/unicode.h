/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 15:54:31 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 13:48:29 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UNICODE_H
# define UNICODE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

/*
** Location of the stored solution map.
*/
# define MAPNAME	"/tmp/solution.tmp"

/*
** Sets unicode output in 256 colors sequence.
*/
# define _0		ft_putstr("\e[0m")

/*
** Square unicode.
*/
# define _SQU	"\u1F3B"
# define _VOID	ft_putstr("\e[38;5;237m\u1F3B")
# define _A		ft_putstr("\e[38;5;9m")
# define _B		ft_putstr("\e[38;5;226m")
# define _C		ft_putstr("\e[38;5;88m")
# define _D		ft_putstr("\e[38;5;82m")
# define _E		ft_putstr("\e[38;5;17m")
# define _F		ft_putstr("\e[38;5;221m")
# define _G		ft_putstr("\e[38;5;162m")
# define _H		ft_putstr("\e[38;5;148m")
# define _I		ft_putstr("\e[38;5;2m")
# define _J		ft_putstr("\e[38;5;106m")
# define _K		ft_putstr("\e[38;5;208m")
# define _L		ft_putstr("\e[38;5;46m")
# define _M		ft_putstr("\e[38;5;51m")
# define _N		ft_putstr("\e[38;5;123m")
# define _O		ft_putstr("\e[38;5;81m")
# define _P		ft_putstr("\e[38;5;74m")
# define _Q		ft_putstr("\e[38;5;32m")
# define _R		ft_putstr("\e[38;5;25m")
# define _S		ft_putstr("\e[38;5;21m")
# define _T		ft_putstr("\e[38;5;18m")
# define _U		ft_putstr("\e[38;5;202m")
# define _V		ft_putstr("\e[38;5;103m")
# define _W		ft_putstr("\e[38;5;96m")
# define _X		ft_putstr("\e[38;5;169m")
# define _Y		ft_putstr("\e[38;5;1m")
# define _Z		ft_putstr("\e[38;5;89m")

int	ft_put_uni(const char *path, char **tab);
int	ft_put_palette(void);
#endif
