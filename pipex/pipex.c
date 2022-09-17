/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/17 17:32:43 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fds[2], char *cmd1, char *cmd2)
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
		ft_printf("%s\n", cmd1);
	else
		ft_printf("%s", cmd2);
}

int	main(void)
{
	int	fd[2];

	fd[0] = open("infile.txt", O_RDONLY);
	fd[1] = open("outfile.txt", O_CREAT | O_RDWR | O_TRUNC);
	return (0);
}
