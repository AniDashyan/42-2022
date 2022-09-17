/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/17 13:35:51 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fds[2], char *cmd1, char *cmd2)
{
	pd_t	c;
	char	*cmd_path[2];

	if (pipe(fd[2]) == -1)
		return (perror("pipe has failed"));
	c = fork();
	if (c == -1)
	{
		perror("fork has failed");
		exit(1);
	}
	else if (c == 0)
}

int	main(int argc, char **argv, char **envp)
{
	return (0);
}
