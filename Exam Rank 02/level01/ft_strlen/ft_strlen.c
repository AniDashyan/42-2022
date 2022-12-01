#include <stdio.h>
#include <string.h>

size_t ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int main()
{	
	char *str = "hello";
	printf("%zu\n", ft_strlen(str));
	printf("%zu\n", strlen(str));
	return (0);
}