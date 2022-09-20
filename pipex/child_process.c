/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:43:47 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/20 20:07:10 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int f1, char *cmd, char **envp)
{
	char	**options;
	char	*path;
	int		f2;

	if (dup2(f2, f1) < 0)
		close(f1);
	path = envp_parsing(cmd, envp);
	options = cmd_split(cmd);
	if (execve(path, options, envp) == -1)
		perror("Error");
	close(f1);
}
