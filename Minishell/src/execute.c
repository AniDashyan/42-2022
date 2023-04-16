/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:30 by adashyan          #+#    #+#             */
/*   Updated: 2023/04/16 18:46:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*access_path(t_data *data, char **args)
{
	char	**split_path;
	int		i;
	char	*str;
	char	*exe;

	i = 0;
	if (access(args[0], X_OK) == 0)
		return (args[0]);
	exe = ft_strjoin("/", args[0]);
	split_path = ft_split(ft_get_value("PATH", data), ':');
	while (split_path[i])
	{
		str = ft_strjoin(split_path[i], exe);
		if (access(str, X_OK) == 0)
		{
			free(exe);
			free_matrix(split_path);
			return (str);
		}
		free(str);
		i++;
	}
	free(exe);
	free_matrix(split_path);
	return (NULL);
}

int	is_abs_or_relative(const char *str)
{
	if (str[0] == '/')
		return (1);
	if (str[0] == '.' && str[1] == '/')
		return (1);
	if (str[0] == '.' && str[1] == '.' && str[2] == '/')
		return (1);
	return (0);
}

int	lsh_launch(t_data *data, t_pipe *pipe)
{
	char	*path;

	if (pipe->argv)
	{
		path = pipe->argv[0];
		if (there_is_builtin(pipe) == 1)
			exit(choose_builtin(pipe, data, 1));
		if (is_abs_or_relative(pipe->argv[0]))
			path = pipe->argv[0];
		else if (ft_get_value("PATH", data))
			path = access_path(data, pipe->argv);
		if (path == NULL)
		{
			ft_printf(2, "minishell: %s:  command not found\n", pipe->argv[0]);
			exit(127);
		}
		if (execve(path, pipe->argv, data->env) == -1)
		{
			ft_printf(2, "minishell: %s: %s\n",
				pipe->argv[0], strerror(errno));
			exit(errno);
		}
	}
	exit(0);
}

int	execute(t_data *data)
{
	int	res;

	if (data->pipe_count == 1 && there_is_builtin(data->pipe) == 1)
		return (choose_builtin(data->pipe, data, data->pipe->fd_out));
	else
	{
		res = pipe_exec(data);
		return (res);
	}
	return (0);
}
