/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:23:58 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/26 13:40:40 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_file_valid(char *path)
{
	char	**splitted_path;

	splitted_path = ft_split(path, '.');
	if (!splitted_path)
		error("Error: split has failed");
	if (ft_strncmp(splitted_path[1], "fdf", 4) == 0)
		return (1);
	free_str(splitted_path);
	return (0);
}
