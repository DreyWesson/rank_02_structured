#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
// {
// 	int	swap;
// 	t_list	*tmp;

// 	tmp = lst;
// 	while(lst->next != NULL)
// 	{
// 		if (((*cmp)(lst->data, lst->next->data)) == 0)
// 		{
// 			swap = lst->data;
// 			lst->data = lst->next->data;
// 			lst->next->data = swap;
// 			lst = tmp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }

int cmp1(int data, int data_ref)
{
        if (data > data_ref)
            return (1);
		return (0);
}

int cmp2(int data, int data_ref)
{
        if (data > data_ref)
            return (1);
		return (0);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	void	*swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp1)(*(int *)lst->data, *(int *)lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp; // u gotta  start the loop all over again
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp2(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}

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
	sort_list(ptr, cmp1);
	print_list(ptr);
	write(1, "\n", 1);
	return (0);
}