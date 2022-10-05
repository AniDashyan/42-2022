/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/05 18:41:59 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	parent;
	int		fds[2];

	if (argc == 5)
	{
		if (pipe(fds) == -1)
			error(PIPE_ERR);
		parent = fork();
		if (parent == -1)
			error(FORK_ERR);
		if (parent == 0)
			child_process(argv, argv[2], envp, fds);
		waitpid(parent, NULL, 0);
		parent_process(argv, argv[3], envp, fds);
	}
	else
		error(ARG_ERR);
	return (0);
}
