#include <unistd.h>

int ft_isspace(char c)
{
	return ((c >= 9 && c < 13) || c == 32);
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i;
	if (argc == 2)
	{
		i = ft_strlen(argv[1]) - 1;
		while (!ft_isspace(argv[1][i]) && i >= 0)
			i--;
		while (argv[1][i++])
			write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
