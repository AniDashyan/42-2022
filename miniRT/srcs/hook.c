/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:15:42 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 15:54:45 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	close_function(t_window *w)
{
	mlx_clear_window(w->mlx->mlx_ptr, w->mlx->win_ptr);
	mlx_destroy_window(w->mlx->mlx_ptr, w->mlx->win_ptr);
	free(w->mlx);
	free(w->img);
	free(w->scene->al);
	free(w->scene->camera);
	ft_lstclear(&w->scene->spheres, free);
	ft_lstclear(&w->scene->planes, free);
	ft_lstclear(&w->scene->cylinders, free);
	ft_lstclear(&w->scene->lights, free);
	free(w->scene);
	free(w->type);
	free(w);
	exit(0);
}

int	key_hook(const int keycode, t_window *window)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	if (keycode == ESC || keycode == KEY_Q)
		close_function(window);
	if (increment_light_ratio(keycode, window)
		|| decrement_light_ratio(keycode, window)
		|| camera_move(keycode, window)
		|| camera_rot(keycode, window)
		|| change_sphere_radius(keycode, window)
		|| change_cylinder_radius(keycode, window)
		|| change_cylinder_height(keycode, window)
		|| object_rot(keycode, window))
	{
		make_img(window);
		mlx_ptr = window->mlx->mlx_ptr;
		win_ptr = window->mlx->win_ptr;
		img_ptr = window->img->img_ptr;
		mlx_clear_window(mlx_ptr, win_ptr);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_window *window)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

	if (button != 1)
		return (0);
	ray_mouse(x, y, window);
	make_img(window);
	mlx_ptr = window->mlx->mlx_ptr;
	win_ptr = window->mlx->win_ptr;
	img_ptr = window->img->img_ptr;
	mlx_clear_window(mlx_ptr, win_ptr);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	return (0);
}

int	mouse_fix(int button, int x, int y, t_window *window)
{
	t_impact	*impact;
	t_ray		ray;

	if (button != 1)
		return (0);
	window->mouse_position.w = x;
	window->mouse_position.h = y;
	ray = generate_ray(*window->scene->camera, window->scene->resolution,
			window->mouse_position);
	impact = closest_object(ray, window->scene, &window->object);
	free(window->type);
	window->type = NULL;
	window->type = ft_strdup(impact->type);
	free(impact->type);
	free(impact);
	return (0);
}

void	get_controls_loop(t_window *window)
{
	mlx_hook(window->mlx->win_ptr, 17, 1L << 17,
		close_function, window);
	mlx_hook(window->mlx->win_ptr, 5, 1L << 3, mouse_hook, window);
	mlx_hook(window->mlx->win_ptr, 4, 1L << 2, mouse_fix, window);
	mlx_hook(window->mlx->win_ptr, 2, 1L << 0, key_hook, window);
	mlx_loop(window->mlx->mlx_ptr);
}
