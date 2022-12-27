/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:12:46 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 16:51:24 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_map *map, int key)
{
	if (key == LEFT_ARROW)
		map->shift_x -= 10;
	else if (key == RIGHT_ARROW)
		map->shift_x += 10;
	else if (key == DOWN_ARROW)
		map->shift_y += 10;
	else if (key == UP_ARROW)
		map->shift_y -= 10;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
}

void	zoom(t_map *map, int key)
{
	if (key == PLUS)
		map->zoom += 5;
	if (key == MINUS)
		map->zoom -= 5;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
}

void	rotate(t_map *map, int key)
{
	if (key == X_KEY)
		rotate_x(map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
}

int	red_cross(t_map *map, int key)
{
	(void)map;
	(void)key;
	exit(0);
}
