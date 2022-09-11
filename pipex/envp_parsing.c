/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:57:38 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/11 17:36:02 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*envp_parsing(char *cmd, char **envp)
{
	int i;
	char **path;
	char *envp_path;
	char *join;
	char *tmp;
	char *cmd_path;

	i = 0;
	while (envp[i])
	{	
		envp_path = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		if (envp_path)
			break;
		i++;
	}

	path = ft_split(envp[i], ':');
	i = 0;
	while (path[i])
	{	
	 	tmp = path[i];
	 	join = ft_strjoin(path[i], "/");
		free(tmp);
		i++;
	}

	i = 0;
	while (path[i])
	{	
		cmd_path = ft_strjoin(path[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

int main(int argc, char **argv, char **envp)
{
    char *cmd_path;
    char *options[3] = {"ls", "-la", NULL};
    char *cmd = "ls";

    (void)argc;
    (void)argv;
    cmd_path = envp_parsing(cmd, envp);
	printf("%s", cmd_path);
    // if (!cmd_path)
    // {
    //     perror(cmd_path);
    //     return(-1);
    // }
    // execve(cmd_path, options, envp);
    // printf("Victory!");
    // free(cmd_path);
    return(0);
}