/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:59:04 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/27 19:37:01 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_split(char *cmd)
{
	char	**splitted_cmd;

	if (!cmd)
		return (NULL);
	splitted_cmd = ft_split(cmd, ' ');
	return (splitted_cmd);
}
