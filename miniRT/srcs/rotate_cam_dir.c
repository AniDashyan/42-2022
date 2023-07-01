/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:17:26 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 13:17:29 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	rot_up(const int keycode, t_window *w)
{
	t_camera	*camera;
	t_vect		vect;

	if (keycode != KEY_8)
		return (0);
	camera = w->scene->camera;
	vect = camera->orientation;
	camera->orientation = multi_vect(vect, 20);
	camera->orientation = add_vect(camera->orientation, minus_vect(camera->up));
	camera->orientation = normalize(camera->orientation);
	camera->up = multi_vect(camera->up, 20);
	camera->up = add_vect(camera->up, vect);
	camera->up = normalize(camera->up);
	return (1);
}

int	rot_down(const int keycode, t_window *w)
{
	t_camera	*camera;
	t_vect		vect;

	if (keycode != KEY_2)
		return (0);
	camera = w->scene->camera;
	vect = camera->orientation;
	camera->orientation = multi_vect(vect, 20);
	camera->orientation = add_vect(camera->orientation, camera->up);
	camera->orientation = normalize(camera->orientation);
	camera->up = multi_vect(camera->up, 20);
	camera->up = add_vect(camera->up, minus_vect(vect));
	camera->up = normalize(camera->up);
	return (1);
}

int	rot_left(const int keycode, t_window *w)
{
	t_camera	*camera;
	t_vect		vect;

	if (keycode != KEY_4)
		return (0);
	camera = w->scene->camera;
	vect = camera->orientation;
	camera->orientation = multi_vect(vect, 20);
	camera->orientation = add_vect(camera->orientation, minus_vect(camera->b));
	camera->orientation = normalize(camera->orientation);
	camera->b = multi_vect(camera->b, 20);
	camera->b = add_vect(camera->b, vect);
	camera->b = normalize(camera->b);
	return (1);
}

int	rot_right(const int keycode, t_window *w)
{
	t_camera	*camera;
	t_vect		vect;

	if (keycode != KEY_6)
		return (0);
	camera = w->scene->camera;
	vect = camera->orientation;
	camera->orientation = multi_vect(vect, 20);
	camera->orientation = add_vect(camera->orientation, camera->b);
	camera->orientation = normalize(camera->orientation);
	camera->b = multi_vect(camera->b, 20);
	camera->b = add_vect(camera->b, minus_vect(vect));
	camera->b = normalize(camera->b);
	return (1);
}
