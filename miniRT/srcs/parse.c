/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:21:21 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/27 20:37:54 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	set_ambient_light(t_scene *scene, const char *line, char **data)
{
	t_ambient_light	*ambient_light;
	double			ratio;

	if (!check_line(line, data, "A", NB_ELEM_AL) || scene->al)
		return (0);
	ambient_light = malloc(sizeof(*ambient_light));
	if (!ambient_light)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	ratio = ft_atof(data[1]);
	ambient_light->color = mult_rgb_double(str_to_rgb(data[2]), ratio);
	ambient_light->ratio = ratio;
	scene->al = ambient_light;
	return (1);
}

static int	set_resolution(t_scene *scene, const char *line, char **data)
{
	t_couple	*resolution;

	if (!check_line(line, data, "R", NB_ELEM_RESOLUTION) || scene->resolution)
		return (0);
	if (check_resolution(data))
		print_err_and_exit("resolution (R) must be 2 positive numbers", 20);
	resolution = malloc(sizeof(*resolution));
	if (!resolution)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	resolution->w = ft_atoi_strict(data[1]);
	resolution->h = ft_atoi_strict(data[2]);
	scene->resolution = resolution;
	return (1);
}

static int	set_objects(t_scene *scene, const char *line, char **data)
{
	if (set_resolution(scene, line, data)
		|| set_ambient_light(scene, line, data)
		|| set_camera(scene, line, data)
		|| set_light(scene, line, data)
		|| set_sphere(scene, line, data)
		|| set_plane(scene, line, data)
		|| set_cylinder(scene, line, data))
		return (1);
	return (0);
}

static void	*init_scene(t_scene *scene)
{
	scene->resolution = NULL;
	scene->al = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->spheres = ft_lstnew(NULL);
	scene->planes = ft_lstnew(NULL);
	scene->cylinders = ft_lstnew(NULL);
	return (scene);
}

t_scene	*parse(int fd)
{
	t_scene	*scene;
	char	*line;
	char	**data;

	scene = malloc(sizeof(*scene));
	if (!scene)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	if (!(init_scene(scene)))
		return (NULL);
	while (get_next_line(&line, fd) == 1)
	{
		data = ft_split_set(line, WHITE_SPACES);
		if (set_objects(scene, line, data))
			;
		else if (!ft_is_from_charset(line, WHITE_SPACES))
		{
			free(line);
			clear_matrix(data);
			return (NULL);
		}
		free(line);
		clear_matrix(data);
	}
	free(line);
	return (scene);
}
