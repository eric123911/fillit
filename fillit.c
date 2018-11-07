/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 16:53:07 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 17:23:05 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

// la variable size correspond à la taille du carré actuel

static char	**ft_tab_malloc(size_t size)
{
	size_t i;
	char **tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if(!(tab[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	set_offset(int *offset_x, int *offset_Y, int x, int y)
{
			*offset_x = x;
			*offset_Y = y;
}

int		fill_as_possible(char *str, char ***tab, int (*ofs)[], size_t realmode)
{
	int *x;
	int *c_x;
	int *c_y;

	x = &(*ofs)[2];
	c_x = &(*ofs)[1];
	c_y = &(*ofs)[4];
	while (str[*x])
	{
		if (str[*x] == '#')
		{
			if (*c_x == -1)
				set_offset(c_x, c_y, *x, (*ofs)[5]);
			if (*x - *c_x + (*ofs)[0] >= (*ofs)[6])
				return (3); // arriver au bout de l'axe X
			if ((*ofs)[5] - *c_y + (*ofs)[3] >= (*ofs)[6])
				return (2); // arriver au bout de l'axe Y; implique un reset total et size++;
			if ((*tab)[(*ofs)[5] - *c_y + (*ofs)[3]][*x - *c_x + (*ofs)[0]] != 0)
				return (1); // case déja utilisé
			if (realmode == 1)
				(*tab)[(*ofs)[5] - *c_y + (*ofs)[3]][*x - *c_x + (*ofs)[0]] = (*ofs)[7];
		}
		(*x)++;
	}
	*x = 0;
	return (0);
}

const f_list		*call_algo(const f_list *list, int (*offset)[], char ***tab)
{
	size_t four; // lis les 4 ligne correspondant au tretriminos
	f_list *begin;
	int temp;
	
	four = 4;
	begin = (f_list*)list;
	while (four--) // lecture du tretriminos
	{	
		if((temp = fill_as_possible(list->str, tab, offset, 0)))
			(*offset)[8] = temp;
		(*offset)[5]++;
		list = list->next;
	}
	if ((*offset)[8] == 0)
	{
		(*offset)[5] = 0;
		while (four-- + 5) // lecture du tretriminos
		{	
			fill_as_possible(begin->str, tab, offset, 1);
			(*offset)[5]++;
			begin = begin->next;
		}
	}
	(*offset)[5] = 0;
	return (list); // sortie 0 de la fonction la tretriminos à bien été placé
}

char **		replace0(char **tab, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (tab[i][j] == '\0')
				tab[i][j] = ' ';
		}
	}
	return (tab);
}

char		**fillit(const f_list *list)
{
	char **result;
	f_list *begin;

	//              G_X  C_X X G_Y C_Y Y SIZE C  RETN
	int offset[9] = {0 , -1, 0, 0, -1, 0, 2, 'A', 0};

	begin = (f_list*)list;
	result = ft_tab_malloc(offset[6]);
	while (list) // fin du fichier ?
	{
		list = call_algo(list, &offset , &result); // non
		fflush(stdout);
		if (offset[8] != 0)
			list = list->prev->prev->prev->prev;
		else
		{
			list = list->next; // on reboucle et permet de zapper la ligne /n apres un tretriminos
			offset[7]++;
		}
		if (offset[8] == 1)
			offset[3]++;
		if (offset[8] == 2)
		{
			offset[0]++;
			offset[3] = 0;;
		}
		
		if (offset[8] == 3)
		{
			list = begin;
			offset[3] = 0;
			offset[7] = 'A';
			offset[0] = 0;
			offset[6]++;
			result = ft_tab_malloc(offset[6]);
		}
		offset[8] = 0;
		offset[1] = -1; //remise a zero des offsets X_c;
		offset[4] = -1;// remise a zero des offsets Y_c;
	}

	return (replace0(result, offset[6])); // oui
}