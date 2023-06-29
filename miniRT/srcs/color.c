/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:22:44 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/29 18:05:21 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_rgb	mult_rgb_double(const t_rgb rgb, const double mult)
{
	return (int_to_rgb(rgb.r * mult, rgb.g * mult, rgb.b * mult));
}

void	min_rgb(t_rgb *color)
{
	color->r = ft_min_int(color->r, 255);
	color->g = ft_min_int(color->g, 255);
	color->b = ft_min_int(color->b, 255);
}

t_rgb	mult_rgb_rgb(const t_rgb rgb, const t_rgb mult)
{
	return (int_to_rgb(rgb.r * (mult.r / 255.),
			rgb.g * (mult.g / 255.), rgb.b * (mult.b / 255.)));
}

t_rgb	add_rgb_rgb(const t_rgb rgb, const t_rgb add)
{
	return (int_to_rgb(rgb.r + add.r, rgb.g + add.g, rgb.b + add.b));
}

t_rgb	get_color(const char *type, const void *object)
{
	if (!ft_strncmp(type, "sp", 3))
		return (((t_sphere *)object)->color);
	if (!ft_strncmp(type, "pl", 3))
		return (((t_plane *)object)->color);
	return (((t_cylinder *)object)->color);
}
