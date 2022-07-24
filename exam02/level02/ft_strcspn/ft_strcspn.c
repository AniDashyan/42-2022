
#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(const char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (ft_strlen((char *)s));
	return (0);
}

size_t ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;
	while (s[i] && reject[j])
	{
		return (ft_strchr(s, reject[j]));
		i++;
		j++;
	}
}
