#include <unistd.h>

int		ft_atoi(char *str)
{
	int n = 0;

	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	return (n);
}

void	ft_write_number(int number)
{
	if (number > 9)
		ft_write_number(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

int ft_isprime(int n)
{	
	if (n <= 0 || n == 1)
		return (0);
	int i = 2;
	while (i <= n/2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{	
	int i = 2;
	int sum = 0;
	if (argc == 2)
	{
		if (ft_atoi(argv[1]) <= 0)
			write(1, "0\n", 2);
		while (i <= ft_atoi(argv[1]))
		{
			if (ft_isprime(i))
				sum += i;	
			i++;
		}
		ft_write_number(sum);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
