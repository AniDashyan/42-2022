/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:44:50 by adashyan          #+#    #+#             */
/*   Updated: 2023/07/03 20:10:06 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* Used libraries */
# include "../libft/libft.h"
# include <mlx.h>
# include "basics.h"
# include "elements.h"
# include "scene.h"
# include "parse.h"

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
/* ------------- */

# define BUFFER_SIZE 40000
# define RES_W 800
# define RES_H 600
# define N_THREADS 16

/* Error numbers */
# define OPEN_ERROR -1
# define CLOSE_ERROR -2
# define PARSE_ERROR -3
# define MLX_ERROR -4
# define MALLOC_ERROR -5
# define THREAD_ERROR -6
# define VECTOR_ERROR -7
/* ------------- */

# define ALBEDO 0.3
# define EPSILON 1e-4

/*
** Keycodes and screen size LINUX and MAC
*/

# define ESC		53
# define LEFT		123
# define RIGHT		124
# define UP			126
# define DOWN		125
# define KEY_1		83
# define KEY_2		84
# define KEY_4		86
# define KEY_6		88
# define KEY_8		91
# define KEY_9		92
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13
# define KEY_Q		12
# define KEY_E		14
# define KEY_J		38
# define KEY_K		40
# define KEY_X		7
# define KEY_Y		16
# define KEY_Z		6
# define KEY_L		37
# define KEY_I		34
# define KEY_U		32
# define KEY_O		31
# define KEY_F1		122
# define KEY_F2		120
# define KEY_SPACE	49
# define KEY_PLUS	69
# define KEY_MINUS	78

/* Structures */
typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct s_img
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	unsigned char	*data;
}					t_img;

typedef struct s_window
{
	t_mlx		*mlx;
	t_img		*img;
	t_scene		*scene;
	t_couple	mouse_position;
	void		*object;
	char		*type;
}				t_window;

typedef struct s_thread
{
	t_window	*window;
	pthread_t	thread;
	t_couple	resolution;
	t_couple	start;
	t_couple	limit;
}				t_thread;
/* ----------- */

/**
 * libft_utils
**/

int			ft_in_charset(char const c, char const *charset);
long		ft_atol(const char *nptr);
float		ft_atof(const char *str);
int			ft_is_from_charset(const char *str, const char *charset);
int			ft_strncmp_rev(const char *s1, const char *s2, size_t n);
char		**ft_split_set(const char *str, char *charset);
int			ft_min_int(int a, int b);
float		ft_min_float(float a, float b);
float		ft_max_float(const float a, const float b);
void		ft_swap(void *a, void *b);
char		*get_next_line(int fd);

/**
 * parsing
**/
t_scene		*parse(int fd);
/* set objects */
int			set_camera(t_scene *scene, const char *line, char **data);
int			set_light(t_scene *scene, const char *line, char **data);
int			set_sphere(t_scene *scene, const char *line, char **data);
int			set_plane(t_scene *scene, const char *line, char **data);
int			set_cylinder(t_scene *scene, const char *line, char **data);
/* ----------- */

t_rgb		str_to_rgb(const char *str);
t_vect		str_to_vect(const char *str);
t_vect		set_vect(const char *x, const char *y, const char *z);
t_rgb		dev_rgb_double(const t_rgb rgb, const double dev);

/**
 * vectors
**/
int			change_sphere_radius(int keycode, t_window *window);
int			change_cylinder_radius(int keycode, t_window *window);
int			change_cylinder_height(int keycode, t_window *window);
int			camera_move(int keycode, t_window *window);
int			camera_rot(int keycode, t_window *window);
int			object_rot(int keycode, t_window *window);
t_vect		new_vect(const double x, const double y, const double z);
t_vect		normalize(const t_vect vect);
t_vect		rot_vect(const t_vect vect, const double radian, const char axe);
t_vect		mult_mat(const double mat[3][3], t_vect vect);
double		dot_product(const t_vect vect1, const t_vect vect2);
t_vect		add_vect(const t_vect vect1, const t_vect vect2);
t_vect		sub_vect(const t_vect vect1, const t_vect vect2);
t_vect		minus_vect(const t_vect vect);
t_vect		multi_vect(const t_vect vect, const double x);
t_vect		cross_product(const t_vect v1, const t_vect v2);

t_vect		set_vect_dir_cam(const t_camera camera, const t_couple resolution,
				const int i, const int j);
/* ray objects */
void		ray_cylinders(const t_ray ray, const t_scene *scene,
				t_impact *impact, void **object);
void		ray_planes(const t_ray ray, const t_scene *scene,
				t_impact *impact, void **object);
void		ray_spheres(const t_ray ray, const t_scene *scene,
				t_impact *impact, void **object);
/* ----------- */

double		to_rad(const double angle);

void		make_img(t_window *window);
void		ft_put_pixel(unsigned char *data, t_couple pixel, int color);

void		print_err_and_exit(char *str, const int err);

double		distance(const t_vect p1, const t_vect p2);
int			solve_quadratic(const t_vect point, double *x0, double *x1);

double		cy_intersection(t_ray ray, const t_cylinder cylinder);
void		*routine(void *thr);
void		ray_mouse(int x, int y, t_window *window);
t_impact	*closest_object(const t_ray ray, const t_scene *scene,
				void **object);
t_ray		generate_ray(const t_camera camera, const t_couple resolution,
				t_couple pixel);
t_vect		get_closest_point_from_line(t_vect a, t_vect b, t_vect p);
double		solve_plane(t_vect o, t_vect d, t_vect plane_p, t_vect plane_nv);
t_vect		find_b(t_vect orient);
void		clear_matrix(char **data);
int			check_resolution(char **data);
int			check_line(const char *line, char **data, const char *type,
				const int nb_elements);
void		get_controls_loop(t_window *window);

/* manage light ratio */
int			decrement_light_ratio(const int keycode, t_window *w);
int			increment_light_ratio(const int keycode, t_window *w);
/* ------------------ */

/* zoom  */ /* zoom.c */
int			zoom_in(const int keycode, t_window *w);
int			zoom_out(const int keycode, t_window *w);
/* ---- */

/* move objects */ /* move.c */
int			move_up(const int keycode, t_window *w);
int			move_down(const int keycode, t_window *w);
int			move_left(const int keycode, t_window *w);
int			move_right(const int keycode, t_window *w);
/* ------------ */

/* rotate objects */ /* rotate_xyz.c, rotate_dir.c */
int			rot_left(const int keycode, t_window *w);
int			rot_right(const int keycode, t_window *w);
int			rot_center_left(const int keycode, t_window *w);
int			rot_center_right(const int keycode, t_window *w);
int			rot_up(const int keycode, t_window *w);
int			rot_down(const int keycode, t_window *w);
int			rot_x(const int keycode, t_window *w);
int			rot_y(const int keycode, t_window *w);
int			rot_z(const int keycode, t_window *w);
/* ------------- */

int			ft_tab_size(char **tab);

#endif
