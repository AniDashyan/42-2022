/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:09 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:36:06 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

# define CMD_ERR	"command not found"
# define PATH_ERR 	"invalid path"
# define FORK_ERR	"fork has failed"
# define EXEC_ERR	"execve has failed"
# define PIPE_ERR   "pipe creation has failed"
# define ARG_ERR	"not enough arguments"
# define DUP_ERR	"can't duplicate the fd"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	**cmd_split(char *cmd);
char	*envp_parsing(char *cmd, char **envp);
void	child_process(int f1, char *cmd, char **envp, int fd[2]);
void	parent_process(int f2, char *cmd, char **envp, int fd[2]);
void	error(char *s);
#endif
