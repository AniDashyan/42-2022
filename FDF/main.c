#include "fdf.h"

int main(int argc, char **argv)
{	
	t_map	*map;
	// void	*img_ptr;
	if (argc == 2)
	{
		map = (t_map *)malloc(sizeof(t_map));
		(void)argc;
		(void)argv;
		read_map(argv[1], map);
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, 640, 360, "FDF");
		// img_ptr = mlx_new_image(map->mlx_ptr, map->width, map->height);
		// mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, img_ptr, 500, 500);
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, 640/2, 360/2, 0xFFFFFF);
		mlx_loop(map->mlx_ptr);
	}
	else
		ft_putstr_fd("Bad arguments!", 2);
	return (0);
}
