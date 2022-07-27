#include <unistd.h>
#include <stdio.h>

<<<<<<< HEAD
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
=======
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_doubles2(char *s, char c)
>>>>>>> 29d187824de552b46f0b2c7853569130ee4c15ff
{
	int i = 0;
	while (s[i])
	{	
		if (s[i] == c)
			return (1);
<<<<<<< HEAD
	}
	return (0);
=======
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
>>>>>>> 29d187824de552b46f0b2c7853569130ee4c15ff
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
<<<<<<< HEAD
		{
			if (!check_doubles2(argv[1], argv[1][i], i))
					write(1, &argv[1][i], 1);
			i++;
		}

		while (argv[2][j])
		{
			if (!check_doubles(argv[1], argv[2][j]) && !check_doubles2(argv[2], argv[2][j], j))
				write(1, &argv[2][j], 1);
=======
		{	
			if (check_doubles(argv[1], argv[1][i], i) == 0)
				ft_putchar(argv[1][i]);
			i++;
		}
		while (argv[2][j])
		{	
			if (check_doubles2(argv[1], argv[2][j]) == 0 && check_doubles(argv[2], argv[2][j], j) == 0)
				ft_putchar(argv[2][j]);
>>>>>>> 29d187824de552b46f0b2c7853569130ee4c15ff
			j++;
		}
	}
	ft_putchar('\n');
	return (0);
}
