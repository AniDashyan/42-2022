/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/29 18:23:42 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f[2], char *cmd1, char *cmd2, char **envp)
{
	pid_t	parent;
	int		fds[2];

	if (pipe(fds) == -1)
		error(PIPE_ERR);
	parent = fork();
	if (parent == -1)
		error(FORK_ERR);
	if (parent == 0)
		child_process(f[0], cmd1, envp, fds);
	else
	{
		waitpid(parent, NULL, 0);
		parent_process(f[1], cmd2, envp, fds);
		exit(parent);
	}
	exit(parent);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	if (argc == 5)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (!fd[0])
			error(OPEN_ERR);
		fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		pipex(fd, argv[2], argv[3], envp);
	}
	else
	{
		ft_printf("Not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
