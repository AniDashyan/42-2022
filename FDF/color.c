/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:31:10 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 18:50:33 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_map *map)
{
	char	*dst;

	if (map->x1 > 0 && map->y1 > 0 && WIN_WIDTH > map->x1 && \
		WIN_HEIGHT > map->y1)
	{
		dst = map->addr + ((int)map->y1 * map->line_length + \
			(int)map->x1 * (map->bits_per_pixel / 8));
		*(unsigned int *)dst = map->pixel;
	}
}

void	get_color(t_map *map, int x, int y)
{
	if (map->z_matrix[y][x] == 0 && map->color[y][x] == 0)
		map->pixel = 0xFFFFFF;
	else if (map->z_matrix[y][x] > 0 && map->color[y][x] != 0)
		map->pixel = 0xFF0000;
}
