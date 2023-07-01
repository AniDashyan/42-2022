/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:17:48 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 13:17:50 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	rot_center_left(const int keycode, t_window *w)
{
	t_camera	*camera;
	t_vect		vect;

	if (keycode != KEY_9)
		return (0);
	camera = w->scene->camera;
	vect = camera->b;
	camera->b = multi_vect(vect, 10);
	camera->b = add_vect(camera->b, camera->up);
	camera->b = normalize(camera->b);
	camera->up = multi_vect(camera->up, 10);
	camera->up = add_vect(camera->up, minus_vect(vect));
	camera->up = normalize(camera->up);
	return (1);
}

int	rot_center_right(const int keycode, t_window *w)
{
	t_camera	*camera;
	t_vect		vect;

	if (keycode != KEY_1)
		return (0);
	camera = w->scene->camera;
	vect = camera->b;
	camera->b = multi_vect(vect, 10);
	camera->b = add_vect(camera->b, minus_vect(camera->up));
	camera->b = normalize(camera->b);
	camera->up = multi_vect(camera->up, 10);
	camera->up = add_vect(camera->up, vect);
	camera->up = normalize(camera->up);
	return (1);
}
