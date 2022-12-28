/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:55:35 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/28 14:20:06 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_map *map, int *y, int *z)
{
	*y = *y * cos(map->theta) + *z * sin(map->theta);
	*z = -*y * sin(map->theta) + *z * cos(map->theta);
}

void	rotate_y(t_map *map, int *x, int *z)
{
	*x = *x * cos(map->theta) + *z * sin(map->theta);
	*z = -*x * sin(map->theta) + *z * cos(map->theta);
}
