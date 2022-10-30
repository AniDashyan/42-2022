#include "push_swap.h"

t_stack *fill_stack(char **str)
{
	int		i;
	t_stack	*top;

	i = 0;
	top = NULL;
	while (str[i])
	{
		ft_lstadd_back(&top, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	return (top);
}
