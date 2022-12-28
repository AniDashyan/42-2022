/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:03:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/28 21:42:17 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int x, int y, t_map *map, int tmp)
{
	map->dot1.x = x;
	map->dot1.y = y;
	map->dot2.x = map->dot1.x;
	map->dot2.y = map->dot1.y + 1;
	if (tmp == 1)
	{
		map->dot2.x += 1;
		map->dot2.y = y;
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
			if (x < map->width - 1)
				draw_line(x, y, map, 1);
			if (y < map->height - 1)
				draw_line(x, y, map, 0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img.img_ptr, 0, 0);
}
