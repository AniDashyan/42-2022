#include <stdio.h>
#include <stdlib.h>

int ft_isprime(int n)
{
	int i = 2;
	if (n == 0 || n == 1)
		return (0);
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
	int n;
	int flag = 1;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		if (n == 1)
			printf("1");
		while (n != 1)
		{
			if (n % i == 0 && ft_isprime(i))
			{
				if (flag == 1)
					printf("%d", i);
				else
					printf("*%d", i);
				flag = 0;
				n /= i;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
