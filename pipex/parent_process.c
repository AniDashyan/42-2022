/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:56:33 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/27 18:42:39 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int f2, char *cmd, char **envp, int fd[2])
{
	char	**options;
	char	*path;

	if (!cmd)
	{
		perror("Error");
		exit(1);
	}
	path = envp_parsing(cmd, envp);
	if (!path)
	{
		perror("Error");
		exit(-1);
	}
	options = cmd_split(cmd);
	if (dup2(f2, STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	waitpid(-1, NULL, 0);
	if (execve(path, options, envp) == -1)
		perror("Error");
	close(f2);
}
