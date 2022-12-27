/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:55:35 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 16:50:17 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map)
{
	map->x1 = map->x1 * cos(map->theta) - map->y1 * sin(map->theta);
	map->y1 = map->x1 * sin(map->theta) + map->y1 * cos(map->theta);
}
