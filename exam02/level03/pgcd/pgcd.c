#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 1;
	int max = 1;
	int a;
	int b;
	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		while (i <= a && i <= b)
		{
			if (a % i == 0 && b % i == 0)
				max = i;
			i++;
		}
		printf("%d", max);
	}
	printf("\n");
	return (0);
}
