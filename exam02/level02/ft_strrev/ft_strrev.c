// #include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_swap_c(char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

char *ft_strrev(char *str)
{
	if (!str)
		return (NULL);
	int i = 0;
	int len = ft_strlen(str) - 1;

	while (len > i)
	{
		ft_swap_c(&str[i], &str[len]);
		i++;
		len--;
	}
	return (str);
}

// int main()
// {
// 	char s[100] = "12345";

// 	printf("%s\n", ft_strrev(s));
// 	return (0);
// }
