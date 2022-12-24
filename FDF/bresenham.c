/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:03:02 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/24 20:57:47 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_map *map)
{
	char	*dst;

	dst = map->addr + ((int)map->y1 * map->line_length
			+ (int)map->x1 * (map->bits_per_pixel / 8));
	*(unsigned int *)dst = map->color;
}

void	three_d(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

// void	bresenham(t_map *map)
// {
// 	int	dx;
// 	int	dy;
// 	int	decision;

// 	map->x1 *= map->zoom;
// 	map->y1 *= map->zoom;
// 	map->x2 *= map->zoom;
// 	map->y2 *= map->zoom;
// 	map->z1 = map->z_matrix[map->y1][map->x1];
// 	// map->z2 = map->z_matrix[map->y2][map->x2];
// 	isometric(&map->x1, &map->y1, map->z1);
// 	// isometric(&map->x2, &map->y2, map->z2);
// 	dx = abs(map->x2 - map->x1);
// 	dy = abs(map->y2 - map->y1);
// 	decision = 2 * dy - dx;
// 	map->color = get_color(map->z1);
// 	while (map->x1 <= map->x2)
// 	{
// 		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, map->color);
// 		map->x1 += 1;
// 		if (decision < 0)
// 			decision += 2 * dy;
// 		else
// 		{
// 			decision += 2 * dy - 2 * dx;
// 			map->y1 += 1;
// 		}
// 	}
// }

int	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	return (0);
}

void	bresenham(t_map *map)
{
	int	dx;
	int	dy;
	int	swap;
	int	s1;
	int	s2;
	int	D;
	
	map->z1 = map->z_matrix[map->y1][map->x1];
	// map->z2 = map->z_matrix[map->y2][map->x2];
	map->x1 *= map->zoom;
	map->y1 *= map->zoom;
	map->x2 *= map->zoom;
	map->y2 *= map->zoom;
	dx = abs(map->x2 - map->x1);
	dy = abs(map->y2 - map->y1);
	swap = 0;
	s1 = sign(map->x2 - map->x1);
	s2 = sign(map->y2 - map->y1);
	swap = 0;
	// three_d(&map->x1, &map->y1, map->z1);
	// three_d(&map->x2, &map->y2, map->z2);
	map->color = get_color(map->z1);
	if (dy > dx) 
	{ 
		ft_swap(&dx, &dy);
		swap = 1;
	}
	D = 2*dy - dx;
	for (int i = 0; i < dx; i++)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, map->x1, map->y1, map->color);
		while (D >= 0)
		{
			D = D - 2 * dx;
			if (swap) 
				map->x1 += s1;
			else
				map->y1 += s2; }
			D = D + 2*dy; 
			if (swap)
				map->y1 += s2;
			else
				map->x1 += s1;
	}	
}