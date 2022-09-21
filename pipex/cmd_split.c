/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:59:04 by adashyan          #+#    #+#             */
/*   Updated: 2022/09/21 19:09:38 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_split(char *cmd)
{
	char	**splitted_cmd;

	splitted_cmd = ft_split(cmd, ' ');
	return (splitted_cmd);
}
