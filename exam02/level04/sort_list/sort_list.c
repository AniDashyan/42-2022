#include "list.h"

int ascending(int a, int b)
{
	return (a <= b);
}

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	if (!lst)
		return (NULL);
	t_list *cur = lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			swap(&lst->data, &lst->next->data);
			lst = cur;
		}
		else
			lst = lst->next;
	}
	lst = cur;
	return (lst);
}

/*
int	main(void)
{
	t_list *c = malloc(sizeof(t_list));
	c->next = 0;
	c->data = 45;

	t_list *b = malloc(sizeof(t_list));
	b->next = c;
	b->data = 73;

	t_list *a = malloc(sizeof(t_list));
	a->next = b;
	a->data = 108;

	t_list *lst = a;
	while (lst)
	{
		printf("%d, ", lst->data);
		lst = lst->next;
	}
	printf("\n");

	lst = sort_list(a, ascending);

	// lst = a;
	while (lst)
	{
		printf("%d, ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}
*/
