#include "minishell.h"

void	ft_lstadd_front(t_pipe **lst, t_pipe *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_pipe **lst, t_pipe *new)
{
	t_pipe	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_lstlast(*lst);
	new_node->next = new;
}

t_pipe	*ft_lstlast(t_pipe *lst)
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

t_pipe	*ft_lstnew(void *content, t_env *env)
{
	t_pipe	*new_node;

	new_node = (t_pipe *)malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->argv = NULL;
	new_node->red = NULL;
	// new_node->head_env = env;
	new_node-> next = NULL;
	return (new_node);
}