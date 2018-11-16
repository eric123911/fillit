/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unicode.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 15:54:31 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:21:59 by eschnell    ###    #+. /#+    ###.fr     */
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
# define MAPNAME	".solution.tmp"

/*
** Sets unicode output in 256 colors sequence.
**
** NB :
** To check colors available on terminal,
** run the following command in a shell
** $> curl -o 256-colors.sh  https://misc.flogisoft.com/_export/code/bash/tip_colors_and_formatting?codeblock=56 ; sh 256-colors.sh
*/
# define _0		ft_putstr("\e[0m")
/*
** Square unicode.
*/
# define _SQU	"\u25fc"
# define _VOID	ft_putstr("\e[38;5;255m\u25fb") //e6
# define _A		ft_putstr("\e[38;5;9m"), ft_putstr(_SQU)
# define _B		ft_putstr("\e[38;5;1m"), ft_putstr(_SQU)
# define _C		ft_putstr("\e[38;5;88m"), ft_putstr(_SQU)
# define _D		ft_putstr("\e[38;5;208m"), ft_putstr(_SQU)
# define _E		ft_putstr("\e[38;5;202m"), ft_putstr(_SQU) // dark orange
# define _F		ft_putstr("\e[38;5;221m"), ft_putstr(_SQU)
# define _G		ft_putstr("\e[38;5;226m"), ft_putstr(_SQU) // yellow
# define _H		ft_putstr("\e[38;5;148m"), ft_putstr(_SQU)
# define _I		ft_putstr("\e[38;5;2m"), ft_putstr(_SQU)
# define _J		ft_putstr("\e[38;5;106m"), ft_putstr(_SQU)
# define _K		ft_putstr("\e[38;5;82m"), ft_putstr(_SQU)
# define _L		ft_putstr("\e[38;5;46m"), ft_putstr(_SQU)
# define _M		ft_putstr("\e[38;5;51m"), ft_putstr(_SQU) // bleu cyan
# define _N		ft_putstr("\e[38;5;123m"), ft_putstr(_SQU)
# define _O		ft_putstr("\e[38;5;81m"), ft_putstr(_SQU)
# define _P		ft_putstr("\e[38;5;74m"), ft_putstr(_SQU)
# define _Q		ft_putstr("\e[38;5;32m"), ft_putstr(_SQU)
# define _R		ft_putstr("\e[38;5;25m"), ft_putstr(_SQU)
# define _S		ft_putstr("\e[38;5;21m"), ft_putstr(_SQU)
# define _T		ft_putstr("\e[38;5;18m"), ft_putstr(_SQU)
# define _U		ft_putstr("\e[38;5;17m"), ft_putstr(_SQU)
# define _V		ft_putstr("\e[38;5;103m"), ft_putstr(_SQU)
# define _W		ft_putstr("\e[38;5;96m"), ft_putstr(_SQU)
# define _X		ft_putstr("\e[38;5;169m"), ft_putstr(_SQU)
# define _Y		ft_putstr("\e[38;5;162m"), ft_putstr(_SQU)
# define _Z		ft_putstr("\e[38;5;89m"), ft_putstr(_SQU)

int	ft_put_uni(const char *path, char **tab);
int	ft_put_palette(void);
#endif
