#include <stdio.h>
#include <stdlib.h>

int ft_isdigit(char c)
{
	return(c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (num * sign > 2147483647)
			return (-1);
		else if (num * sign < -2147483648)
			return (0);
		i++;
	}
	return (num * sign);
}

int main()
{
	char *str = "--1567";
	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	return (0);
}
