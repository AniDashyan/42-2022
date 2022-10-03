/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:09 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/03 17:53:20 by adashyan         ###   ########.fr       */
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
# define OPEN_ERR	"can't open the file"
# define WAIT_ERR	"wait has failed"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *s, char c);
char	**cmd_split(char *cmd);
char	*envp_parsing(char *cmd, char **s);
void	child_process(char **argv, char *cmd, char **envp, int *fd);
void	parent_process(char **argv, char *cmd, char **envp, int *fd);
void	error(char *s);
void	double_free(char **s);
#endif
