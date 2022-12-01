#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int i = 0;
	if (!tab)
		return (0);
	int max = tab[0];
	while (len)
	{	
		if (tab[i] > max)
			max = tab[i];
		i++;
		len--;
	}
	return (max);
}

/*
int main()
{	
	int tab[] = {10, 2, 3, 4, 5};
	printf("%d\n", max(tab, 5));
	return (0);
}
*/
