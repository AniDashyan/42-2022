#include <unistd.h>

int check_doubles(char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

int check_doubles2(char *s, char c, int pos)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!check_doubles2(argv[1], argv[1][i], i))
					write(1, &argv[1][i], 1);
			i++;
		}

		while (argv[2][j])
		{
			if (!check_doubles(argv[1], argv[2][j]) && !check_doubles2(argv[2], argv[2][j], j))
				write(1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
