/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:06:59 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 18:07:23 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	move_up(const int keycode, t_window *w)
{
	t_camera	*camera;

	if (keycode != UP)
		return (0);
	camera = w->scene->camera;
	camera->pos = sub_vect(camera->pos, camera->up);
	return (1);
}

int	move_down(const int keycode, t_window *w)
{
	t_camera	*camera;

	if (keycode != DOWN)
		return (0);
	camera = w->scene->camera;
	camera->pos = add_vect(camera->pos, camera->up);
	return (1);
}

int	move_left(const int keycode, t_window *w)
{
	t_camera	*camera;

	if (keycode != LEFT)
		return (0);
	camera = w->scene->camera;
	camera->pos = sub_vect(camera->pos, camera->b);
	return (1);
}

int	move_right(const int keycode, t_window *w)
{
	t_camera	*camera;

	if (keycode != RIGHT)
		return (0);
	camera = w->scene->camera;
	camera->pos = add_vect(camera->pos, camera->b);
	return (1);
}
