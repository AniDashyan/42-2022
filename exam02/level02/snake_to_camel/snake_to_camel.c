#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

char ft_toupper(char c)
{	
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

int main(int argc, char **argv)
{	
	int i = 0;
	if (argc == 2)
	{	
		while (argv[1][i])
		{	
			if (argv[1][i] == '_')
			{
				i++;
				argv[1][i] = ft_toupper(argv[1][i]);
			}
			ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}
