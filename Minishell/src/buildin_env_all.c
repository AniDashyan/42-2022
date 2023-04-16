/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_env_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:19 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	buildin_env_all(t_pipe *pipe, int fd)
{
	t_env	*head;

	head = pipe->head_env;
	while (head)
	{
		if (head->key && head->val && ft_strcmp(head->key, "?") != 0)
			ft_printf(fd, "%s=%s\n", head->key, head->val);
		if (head->next == NULL)
			return ;
		head = head->next;
	}
}
