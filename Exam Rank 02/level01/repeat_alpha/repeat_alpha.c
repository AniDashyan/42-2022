#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_islower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int ft_isupper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char ft_repeat_alpha(char *str)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		if (ft_isupper(str[i]))
		{
			j = str[i] - 'A';
			while (j >= 0)
			{
				ft_putchar(str[i]);
				j--;
			}
		}
		else if (ft_islower(str[i]))
		{
			j = str[i] - 'a';
			while (j >= 0)
			{
				ft_putchar(str[i]);
				j--;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
	return (*str);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_repeat_alpha(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
