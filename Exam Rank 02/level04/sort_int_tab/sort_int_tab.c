// #include <stdio.h>

void ft_swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			if (tab[i + 1] < tab[i])
			{
				ft_swap(&tab[i + 1], &tab[i]);
				i = 0;
			}
			else
				i++;
		}
	}
}

/*
int main()
{
	int tab[] = {10, 3, -7, 1, 5};
	unsigned int size = 5;
	int i = 0;
	sort_int_tab(tab, size);
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
*/
