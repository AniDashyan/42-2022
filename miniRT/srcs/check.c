/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:27:21 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 17:41:34 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	check_line(const char *line, char **data, const char *type,
	const int nb_elements)
{
	if (*data && !ft_strncmp(data[0], type, ft_strlen(type)))
	{
		if (ft_in_charset(line[ft_strlen(type)], WHITE_SPACES))
			return (ft_tab_size(data) == nb_elements);
	}
	return (0);
}

int	check_resolution(char **data)
{
	return (ft_atoi_strict(data[1]) <= 0 || ft_atoi_strict(data[2]) <= 0);
}
