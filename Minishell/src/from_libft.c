/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:30:02 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_pipe	*ft_lstnew(void *content, t_env *env)
{
	t_pipe	*new_node;

	new_node = (t_pipe *)malloc(sizeof(t_pipe));
	if (!new_node)
		return (NULL);
	new_node->fd_in = 0;
	new_node->fd_out = 1;
	new_node->joined_argv = NULL;
	new_node->content = ft_strdup(content);
	new_node->argv = NULL;
	new_node->red = NULL;
	new_node->head_env = env;
	new_node->next = NULL;
	return (new_node);
}
