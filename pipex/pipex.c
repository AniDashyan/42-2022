/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/12 18:21:03 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	child1;
	pid_t	child2;
	int		fds[2];

	if (argc == 5)
	{
		if (pipe(fds) == -1)
			error(PIPE_ERR);
		child1 = fork();
		if (child1 == -1)
			error(FORK_ERR);
		else if (child1 == 0)
		{
			child_process(argv, argv[2], envp, fds);
			exit(child1);
		}
		waitpid(child1, NULL, 0);
		child2 = fork();
		if (child2 == -1)
			error(FORK_ERR);
		else if (child2 == 0)
			parent_process(argv, argv[3], envp, fds);
		waitpid(child2, NULL, 0);
	}
	else
		ft_printf("Bad arguments\n");
	return (0);
}
