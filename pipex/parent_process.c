/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:56:33 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:32:45 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int f2, char *cmd, char **envp, int fd[2])
{
	char	**options;
	char	*path;

	if (!cmd)
		error(CMD_ERR);
	path = envp_parsing(cmd, envp);
	if (!path)
		error(PATH_ERR);
	options = cmd_split(cmd);
	if (!dup2(f2, STDOUT_FILENO))
		error(DUP_ERR);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	if (execve(path, options, envp) == -1)
		error(EXEC_ERR);
	close (f2);
}
