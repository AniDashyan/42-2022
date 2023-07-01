/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:59:18 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 11:53:47 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_impact	*closest_object(const t_ray ray, \
	const t_scene *scene, void **object)
{
	t_impact	*impact;

	impact = malloc(sizeof(*impact));
	if (!impact)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	impact->type = malloc(3 * sizeof(char));
	if (!(impact->type))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	ft_bzero(impact->type, 3);
	impact->dist = INFINITY;
	ray_spheres(ray, scene, impact, object);
	ray_planes(ray, scene, impact, object);
	ray_cylinders(ray, scene, impact, object);
	if (!*impact->type)
		*object = NULL;
	return (impact);
}

static void	man_li(const t_scene *scene, t_rgb *diffuse,
		t_impact *impact, t_light *light)
{
	t_ray		to_light;
	t_impact	*impact_obstacle;
	void		*obstacle;
	double		normal_dot_light;

	obstacle = NULL;
	to_light = new_ray(impact->pos, sub_vect(light->pos, impact->pos));
	impact_obstacle = closest_object(to_light, scene, &obstacle);
	if (impact_obstacle->dist > distance(impact->pos, light->pos))
	{
		normal_dot_light = ft_max_float(dot_product(impact->normal, \
			to_light.dir), 0.0) / (distance(impact->pos, \
			light->pos) * (distance(impact->pos, light->pos)));
		*diffuse = add_rgb_rgb(*diffuse, \
			mult_rgb_double(light->color, normal_dot_light));
	}
	free(impact_obstacle->type);
	free(impact_obstacle);
}

void	manage_light(const t_scene *scene, t_impact *impact, t_rgb *color)
{
	t_rgb		diffuse;
	t_list		*lights;
	t_light		*light;

	lights = scene->lights;
	diffuse = int_to_rgb(0, 0, 0);
	while (lights->next)
	{
		light = (t_light *)lights->content;
		man_li(scene, &diffuse, impact, light);
		lights = lights->next;
	}
	diffuse = mult_rgb_double(diffuse, ALBEDO);
	*color = mult_rgb_rgb(add_rgb_rgb(scene->al->color, diffuse), *color);
	min_rgb(color);
}

static void	rout(t_thread *thread)
{
	t_impact	*impact;
	t_rgb		color;
	t_ray		ray;
	void		*object;

	color = int_to_rgb(0, 0, 0);
	ray = generate_ray(*thread->window->scene->camera,
			thread->window->scene->resolution, thread->start);
	impact = closest_object(ray, thread->window->scene, &object);
	if (object)
	{
		color = get_color(impact->type, object);
		if (dot_product(impact->normal, ray.dir) >= 0)
			impact->normal = minus_vect(impact->normal);
		manage_light(thread->window->scene, impact, &color);
	}
	free(impact->type);
	free(impact);
	ft_put_pixel(thread->window->img->data,
		thread->start, rgb_to_int(color));
}

void	*routine(void *thr)
{
	t_thread	*thread;

	thread = (t_thread *)thr;
	thread->limit.h = thread->start.h + thread->resolution.h;
	thread->limit.w = thread->start.w + thread->resolution.w;
	while (thread->start.h < thread->limit.h)
	{
		thread->start.w = thread->limit.w - thread->resolution.w;
		while (thread->start.w < thread->limit.w)
		{
			rout(thread);
			thread->start.w++;
		}
		thread->start.h++;
	}
	return ((void *)0);
}
