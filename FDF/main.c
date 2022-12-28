/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:02:25 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/28 22:05:56 by adashyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d", map->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		error("Error: MLX not connected!");
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "FDF");
	if (map->win_ptr == NULL)
	{
		free(map->win_ptr);
		error("Error: Can't create window!");
	}
	map->img.img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (map->img.img_ptr == NULL)
		error("Error: can't create image!");
	map->img.addr = mlx_get_data_addr(map->img.img_ptr,
			&map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
	map->zoom = 30;
	map->shift_x = WIN_WIDTH / 2;
	map->shift_y = WIN_HEIGHT / 10;
	map->theta = 0.5;
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == UP_ARROW || keycode == DOWN_ARROW
		|| keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		move(map, keycode);
	if (keycode == PLUS || keycode == MINUS)
		zoom(map, keycode);
	if (keycode == X_KEY || keycode == Y_KEY)
		rotate(map, keycode);
	// mlx_destroy_image(map->mlx_ptr, map->img.img_ptr);
	draw(map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;	

	if (argc == 2)
	{	
		if (is_file_valid(argv[1]) == 0)
			error("Error: file extension is not valid");
		map = (t_map *)malloc(sizeof(t_map));
		read_map(argv[1], map);
		print_map(map);
		init(map);
		draw(map);
		mlx_hook(map->win_ptr, 17, 1L << 17, red_cross, map);
		mlx_key_hook(map->win_ptr, key_hook, map);
		mlx_loop(map->mlx_ptr);
	}
	else
		error("Bad arguments!");
	return (0);
}
