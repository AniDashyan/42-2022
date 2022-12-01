#include <unistd.h>

int ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{	
	int	i = 0;
	if (argc == 2)
	{	
	    while (ft_isspace(argv[1][i]))
			i++;
		while (argv[1][i] && !ft_isspace(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}