/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:31:10 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/28 21:53:13 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_map *map)
{
	char	*dst;

	if (map->dot1.x > 0 && map->dot1.y > 0 && WIN_WIDTH > map->dot1.x
		&& WIN_HEIGHT > map->dot1.y)
	{
		dst = map->img.addr + (map->dot1.y * map->img.line_length
				+ map->dot1.x * (map->img.bits_per_pixel / 8));
		*(unsigned int *)dst = map->dot1.color;
	}
}

void	set_color(t_map *map)
{
	if (map->dot1.z > 0)
		map->dot1.color = hex_to_decimal("EA047E");
	else if (map->dot1.z < 0)
		map->dot1.color = hex_to_decimal("FF6D28");
	else
		map->dot1.color = hex_to_decimal("FCE700");
}
