/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:59:07 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 18:44:22 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_HEIGHT 1920
# define WIN_WIDTH 1080

# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define ESC 53
# define PLUS 69
# define MINUS 78
# define X_KEY 7
# define Y_KEY 16

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color;
	int		zoom;

	int		x1;
	int		y1;
	int		z1;
	int		x2;
	int		y2;
	int		z2;
	double	theta;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		pixel;

	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_map;

void		read_map(char *file, t_map *map);
int			get_height(char *file);
int			get_width(char *file);
char		*get_next_line(int fd);
char		*ft_strjoin_gnl(char *s1, char c);
void		free_str(char **str);
void		error(char *err_msg);
char		**num_color_split(char *str);
void		bresenham(t_map *map);
void		draw(t_map *map);
void		get_color(t_map *map, int x, int y);
void		draw_line(int x, int y, t_map *map, int tmp);
void		print_map(t_map *map);
int			sign(int x);
int			is_file_valid(char *path);
int			red_cross(t_map *map, int key);
void		move(t_map *map, int key);
void		zoom(t_map *map, int key);
void		rotate_x(t_map *map);
void   		my_pixel_put(t_map *map);

#endif