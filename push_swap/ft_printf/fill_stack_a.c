#include "push_swap.h"

t_stack	fill_stack(char **str)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	while (str[i])
	{
		stack_a = ft_lstnew(ft_atoi(str[i]));
		i++;
	}
}
