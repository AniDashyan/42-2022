/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:03:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/23 21:26:07 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	int	color;

	color = 0xffffff;
	if (z != 0)
		color = 0xff0000;
	return (color);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x1, float y1, float x2, float y2, t_map *map)
{
	float	dx;
	float	dy;
	float	decision;
	int		z1;
	int		z2;

	z1 = map->z_matrix[(int)y1][(int)x1];
	z2 = map->z_matrix[(int)y2][(int)x2];
	
	x1 *= map->zoom;
	x2 *= map->zoom;
	y1 *= map->zoom;
	y2 *= map->zoom;
	map->x = x1;
	map->y = y1;
	dx = (x2 - x1);
	dy = (y2 - y1);
	// isometric(&x1, &y1, z1);
	// isometric(&x2, &y2, z2);
	decision = 2 * dy - dx;
	map->color = get_color(z1);
	while (map->x <= x2)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x, map->y, map->color);
		map->x += 1;
		if (decision < 0)
			decision += 2 * dy;
		else
		{
			decision += 2 * dy - 2 * dx;
			map->y += 1;
		}
	}
}
