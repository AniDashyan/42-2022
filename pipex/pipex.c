/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/17 14:48:07 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fds[2])
{
	pid_t	parent;

	if (pipe(fds) == -1)
		return (perror("pipe has failed"));
	parent = fork();
	if (parent == -1)
	{
		perror("fork has failed");
		exit(1);
	}
	if (!parent)
		ft_printf("child\n");
	else
		ft_printf("parent");
}

int	main(void)
{
	int	fd[2];

	fd[0] = 3;
	fd[1] = 4;
	pipex(fd);
	return (0);
}
