/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:23:23 by adashyan          #+#    #+#             */
/*   Updated: 2023/06/30 13:21:11 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_img	*init_img(t_mlx *mlx, t_couple *resolution)
{
	t_img		*img;

	img = malloc(sizeof(*img));
	if (!img)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, resolution->w, resolution->h);
	if (!(img->img_ptr))
		print_err_and_exit("Minilibx error", MLX_ERROR);
	img->data = (unsigned char *)mlx_get_data_addr(img->img_ptr,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	if (!(img->data))
		print_err_and_exit("Minilibx error", MLX_ERROR);
	return (img);
}

t_mlx	*init_mlx(void)
{
	t_mlx		*mlx;

	mlx = malloc(sizeof(*mlx));
	if (!mlx)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	mlx->mlx_ptr = mlx_init();
	if (!(mlx->mlx_ptr))
		print_err_and_exit("Minilibx error", MLX_ERROR);
	return (mlx);
}

t_scene	*get_scene(const int argc, char *argv[])
{
	int			fd;
	t_scene		*scene;

	if (argc < 2)
		print_err_and_exit("Error: expecting a '.rt'file", 1);
	if (argc > 2)
		print_err_and_exit("Error: expecting a 2 arguments maximum", 1);
	if (ft_strncmp_rev(argv[1], ".rt", 3))
		print_err_and_exit("First argument must be a '.rt' file", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_err_and_exit(strerror(errno), errno);
	scene = parse(fd);
	if (!scene)
		print_err_and_exit("Parsing error", PARSE_ERROR);
	if (close(fd) == -1)
		print_err_and_exit(strerror(errno), errno);
	return (scene);
}

t_window	*init_window(int argc, char **argv)
{
	t_window	*window;
	char		*title_window;
	void		*mlx_ptr;
	int			x;
	int			y;

	window = (t_window *)malloc(sizeof(t_window));
	if (!window)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	window->scene = get_scene(argc, argv);
	window->mlx = init_mlx();
	window->img = init_img(window->mlx, &window->scene->resolution);
	window->object = NULL;
	window->type = NULL;
	title_window = ft_strjoin("miniRT - ", argv[1]);
	mlx_ptr = window->mlx->mlx_ptr;
	x = window->scene->resolution.w;
	y = window->scene->resolution.h;
	window->mlx->win_ptr = mlx_new_window(mlx_ptr, x, y, title_window);
	free(title_window);
	if (!window->mlx->win_ptr)
		print_err_and_exit("Minilibx error", MLX_ERROR);
	return (window);
}

int	main(const int argc, char *argv[])
{
	t_window	*window;
	clock_t		start;
	clock_t		end;

	start = clock();
	window = init_window(argc, argv);
	make_img(window);
	end = clock();
	printf("make_img:\t%fs\n", ((double)(end - start)) / CLOCKS_PER_SEC);
	if (argc == 2)
	{
		mlx_put_image_to_window(window->mlx->mlx_ptr,
			window->mlx->win_ptr, window->img->img_ptr, 0, 0);
		get_controls_loop(window);
	}
	return (0);
}
