/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:00:11 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/24 20:00:33 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
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
	map->z_matrix = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (!(map->z_matrix))
		error("Malloc has failed");
	i = 0;
	while (i < map->height)
	{
		map->z_matrix[i] = (int *)malloc(sizeof(int) * (map->width + 1));
		if (!(map->z_matrix[i]))
			error("Malloc has failed");
		i++;
	}
	fill_map(map, fd);
	close(fd);
}
