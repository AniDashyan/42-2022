#include <unistd.h>

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
<<<<<<< HEAD
	{
		write(1, &s[i], 1);
		i++;
	}

=======
	{	
		write(1, &s[i], 1);
		i++;
	}
>>>>>>> 29d187824de552b46f0b2c7853569130ee4c15ff
}

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
<<<<<<< HEAD
{
	int i = 0;
	int j = 0;
	int k = 0;
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
					k++;
=======
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
>>>>>>> 29d187824de552b46f0b2c7853569130ee4c15ff
					break;
				}
				j++;
			}
<<<<<<< HEAD
			if (k == len)
				ft_putstr(argv[1]);
			i++;
		}
=======
			i++;
		}
		if (wdlen == len)
			ft_putstr(argv[1]);
>>>>>>> 29d187824de552b46f0b2c7853569130ee4c15ff
	}
	write(1, "\n", 1);
	return (0);
}
<<<<<<< HEAD

=======
>>>>>>> 29d187824de552b46f0b2c7853569130ee4c15ff
