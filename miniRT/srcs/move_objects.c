/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:57:02 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 13:20:53 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static void	move_cylinder(int x, int y, t_window *window, int camera_disp)
{
	t_cylinder		*cy;
	t_couple		delta;
	double			l;

	if (!ft_strncmp(window->type, "cy", 3))
	{
		cy = (t_cylinder *)window->object;
		l = distance(window->scene->camera->pos, cy->pos);
		delta.w = l * (x - window->mouse_position.w);
		delta.w = delta.w * 2 * tan((to_rad(window->scene->camera->fov * 0.5)));
		delta.w = delta.w / camera_disp;
		delta.h = l * (y - window->mouse_position.h);
		delta.h = delta.h * 2 * tan((to_rad(window->scene->camera->fov * 0.5)));
		delta.h = delta.h / camera_disp;
		cy->pos = add_vect(cy->pos, multi_vect(window->scene->camera->b, \
			delta.w));
		cy->pos = add_vect(cy->pos, multi_vect(window->scene->camera->up, \
			delta.h));
	}
}

static void	move_plane(int x, int y, t_window *window, int camera_disp)
{
	t_plane		*pl;
	t_couple	delta;
	double		l;

	if (!ft_strncmp(window->type, "pl", 3))
	{
		pl = (t_plane *)window->object;
		l = distance(window->scene->camera->pos, pl->pos);
		delta.w = l * (x - window->mouse_position.w);
		delta.w = delta.w * 2 * tan((to_rad(window->scene->camera->fov * 0.5)));
		delta.w = delta.w / camera_disp;
		delta.h = l * (y - window->mouse_position.h);
		delta.h = delta.h * 2 * tan((to_rad(window->scene->camera->fov * 0.5)));
		delta.h = delta.h / camera_disp;
		pl->pos = add_vect(pl->pos, multi_vect(window->scene->camera->b, \
			delta.w));
		pl->pos = add_vect(pl->pos, multi_vect(window->scene->camera->up, \
			delta.h));
	}
}

static void	move_sphere(int x, int y, t_window *window, int camera_disp)
{
	t_sphere	*sp;
	t_couple	delta;
	double		l;

	if (!ft_strncmp(window->type, "sp", 3))
	{
		sp = (t_sphere *)window->object;
		l = distance(window->scene->camera->pos, sp->pos);
		delta.w = l * (x - window->mouse_position.w);
		delta.w = delta.w * 2 * tan((to_rad(window->scene->camera->fov * 0.5)));
		delta.w = delta.w / camera_disp;
		delta.h = l * (y - window->mouse_position.h);
		delta.h = delta.h * 2 * tan((to_rad(window->scene->camera->fov * 0.5)));
		delta.h = delta.h / camera_disp;
		sp->pos = add_vect(sp->pos, multi_vect(window->scene->camera->b, \
			delta.w));
		sp->pos = add_vect(sp->pos, multi_vect(window->scene->camera->up, \
			delta.h));
	}
}

void	ray_mouse(int x, int y, t_window *window)
{
	int	camera_disp;

	camera_disp = window->scene->resolution.w;
	if (camera_disp < window->scene->resolution.h)
		camera_disp = window->scene->resolution.h;
	if (window->object)
	{
		move_sphere(x, y, window, camera_disp);
		move_plane(x, y, window, camera_disp);
		move_cylinder(x, y, window, camera_disp);
	}
}
