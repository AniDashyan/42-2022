#include <unistd.h>

int ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(char *s)
{
	int i = 0;
	int num = 0;
	int sign = 1;

	while (ft_isspace(s[i]))
		i++;
	while(s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	while (ft_isdigit(s[i]))
	{
		num = num * 10 + (s[i] - '0') % 10;
		i++;
	}
	return (num * sign);
}

void write_number(int n)
{
	if (n > 9)
		write_number(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int main(int argc, char **argv)
{
	int s;
	int i = 1;
	if (argc == 2)
	{
		s = ft_atoi(argv[1]);
		while (i <= 9)
		{
			write_number(i);
			write(1, " x ", 3);
			write_number(s);
			write(1, " = ", 3);
			write_number(i * s);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
