/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:57:38 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/14 16:10:23 by adashyan         ###   ########.fr       */
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

char	*envp_parsing(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*join;
	char	*tmp;
	char	*cmd_path;

	path = find_path(envp);
	i = 0;
	while (path[i])
	{
		tmp = path[i];
		join = ft_strjoin(path[i], "/");
		if (join)
		{
			cmd_path = ft_strjoin(join, cmd);
			if (access(cmd_path, F_OK | X_OK) == 0)
				return (cmd_path);
		}
		free(join);
		i++;
	}
	return (NULL);
}
