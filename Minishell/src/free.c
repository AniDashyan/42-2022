/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:50 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
	return (1);
}

void	free_redirect(t_redirect *redirect)
{
	t_redirect	*prev;

	while (redirect)
	{
		prev = redirect;
		if (redirect->heredoc_fd != -1)
			close(redirect->heredoc_fd);
		free(redirect->f_name);
		redirect = redirect->next;
		free(prev);
	}
}

void	free_pipe(t_pipe *pipe)
{
	t_pipe	*prev;

	while (pipe)
	{
		prev = pipe;
		if (pipe->fd_in != 0)
			close(pipe->fd_in);
		if (pipe->fd_out != 1)
			close(pipe->fd_out);
		free(pipe->content);
		free(pipe->joined_argv);
		free_matrix(pipe->argv);
		free_redirect(pipe->red);
		pipe = pipe->next;
		free(prev);
	}
}

void	free_data(t_data *data)
{
	data->pipe_count = 0;
	data->len_key_sum = 0;
	data->len_val_sum = 0;
	free_pipe(data->pipe);
	data->pipe = NULL;
}
