/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:03:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/28 21:42:26 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map, int num)
{
	if (num == 1)
	{
		map->dot1.x = (map->dot1.x - map->dot1.y) * cos(0.8);
		map->dot1.y = (map->dot1.x + map->dot1.y) * sin(0.8) - map->dot1.z;
	}
	else if (num == 2)
	{
		map->dot2.x = (map->dot2.x - map->dot2.y) * cos(0.8);
		map->dot2.y = (map->dot2.x + map->dot2.y) * sin(0.8) - map->dot2.z;
	}
}

void	coords(t_map *map)
{
	map->dot1.z = map->z_matrix[map->dot1.y][map->dot1.x];
	map->dot2.z = map->z_matrix[map->dot2.y][map->dot2.x];
	map->dot1.x *= map->zoom;
	map->dot1.y *= map->zoom;
	map->dot2.x *= map->zoom;
	map->dot2.y *= map->zoom;
	map->dot1.x += map->shift_x;
	map->dot2.x += map->shift_x;
	map->dot1.y += map->shift_y;
	map->dot2.y += map->shift_y;
}

void	decider(t_map *map, int dx, int dy, int swap)
{
	int	i;
	int	decision;

	i = 0;
	decision = 2 * dy - dx;
	while (i < dx)
	{
		img_pix_put(map);
		set_color(map);
		while (decision >= 0)
		{
			decision = decision - 2 * dx;
			if (swap)
				map->dot1.x += sign(map->dot2.x - map->dot1.x);
			else
				map->dot1.y += sign(map->dot2.y - map->dot1.y);
		}
		decision = decision + 2 * dy;
		if (swap)
			map->dot1.y += sign(map->dot2.y - map->dot1.y);
		else
			map->dot1.x += sign(map->dot2.x - map->dot1.x);
		i++;
	}
}

void	bresenham(t_map *map)
{
	int	dx;
	int	dy;
	int	swap;

	coords(map);
	isometric(map, 1);
	isometric(map, 2);
	dx = abs(map->dot2.x - map->dot1.x);
	dy = abs(map->dot2.y - map->dot1.y);
	swap = 0;
	if (dy > dx)
	{
		ft_swap(&dx, &dy);
		swap = 1;
	}
	decider(map, dx, dy, swap);
}
