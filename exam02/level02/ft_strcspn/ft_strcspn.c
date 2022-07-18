#include <stdio.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(const char *s1, char c)
{
	int i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (ft_strlen((char *)s1));
	return (0);
}

size_t ft_strcspn(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;
	while (s1[i] && s2[j])
	{
		return (ft_strchr(s1, s2[j]));
		i++;
		j++;
	}
}
