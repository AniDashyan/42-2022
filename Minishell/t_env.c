#include "minishell.h"

t_env *new_t_env(char *tmp, char* tmp1)
{
   t_env *new_node;

    new_node = malloc(sizeof(t_env));
    new_node->key= tmp;
    new_node->val= tmp1;
	// new_node->key=ft_strjoin(new_node->key,"=");
	// printf(" new_node->argv = %s\n",  new_node->argv[0]);
    // mnacac@ dardznel NULL;
    new_node->next = NULL;
    return (new_node);
}

t_env	*ft_t_env_last(t_env *lst)
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

void	ft_t_env_add_back(t_env **lst, t_env *new)
{
	t_env	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_t_env_last(*lst);
	new_node->next = new;
}
