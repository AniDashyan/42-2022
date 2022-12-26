/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:12:46 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/26 20:19:15 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	keycodes(t_map *map, int key)
// {
// 	if (key == 53)
// 	{
// 		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
// 		red_cross(map, key);
// 	}
// 	else if (key == 7)
// 		rotate_x(&map->y1, &map->z1, map);
// 	else if (key == 16)
// 		rotate_y(&map->y1, &map->z1, map);
// 	else if (key == 6)
// 		rotate_z(&map->x1, &map->y1, map);
// 	return (0);
// }

int	red_cross(t_map *map, int key)
{
	(void)map;
	(void)key;
	exit(0);
}
