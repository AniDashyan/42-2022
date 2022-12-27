/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:02:25 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/27 18:30:17 by adashyan         ###   ########.fr       */
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

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW
		|| keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		move(map, keycode);
	else if (keycode == PLUS || keycode == MINUS)
		zoom(map, keycode);
	// else if (keycode == X_KEY || keycode == Y_KEY || keycode == Z_KEY)
	// 	rotate(map, keycode);
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
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, WIN_WIDTH,
				WIN_HEIGHT, "FDF");
		map->img_ptr = mlx_new_image(map->mlx_ptr, map->width, map->height);
		// map->img_ptr = mlx_new_image(map->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		map->zoom = 30;
		map->shift_x = WIN_WIDTH / 2;
		map->shift_y = WIN_HEIGHT / 10;
		map->theta = 0.5;
		mlx_hook(map->win_ptr, 17, 1L << 17, red_cross, map);
		draw(map);
		mlx_key_hook(map->win_ptr, key_hook, map);
		// mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
		mlx_loop(map->mlx_ptr);
	}
	else
		ft_putstr_fd("Bad arguments!", 2);
	return (0);
}
