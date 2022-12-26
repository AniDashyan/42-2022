/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:03:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/26 19:22:24 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map, int num)
{
	if (num == 1)
	{
		map->x1 = (map->x1 - map->y1) * cos(0.8);
		map->y1 = (map->x1 + map->y1) * sin(0.8) - map->z1;
	}
	else if (num == 2)
	{
		map->x2 = (map->x2 - map->y2) * cos(0.8);
		map->y2 = (map->x2 + map->y2) * sin(0.8) - map->z2;
	}
}

void	coords(t_map *map)
{
	map->z1 = map->z_matrix[map->y1][map->x1];
	map->z2 = map->z_matrix[map->y2][map->x2];
	map->x1 *= map->zoom;
	map->y1 *= map->zoom;
	map->x2 *= map->zoom;
	map->y2 *= map->zoom;
	map->x1 += map->shift;
	map->x2 += map->shift;
}

void	decider(t_map *map, int dx, int dy, int swap)
{
	int	i;
	int	decision;

	i = 0;
	decision = 2 * dy - dx;
	while (i < dx)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, map->color);
		while (decision >= 0)
		{
			decision = decision - 2 * dx;
			if (swap)
				map->x1 += sign(map->x2 - map->x1);
			else
				map->y1 += sign(map->y2 - map->y1);
		}
		decision = decision + 2 * dy;
		if (swap)
			map->y1 += sign(map->y2 - map->y1);
		else
			map->x1 += sign(map->x2 - map->x1);
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
	dx = abs(map->x2 - map->x1);
	dy = abs(map->y2 - map->y1);
	swap = 0;
	map->color = get_color(map->z1);
	if (dy > dx)
	{
		ft_swap(&dx, &dy);
		swap = 1;
	}
	decider(map, dx, dy, swap);
}
