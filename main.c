#include "fillit.h"

f_list	*ft_read(char *av)
{
	int f;
	f_list	*list;
	f_list	*begin;

	f = open(av, O_RDONLY);
	list = malloc(sizeof(f_list));
	list->prev = NULL;
	begin = list;
	while (get_next_line(f, &list->str) > 0)
	{
		list->next = malloc(sizeof(f_list));
		list->next->prev = list;
		list = list->next;
	}
	list->next = NULL;
	return (begin);
}

int main(int ac, char **av)
{
	f_list	*list;
    //char **tab;
	//int i;

	if (ac != 2)
        return (1);
    list = ft_read(av[1]);
	if (validate_file(list))
	{
		ft_putstr("error\n");
		return (1);
	}
	/*tab = fillit(list);
	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}*/
	return (0);
}
