/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:12:46 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/28 22:03:41 by adashyan         ###   ########.fr       */
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
}

void	zoom(t_map *map, int key)
{
	if (key == PLUS)
		map->zoom += 5;
	if (key == MINUS)
		map->zoom -= 5;
}

void	rotate(t_map *map, int key)
{
	if (key == X_KEY)
	{
		rotate_x(map, &map->dot1.y, &map->dot1.z);
	}
	if (key == Y_KEY)
	{
		rotate_y(map, &map->dot1.x, &map->dot1.z);
	}
}

int	red_cross(t_map *map, int key)
{
	(void)map;
	(void)key;
	exit(0);
}
