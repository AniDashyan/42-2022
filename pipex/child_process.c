/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:43:47 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/27 18:55:16 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int f1, char *cmd, char **envp, int fd[2])
{
	char	**options;
	char	*path;

	if (!cmd)
	{
		perror("Error");
		exit(-1);
	}
	path = envp_parsing(cmd, envp);
	if (!path)
	{
		perror("Error");
		exit(1);
	}
	options = cmd_split(cmd);
	if (dup2(f1, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (execve(path, options, envp) == -1)
		perror("Error");
	close(f1);
	exit(0);
}
