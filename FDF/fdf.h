/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:59:07 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/26 20:06:57 by adashyan         ###   ########.fr       */
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

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;

	int		x1;
	int		y1;
	int		z1;
	int		x2;
	int		y2;
	int		z2;
	int		color;
	double	theta;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		shift;
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
int			get_color(int z);
void		my_pixel_put(t_map *map);
void		draw_line(int x, int y, t_map *map, int tmp);
void		print_map(t_map *map);
int			sign(int x);
int			is_file_valid(char *path);
int			create_argb(int a, int r, int g, int b);
int			exit_win(t_map *map, int key);
int			red_cross(t_map *map, int key);
int			keycodes(t_map *map, int key);
void		rotate_x(int *y, int *z, t_map *map);
void		rotate_y(int *x, int *z, t_map *map);
void		rotate_z(int *x, int *y, t_map *map);

#endif