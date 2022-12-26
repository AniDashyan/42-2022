/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:02:25 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/26 20:25:35 by adashyan         ###   ########.fr       */
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

int	keycodes(t_map *map, int key)
{
	(void)map;
	if (key == 53)
	{
		printf("%d\n", key);
		// mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		// red_cross(map, key);
	}
	if (key == 7)
		printf("%d\n", key);
		// rotate_x(&map->y1, &map->z1, map);
	else if (key == 16)
		printf("%d\n", key);
		// rotate_y(&map->y1, &map->z1, map);
	else if (key == 6)
		printf("%d\n", key);
		// rotate_z(&map->x1, &map->y1, map);
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
		// map->img_ptr = mlx_new_image(map->mlx_ptr, map->width, map->height);
		map->zoom = 30;
		map->shift = WIN_WIDTH / 2;
		// mlx_hook(map->win_ptr, 02, 1L << 0, exit_win, map);
		mlx_hook(map->win_ptr, 17, 1L << 5, red_cross, map);
		printf("barev\n");
 		draw(map);
		// mlx_hook(map->mlx_ptr, map->win_ptr, keycodes, &map);
		mlx_hook(map->win_ptr, 2, 1L << 0, keycodes, map);
		mlx_loop(map->mlx_ptr);
	}
	else
		ft_putstr_fd("Bad arguments!", 2);
	return (0);
}
