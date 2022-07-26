#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_doubles2(char *s, char c)
{
	int i = 0;
	while (s[i])
	{	
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int check_doubles(char *s, char c, int pos)
{
	int i = 0;
	while (i < pos)
	{	
		if (s[i] == c)
			return (1);
		i++;
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
			if (check_doubles(argv[1], argv[1][i], i) == 0)
				ft_putchar(argv[1][i]);
			i++;
		}
		while (argv[2][j])
		{	
			if (check_doubles2(argv[1], argv[2][j]) == 0 && check_doubles(argv[2], argv[2][j], j) == 0)
				ft_putchar(argv[2][j]);
			j++;
		}
	}
	ft_putchar('\n');
	return (0);
}
