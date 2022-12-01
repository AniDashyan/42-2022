#include <stdlib.h>
// #include <stdio.h>

int num_len(int n)
{
	int i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char *ft_itoa(int n)
{
	int len = num_len(n);
	int i = 0;
	int nbr = ft_abs(n);
	char *num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len--] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
		num[0] = '-';
	while(nbr > 0)
	{
		num[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (num);
}

/* int main()
{
	int n = -4123;
	// printf("%d\n", num_len(n));
	printf("%s\n", ft_itoa(n));
	return (0);
} */
