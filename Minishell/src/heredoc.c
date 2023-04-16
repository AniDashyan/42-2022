/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:30:50 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_child(t_data *data, t_redirect *red, int fd)
{
	char	*s;
	char	*tmp_free;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		set_term_attr(0);
		s = readline("heredoc>");
		set_term_attr(1);
		if (s == NULL || ft_strcmp(s, red->f_name) == 0)
		{
			free(s);
			s = NULL;
			break ;
		}
		tmp_free = s;
		s = hendl_doloar_comand(data, s);
		free(tmp_free);
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
		free(s);
	}
	close(fd);
	exit (0);
}

int	heredoc(t_data *data, t_redirect *red)
{
	int	pid;
	int	fd[12];
	int	ret;

	while (red)
	{
		if (red->flag == HEREDOC)
		{
			if (pipe(fd) == -1)
				exit(1);
			pid = fork();
			if (pid == 0)
				heredoc_child(data, red, fd[1]);
			red->heredoc_fd = fd[0];
			close(fd[1]);
			signal(SIGINT, SIG_IGN);
			waitpid(pid, &ret, 0);
			if (WIFSIGNALED(ret))
				return (ft_printf(1, "\n"), 1);
		}
		red = red->next;
	}
	return (0);
}
