/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:31:45 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(t_data *data, t_pipe *tmp, int i)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	pipe_in_out(i, data, tmp);
}

static int	ft_waitpid(t_data *data)
{
	int		i;
	int		ret;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	i = -1;
	while (++i < data->pipe_count)
		waitpid(-1, &ret, 0);
	if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGPIPE)
			return (0);
		if (WTERMSIG(ret) == SIGQUIT)
			ft_printf(1, "Quit: 3");
		ft_printf(1, "\n");
		return (WTERMSIG(ret) + 128);
	}
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (0);
}

void	close_fds(t_data *data)
{	
	close(data->pipe_fd);
	data->pipe_fd = data->fd1[0];
	close(data->fd1[1]);
}

int	pipe_exec(t_data *data)
{
	int		i;
	pid_t	pid;
	pid_t	first_pid;
	t_pipe	*tmp;

	data->pipe_fd = dup(0);
	tmp = data->pipe;
	i = 0;
	while (tmp)
	{
		if (pipe(data->fd1) == -1)
			return (perror("minishell: fork:"), errno);
		pid = fork();
		if (pid == 0)
			first_pid = pid;
		if (pid == -1 && ft_printf(2, "minishell: fork: %s\n", strerror(errno)))
			return (kill(first_pid, SIGKILL), errno);
		if (pid == 0)
			child(data, tmp, i);
		close_fds(data);
		tmp = tmp->next;
		i++;
	}
	return (close(data->pipe_fd), ft_waitpid(data));
}
