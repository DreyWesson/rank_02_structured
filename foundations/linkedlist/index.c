#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

t_list	*create_list(void *value)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->next = NULL;
	ptr->data = value;
	return (ptr);
}

void add_to_tail(t_list **ptr, t_list *new)
{
	new->next = *ptr;
	*ptr = new;
}

void print_list(t_list *head_ref)
{
	t_list	*tmp;

	tmp = head_ref;
	while (tmp)
	{
		printf("%d\n",(*(int *)tmp->data)) ;
		tmp = tmp->next;
	}
}



int	main(int argc, char **argv)
{
	t_list	*ptr;
	int		i;

	(void)argc;
	(void)argv;
	ptr = NULL;
	int num[4] = {1, 2, 3, 4};
	i = 0;

	while (i < 4)
	{
		add_to_tail(&ptr, create_list(&num[i]));
		i++;
	}

	print_list(ptr);
	write(1, "\n", 1);
	return (0);
}
