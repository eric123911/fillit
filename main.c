#include "fillit.h"

f_list	*ft_read(char *av)
{	
	int f;
	f_list	*list;
	f_list	*begin;
	
	f = open(av, O_RDONLY);
	list = malloc(sizeof(f_list));
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
    if (ac != 2)
        return (1);
    list = ft_read(av[1]);
	while (list->next)
	{
		printf("%s\n",list->str);
		list = list->next;
	}
    return (0);
}