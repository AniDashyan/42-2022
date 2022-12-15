#include "fdf.h"

int get_height(char *file)
{
    int     fd;
    int     height;

    fd = open(file, O_RDONLY);
    height = 0;
    while (get_next_line(fd))
        height++;
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

// void    fill_map(int *map, char *line)
// {
//     int i;
//     int j;
//     char **nums;

//     i = 0;
//     j = 0;
//     nums = ft_split(line, ' ');
//     while (nums[i])
//     {
//         map[i] = ft_atoi(nums[i]);
//         free(nums[i]);
//         i++;
//     }
//     free(nums);
// }

void    read_map(char *file, t_map *map)
{
    int     i;
    int     fd;
    // char    *line;
    
    map->height = get_height(file);
    map->width = get_width(file);
    map->z_matrix = (int **)malloc(sizeof(int *) * map->height);
    i = 0;
    while (i < map->height)
    {
        map->z_matrix[i] = (int *)malloc(sizeof(int) * map->width);
        i++;
    }
    fd = open(file, O_RDONLY);
    i = 0;
    while (i < map->height)
    {
        ft_printf("%s", get_next_line(fd));
        i++;
    }
    close(fd);
    // map->z_matrix[i] = NULL;
}