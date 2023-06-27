/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:59:18 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 20:36:27 by adashyan         ###   ########.fr       */
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

void	manage_light(const t_scene *scene, t_impact *impact, t_rgb *color)
{
	t_light		light;
	t_ray		to_light;
	void		*obstacle;
	t_impact	*impact_obstacle;
	t_rgb		diffuse;
	t_rgb		color_l;
	double		normal_dot_light;

	diffuse = int_to_rgb(0, 0, 0);
	obstacle = NULL;
	light = *scene->light;
	to_light = new_ray(impact->pos, sub_vect(light.pos, impact->pos));
	impact_obstacle = closest_object(to_light, scene, &obstacle);
	if (impact_obstacle->dist > distance(impact->pos, light.pos))
	{
		normal_dot_light = ft_max_float(dot_product(impact->normal, \
			to_light.dir), 0.0) / (distance(impact->pos, \
			light.pos) * (distance(impact->pos, light.pos)));
		color_l = mult_rgb_double(light.color, normal_dot_light);
		diffuse = add_rgb_rgb(diffuse, color_l);
	}
	free(impact_obstacle->type);
	free(impact_obstacle);
	diffuse = mult_rgb_double(diffuse, ALBEDO);
	*color = mult_rgb_rgb(add_rgb_rgb(scene->al->color, diffuse), *color);
	min_rgb(color);
}

void	*routine(void *thr)
{
	t_impact	*impact;
	t_thread	*thread;
	t_rgb		color;
	t_ray		ray;
	t_couple	limit;
	void		*object;
	double		reflec;
	int			depth;

	thread = (t_thread *)thr;
	reflec = REFLEC;
	object = NULL;
	impact = NULL;
	limit.h = thread->start.h + thread->resolution.h;
	limit.w = thread->start.w + thread->resolution.w;
	while (thread->start.h < limit.h)
	{
		thread->start.w = limit.w - thread->resolution.w;
		while (thread->start.w < limit.w)
		{
			color = int_to_rgb(0, 0, 0);
			depth = DEPTH;
			while (depth-- && reflec > EPSILON)
			{
				ray = generate_ray(*thread->window->scene->camera,
						*thread->window->scene->resolution, thread->start);
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
			}
			ft_put_pixel(thread->window->img->data,
				thread->start, rgb_to_int(color),
				*thread->window->scene->resolution);
			thread->start.w++;
		}
		thread->start.h++;
	}
	return ((void *)0);
}
