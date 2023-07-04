/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:30:30 by adashyan          #+#    #+#             */
/*   Updated: 2023/07/03 21:00:43 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	set_camera(t_scene *scene, const char *line, char **data)
{
	t_camera	*camera;

	if (!check_line(line, data, "C", NB_ELEM_CAMERA) || scene->camera)
		return (0);
	camera = malloc(sizeof(*camera));
	if (!camera)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	camera->pos = str_to_vect(data[1]);
	camera->orientation = normalize(str_to_vect(data[2]));
	camera->b = normalize(find_b(camera->orientation));
	camera->up = normalize(cross_product(camera->orientation, camera->b));
	if (camera->up.z < -EPSILON)
		camera->up.z = -camera->up.z;
	camera->fov = ft_atof(data[3]);
	if (camera->fov < 0 || camera->fov > 180)
		print_err_and_exit("Camera fov incorrect value\n", PARSE_ERROR);
	scene->camera = camera;
	return (1);
}

int	set_cylinder(t_scene *scene, const char *line, char **data)
{
	t_cylinder	*cy;
	double		radius;

	if (!check_line(line, data, "cy", NB_ELEM_CYLINDER)
		&& !check_line(line, data, "cy", NB_ELEM_CYLINDER + 1))
		return (0);
	cy = malloc(sizeof(*cy));
	if (!cy)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	cy->pos = str_to_vect(data[1]);
	cy->dir = normalize(str_to_vect(data[2]));
	radius = ft_atof(data[3]) / 2;
	cy->radius2 = radius * radius;
	cy->height = ft_atof(data[4]);
	cy->pos2 = add_vect(cy->pos, multi_vect(cy->dir, cy->height));
	cy->color = str_to_rgb(data[5]);
	if (data[6])
		cy->is_closed = ft_atoi(data[6]);
	else
		cy->is_closed = 1;
	ft_lstadd_front(&(scene->cylinders), ft_lstnew(cy));
	return (1);
}

int	set_plane(t_scene *scene, const char *line, char **data)
{
	t_plane		*plane;

	if (!check_line(line, data, "pl", NB_ELEM_PLANE))
		return (0);
	plane = malloc(sizeof(*plane));
	if (!plane)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	plane->pos = str_to_vect(data[1]);
	plane->normal = normalize(str_to_vect(data[2]));
	plane->color = str_to_rgb(data[3]);
	ft_lstadd_front(&(scene->planes), ft_lstnew(plane));
	return (1);
}

int	set_sphere(t_scene *scene, const char *line, char **data)
{
	t_sphere	*sphere;
	double		radius;

	if (!check_line(line, data, "sp", NB_ELEM_SPHERE))
		return (0);
	sphere = malloc(sizeof(*sphere));
	if (!sphere)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	sphere->pos = str_to_vect(data[1]);
	radius = ft_atof(data[2]);
	sphere->radius2 = radius * radius;
	sphere->color = str_to_rgb(data[3]);
	sphere->reflec = 0;
	if (data[4])
		sphere->reflec = ft_atof(data[4]);
	ft_lstadd_front(&(scene->spheres), ft_lstnew(sphere));
	return (1);
}

int	set_light(t_scene *scene, const char *line, char **data)
{
	t_light		*light;

	if (!check_line(line, data, "l", NB_ELEM_LIGHT))
		return (0);
	light = malloc(sizeof(*light));
	if (!light)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	light->pos = str_to_vect(data[1]);
	light->ratio = ft_atof(data[2]) * 255;
	light->color = mult_rgb_double(str_to_rgb(data[3]), light->ratio);
	ft_lstadd_front(&(scene->lights), ft_lstnew(light));
	return (1);
}
