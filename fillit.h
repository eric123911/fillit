/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 11:50:42 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 14:01:11 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <fcntl.h>


# include <stdio.h>

typedef struct			p_list
{
	char				*str;
	struct p_list		*next;
	struct p_list		*prev;
}						f_list;

char    validate_file(const f_list *list);

#endif
