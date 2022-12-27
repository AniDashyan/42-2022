/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:00:11 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 18:43:43 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error: open has failed");
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error: open has failed");
	line = get_next_line(fd);
	width = ft_wordcount(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_map(t_map *map, int fd)
{
	int		i;
	int		j;
	char	**str;
	char	**num;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		str = ft_split(get_next_line(fd), ' ');
		j = 0;
		while (str[j])
		{
			num = num_color_split(str[j]);
			map->z_matrix[i][j] = ft_atoi(num[0]);
			map->color[i][j] = num[1];
			j++;
		}
		free_str(num);
		i++;
	}
	free_str(str);
	map->z_matrix[i] = NULL;
}

void	read_map(char *file, t_map *map)
{
	int	i;
	int	fd;

	fd = open(file, O_RDONLY);
	map->height = get_height(file);
	map->width = get_width(file);
	if (map->height <= 0 || map->width <= 0)
		error("Error: no values");
	map->z_matrix = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (!(map->z_matrix))
		error("Error: malloc has failed");
	i = 0;
	while (i < map->height)
	{
		map->z_matrix[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		if (!(map->z_matrix[i]))
			error("Error: malloc has failed");
		i++;
	}
	fill_map(map, fd);
	close(fd);
}
