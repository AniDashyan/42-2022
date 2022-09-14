/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/14 16:12:18 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fd[2], char *cmd1, char *cmd2)
{
	pid_t	c;

	if (pipe(fd[2]) == -1)
		return (perror("pipe has failed"));
	c = fork();
	if (c == -1)
		return (perror("fork has failed"));
}
