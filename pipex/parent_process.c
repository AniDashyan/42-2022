/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:56:33 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/10 20:09:20 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **argv, char *cmd, char **envp, int *fd)
{
	char	**options;
	char	*path;
	int		outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		error(OPEN_ERR);
	path = envp_parsing(cmd, envp);
	options = cmd_split(cmd);
	if (!path)
	{
		exec_free(options, path);
		error(CMD_ERR);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	while (1);
	execve(path, options, envp);
	free(path);
	double_free(options);
	error(EXEC_ERR);
}
