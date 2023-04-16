/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:30:08 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	del_one_t_env(t_env	*node)
{
	free(node->key);
	free(node->val);
	free(node);
	return (1);
}

static void	remove_else_inner(t_pipe *pipe, char **str1)
{
	t_env	*head;
	t_env	*prev;

	head = pipe->head_env;
	if (head == NULL)
		return ;
	if (head && ft_strcmp(head->key, str1[0]) == 0)
	{
		del_one_t_env(head);
		pipe->head_env = NULL;
		return ;
	}
	while (head)
	{
		if (ft_strcmp(head->key, str1[0]) == 0)
		{
			prev->next = head->next;
			del_one_t_env(head);
			return ;
		}
		prev = head;
		head = head->next;
	}
}

int	ft_list_remove_if(t_pipe *pipe)
{
	int		i;
	int		ret;

	ret = 0;
	i = 1;
	while (pipe->argv[i])
	{
		if (hendl_export_var(pipe->argv[i]) != 0)
		{
			ret = 1;
			ft_printf(2, "minishell:  %s `%s' not a valid identifier\n",
				pipe->argv[0], pipe->argv[i++]);
			continue ;
		}
		remove_else_inner(pipe, &pipe->argv[i]);
		i++;
	}
	return (ret);
}
