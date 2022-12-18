#include "fdf.h"

int get_height(char *file)
{
    int     fd;
    int     height;
    char    *line;

    fd = open(file, O_RDONLY);
    height = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        free(line);
        height++;
    }
    close(fd);
    return (height);
}

int get_width(char *file)
{
    int     fd;
    int     width;
    char    *line;

    fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    width = ft_wordcount(line, ' ');
    free(line);
    close(fd);
    return (width);
}

void    fill_map(t_map *map, int fd)
{
    int     i;
    int     j;
    char    *line;
    char    **str;

    i = 0;
    j = 0;
    while (i < map->height)
    {
        line = get_next_line(fd);
        str = ft_split(line, ' ');
        j = 0;
        while (str[j])
        {
            map->z_matrix[i][j] = ft_atoi(str[j]);
            j++;
        }
        free(line);
        i++;
    }
    map->z_matrix[i] = NULL;
    free_str(str);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void    read_map(char *file, t_map *map)
{
    int     i;
    int     fd;
    
    fd = open(file, O_RDONLY);
    map->height = get_height(file);
    map->width = get_width(file);
    map->z_matrix = (int **)malloc(sizeof(int *) * map->height);
    if (!map->z_matrix)
        error("Malloc has failed");
    i = 0;
    while (i < map->height)
    {
        map->z_matrix[i] = (int *)malloc(sizeof(int) * map->width);
        if (!map->z_matrix[i])
            error("Malloc has failed");
        i++;
    }
    fill_map(map, fd);
    close(fd);
}
