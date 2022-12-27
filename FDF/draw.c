/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:03:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 18:50:52 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int x, int y, t_map *map, int tmp)
{
	map->x1 = x;
	map->y1 = y;
	map->x2 = map->x1;
	map->y2 = map->y1 + 1;
	if (tmp == 1)
	{
		map->x2 += 1;
		map->y2 = y;
	}
	bresenham(map);
}

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
			get_color(map, x, y);
			if (x < map->width - 1)
				draw_line(x, y, map, 1);
			if (y < map->height - 1)
				draw_line(x, y, map, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
}
