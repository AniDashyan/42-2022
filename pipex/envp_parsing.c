/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:57:38 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/17 16:39:08 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **s)
{
	int		i;
	char	*envp_path;
	char	**path;

	i = 0;
	while (s[i])
	{
		envp_path = ft_strnstr(s[i], "PATH=", 5);
		if (envp_path)
			break ;
		i++;
	}
	path = ft_split(envp_path, ':');
	return (path);
}

char	**cmd_split(char *cmd)
{
	char	**splitted_cmd;

	splitted_cmd = ft_split(cmd, ' ');
	return (splitted_cmd);
}

char	*envp_parsing(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*join;
	char	*cmd_path;
	char	**splitted_cmd;

	path = find_path(envp);
	splitted_cmd = cmd_split(cmd);
	i = 0;
	while (path[i])
	{
		join = ft_strjoin(path[i], "/");
		if (join)
		{
			cmd_path = ft_strjoin(join, splitted_cmd[0]);
			if (access(cmd_path, F_OK | X_OK) == 0)
				return (cmd_path);
		}
		free(join);
		i++;
	}
	return (NULL);
}
