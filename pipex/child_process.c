/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:43:47 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/05 18:39:38 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, char *cmd, char **envp, int *fd)
{
	char	**options;
	char	*path;
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		error(OPEN_ERR);
	path = envp_parsing(cmd, envp);
	options = cmd_split(cmd);
	if (!path)
	{
		free(path);
		double_free(options);
		error(CMD_ERR);
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (execve(path, options, envp) == -1)
		error(EXEC_ERR);
}
