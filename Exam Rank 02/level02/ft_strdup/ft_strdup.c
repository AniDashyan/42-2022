
#include <stdlib.h>
// #include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
	int i = 0;
	char *p = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!p)
		return (NULL);
	while(s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

// int main()
// {
// 	char *s = "Hello";
// 	char *dst;

// 	dst = ft_strdup(s);
// 	printf("%s", dst);
// 	return (0);
// }
