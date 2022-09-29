/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:43:47 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:31:38 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int f1, char *cmd, char **envp, int fd[2])
{
	char	**options;
	char	*path;

	if (!cmd)
		perror("error");
	path = envp_parsing(cmd, envp);
	if (!path)
		error(PATH_ERR);
	options = cmd_split(cmd);
	if (dup2(f1, STDIN_FILENO) < 0)
		error(DUP_ERR);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (execve(path, options, envp) == -1)
		error(EXEC_ERR);
	close (f1);
}
