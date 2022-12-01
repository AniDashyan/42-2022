#include <unistd.h>

int ft_isspace(char c)
{
	return ((c >= 9 && c < 13) || c == 32);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 2)
	{
		while (ft_isspace(av[1][i]))
			i++;
		while (av[1][i])
		{
			if (ft_isspace(av[1][i]))
			{
				if (av[1][i + 1] > 32 && av[1][i + 1])
					write(1, "   ", 3);
			}
			else if (!ft_isspace(av[1][i]))
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
