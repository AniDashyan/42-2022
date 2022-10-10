/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/10 20:10:26 by adashyan         ###   ########.fr       */
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
		else if (parent == 0)
		{
			child_process(argv, argv[2], envp, fds);
			while (1)
			{
			}
			exit(parent);
		}
		else
		{
			waitpid(parent, NULL, 0);
			parent_process(argv, argv[3], envp, fds);
		}
		while (1)
		{
		}
		exit(parent);
	}
	else
		ft_printf("Bad arguments\n");
	return (0);
}
