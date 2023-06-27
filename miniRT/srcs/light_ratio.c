/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:30:53 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 17:30:54 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	decrement_light_ratio(const int keycode, t_window *w)
{
	t_light	*light;

	if (keycode != KEY_F1)
		return (0);
	light = w->scene->light;
	if (light->ratio > 0.1 * 255.0)
	{
		light->color = dev_rgb_double(light->color, light->ratio);
		light->ratio -= 0.1 * 255.0;
		light->color = mult_rgb_double(light->color, light->ratio);
	}
	else
	{
		light->color = int_to_rgb(0, 0, 0);
		light->ratio = 0;
	}
	return (1);
}

int	increment_light_ratio(const int keycode, t_window *w)
{
	t_light	*light;

	if (keycode != KEY_F2)
		return (0);
	light = w->scene->light;
	if (light->ratio < 0.9 * 255.0)
	{
		if (light->ratio == 0)
		{
			light->ratio = 0.1 * 255.0;
			light->color = int_to_rgb(6120, 6120, 6477);
		}
		else
		{
			light->color = dev_rgb_double(light->color, light->ratio);
			light->ratio += 0.1 * 255.0;
			light->color = mult_rgb_double(light->color, light->ratio);
		}
	}
	return (1);
}
