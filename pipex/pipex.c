/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/20 20:04:14 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fds[2], char *cmd1, char *cmd2, char **envp)
{
	pid_t	parent;

	if (pipe(fds) == -1)
		return (perror("pipe has failed"));
	parent = fork();
	if (parent == -1)
	{
		perror("fork has failed");
		exit(-1);
	}
	if (!parent)
		child_process(fds[0], cmd1, envp);
	else
		child_process(fds[1], cmd2, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];

	(void)argc;
	(void)argv;
	if (argc == 5)
	{
		fd[0] = open(argv[1], O_RDONLY);
		fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
		pipex(fd, argv[2], argv[3], envp);
	}
	else
		ft_printf("Note enough arguments\n");
	return (0);
}
