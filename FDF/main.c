#include "fdf.h"

int main(int argc, char **argv)
{	
	int	fd;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR | 0677);
		ft_printf("hello %d\n", fd);
	}
	else
		ft_putstr_fd("Bad arguments!", 2);
	return (0);
}