/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:26:52 by adashyan          #+#    #+#             */
/*   Updated: 2022/10/11 18:46:52 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	double_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	e_free(char *join, char *cmd_path)
{
	free(join);
	free(cmd_path);
}

void	exec_free(char **options, char *path)
{
	double_free(options);
	free(path);
}

void	p_free(char **sp_cmd, char **path)
{
	double_free(sp_cmd);
	double_free(path);
}
