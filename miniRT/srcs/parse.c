/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:21:21 by adashyan          #+#    #+#             */
/*   Updated: 2023/07/03 20:28:31 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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

static int	set_objects(t_scene *scene, const char *line, char **data)
{
	if (set_ambient_light(scene, line, data)
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
	scene->resolution.w = RES_W;
	scene->resolution.h = RES_H;
	scene->al = NULL;
	scene->camera = NULL;
	scene->lights = ft_lstnew(NULL);
	scene->spheres = ft_lstnew(NULL);
	scene->planes = ft_lstnew(NULL);
	scene->cylinders = ft_lstnew(NULL);
	return (scene);
}

int	read_and_check(t_scene *scene, char **data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL || !*line || *line == '\n')
		return (0);
	while (line && *line)
	{
		data = ft_split_set(line, WHITE_SPACES);
		if (set_objects(scene, line, data))
			;
		else if (!ft_is_from_charset(line, WHITE_SPACES))
		{
			free(line);
			clear_matrix(data);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		clear_matrix(data);
	}
	free(line);
	return (1);
}

t_scene	*parse(int fd)
{
	t_scene	*scene;
	char	**data;

	data = NULL;
	scene = malloc(sizeof(*scene));
	if (!scene)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	if (!(init_scene(scene)))
		return (NULL);
	if (read_and_check(scene, data, fd) == 0)
		return (NULL);
	return (scene);
}
