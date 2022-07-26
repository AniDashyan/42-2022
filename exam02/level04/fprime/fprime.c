#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void fprime(char *str)
{
	int n = atoi(str);
	int factor = 2;
	int first = 1;

	if (n == 1)
		printf("1");

	while (factor <= n)
	{
		if (n % factor == 0 && ft_isprime(factor))
		{
			if (first == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			first = 0;
			n = n / factor;
		}
		else
			++factor;
	}
}

int main(int argc, char **argv)
{
	int i = 2;
	int n;
	int flag = 1;
	if (argc == 2)
		fprime(argv[1]);
	printf("\n");
	return (0);
}
