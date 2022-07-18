#include <unistd.h>

void ft_print_hex(unsigned int n)
{
	if (n >= 16)
		ft_print_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

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
	while(ft_isspace(s[i]))
		i++;
	while (s[i] == '-' || s[i] == '+')
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

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
