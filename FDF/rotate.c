/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:55:35 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/26 20:01:36 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, t_map *map)
{
	*y = *y * cos(map->theta) - *z * sin(map->theta);
	*z = *z * sin(map->theta) + *z * cos(map->theta);
}

void	rotate_y(int *x, int *z, t_map *map)
{
	*x = *x * cos(map->theta) + *z * sin(map->theta);
	*z = -(*x) * sin(map->theta) + *z * cos(map->theta);
}

void	rotate_z(int *x, int *y, t_map *map)
{
	*x = *x * cos(map->theta) - *y * sin(map->theta);
	*y = *x * sin(map->theta) + *y * cos(map->theta);
}
