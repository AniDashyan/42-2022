#include "fdf.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		i;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	img.img = mlx_new_image(mlx, 500, 500);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	i = 0;
// 	while (i < 100)
// 	{
// 		my_mlx_pixel_put(&img, i, i, 0x00FF0000 /* hex of ARGB(0,255,0,0) */);
// 		i++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

// x#include "mlx.h"

// int main()
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Pixel");

//     mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);

//     mlx_loop(mlx);
// }