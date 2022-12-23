/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:03:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/23 21:26:16 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				bresenham(x, y, x + 1, y, map);
			if (y < map->height - 1)
				bresenham(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
