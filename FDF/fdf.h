#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef struct  s_map
{
    int     width;
    int     height;
    int     **z_matrix;

    void    *mlx_ptr;
    void    *win_ptr;
} t_map;

void    read_map(char *file, t_map *map);
int     get_height(char *file);
int     get_width(char *file);

#endif