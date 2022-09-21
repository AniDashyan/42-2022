/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:43:47 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/21 19:07:14 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int f1, char *cmd, char **envp, int fd[2])
{
	char	**options;
	char	*path;

	path = envp_parsing(cmd, envp);
	if (!path)
	{
		perror("Error");
		exit(1);
	}
	if (!cmd)
	{
		perror("command not found");
		exit(-1);
	}
	options = cmd_split(cmd);
	close(fd[0]);
	dup2(f1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	if (execve(path, options, envp) == -1)
		perror("Error");
	close(f1);
	exit(1);
}
