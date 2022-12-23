/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:59:07 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/23 18:12:08 by adashyan         ###   ########.fr       */
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

	float	x;
	float	y;
	int		color;

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
void		bresenham(float x1, float y1, float x2, float y2, t_map *map);
void		draw(t_map *map);

#endif