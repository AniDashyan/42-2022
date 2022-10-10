/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:57:38 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/10 20:07:30 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

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
		{
			envp_path = ft_substr(envp_path, 5, ft_strlen(envp_path));
			if (!envp_path)
				return (NULL);
			break ;
		}
		i++;
	}
	path = ft_split(envp_path, ':');
	free(envp_path);
	return (path);
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
	while (path[i++])
	{
		join = ft_strjoin(path[i], "/");
		if (check_cmd(cmd))
			return (cmd);
		cmd_path = ft_strjoin(join, splitted_cmd[0]);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			double_free(path);
			free(join);
			return (cmd_path);
		}
		free(join);
		free(cmd_path);
	}
	double_free(splitted_cmd);
	double_free(path);
	return (NULL);
}
