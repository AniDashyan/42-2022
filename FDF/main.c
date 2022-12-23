/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adashyan <adashyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:02:25 by adashyan          #+#    #+#             */
/*   Updated: 2022/12/23 19:47:23 by adashyan         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	*map;	

	if (argc == 2)
	{
		map = (t_map *)malloc(sizeof(t_map));
		(void)argc;
		(void)argv;
		read_map(argv[1], map);
		print_map(map);
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, 1920, 1080, "FDF");
		// bresenham(10, 10, 600, 300, map);
		map->zoom = 20;
		draw(map);
		mlx_loop(map->mlx_ptr);
	}
	else
		ft_putstr_fd("Bad arguments!", 2);
	return (0);
}
