#include "fdf.h"

int main(int argc, char **argv)
{	
	t_map	*map;
	// int		i;
	// int		j;
	if (argc == 2)
	{
		map = (t_map *)malloc(sizeof(t_map));
		(void)argc;
		(void)argv;
		read_map(argv[1], map);
		// i = 0;
		// j = 0;
		// while (i < map->height)
		// {
		// 	while (j < map->width)
		// 	{
		// 		ft_printf("%d ", map->z_matrix[i][j]);
		// 		j++;
		// 	}
		// 	ft_printf("\n");
		// 	i++;
		// }
	}
	else
		ft_putstr_fd("Bad arguments!", 2);
	return (0);
}