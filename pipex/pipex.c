/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:28 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/05 18:42:53 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// void pipex(int fd[2], char *cmd1, char *cmd2)
// {	
// 	pid_t c;

// 	if (pipe(fd[2]) == -1)
// 		return (perror("pipe has failed"));
// 	c = fork();
// 	if (c == -1)
// 		return (perror("fork has failed"));
// 	if (c == 0)
// }

#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
    char *options[3] = {"ls", "-la", NULL};

    (void)argc;
    (void)argv;
    execve("/bin/ls", options, envp);
    return (0);
}