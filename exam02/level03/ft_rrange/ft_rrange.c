#include <stdio.h>
//#include <stdlib.h>

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int *ft_rrange(int start, int end)
{
	int i = 0;
	int len = ft_abs(end - start);
	int *s = (int *)malloc(sizeof(int) * len);
	if (!s)
		return (NULL);
	if (start > end)
	{
		while (len-- >= 0)
			s[i++] = end++;
	}
	else
	{
		while (len-- >= 0)
			s[i++] = end--;
	}
	return (s);
}

/*
int main()
{
	int i = 0;
	int start;
	int end;

	start = 0;
	end = -3;
	int *array;
	int size = ft_abs(end - start);
	array = ft_rrange(start, end);
	while (size >= 0)
	{
		printf("%d\n", array[i]);
		i++;
		size--;
	}
}
*/
