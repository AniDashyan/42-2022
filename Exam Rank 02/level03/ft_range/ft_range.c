#include <stdlib.h>
#include <stdio.h>

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int *ft_range(int start, int end)
{
	int i = 0;
	int len = ft_abs(end - start);
	int *s = (int *)malloc(sizeof(int) * len);
	if (!s)
		return (NULL);
	if (start > end)
	{
		while (len-- >= 0)
			s[i++] = start--;
	}
	else
	{
		while (len-- >= 0)
			s[i++] = start++;
	}
	return (s);
}

int main()
{
	int start;
	int end;

	start = -3;
	end = 0;
	int *array;
	int size = ft_abs(end - start);
	array = ft_range(start, end);
	int i = 0;
	while (size >= 0)
	{
		printf("%d\n", array[i]);
		i++;
		size--;
	}
}