#include <unistd.h>

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{	
		write(1, &s[i], 1);
		i++;
	}
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
	int i = 0;
	int j = 0;
	int wdlen = 0;
	int len;
	if (argc == 3)
	{	
		len = ft_strlen(argv[1]);
		while (argv[1][i])
		{	
			while (argv[2][j])
			{	
				if (argv[1][i] == argv[2][j])
				{
					wdlen++;
					break;
				}
				j++;
			}
			i++;
		}
		if (wdlen == len)
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
