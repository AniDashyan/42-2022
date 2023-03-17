#include "minishell.h"

t_pipe *new_t_pipe(char **tmp)
{
   t_pipe *new_node;

    new_node = malloc(sizeof(t_pipe));
    new_node->argv  = tmp;
	// printf(" new_node->argv = %s\n",  new_node->argv[0]);
    // mnacac@ dardznel NULL;
    new_node->next = NULL;
    return (new_node);
}

t_pipe	*ft_t_pipe_last(t_pipe *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (!lst -> next)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_t_pipe_add_back(t_pipe **lst, t_pipe *new)
{
	t_pipe	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_t_pipe_last(*lst);
	new_node->next = new;
}
