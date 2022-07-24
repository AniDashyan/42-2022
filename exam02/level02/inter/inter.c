#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
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
		while(argv[1][i])
		{	
			while (argv[2][j])
			{	
				if (argv[1][i] == argv[2][j])
				{
					if (check_doubles(argv[1], argv[1][i], i) == 0)
					{
						ft_putchar(argv[1][i]);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}