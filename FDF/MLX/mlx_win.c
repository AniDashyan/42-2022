#include <mlx.h>

int deal_key(int key)
{
	ft_putchar_fd(key + '0', 1);
	return (0);
}

int main()
{	
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "Helllo MLX!");
	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 247209997);
	// mlx_key_hook(win_ptr, deal_key, 0);
	mlx_loop(mlx_ptr);
	return (0);
}