#include <stdlib.h>

int ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int ft_wordcount(char *s)
{
	int i;
	int flag;
	int k;

	i = 0;
	flag = 1;
	k = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			flag = 1;
		else if (flag)
		{
			k++;
			if (s[i] != '\0' && !ft_isspace(s[i]))
				flag = 0;
		}
		i++;
	}
	return (k);
}

int ft_wordlen(char const *s, int i)
{
	int len;

	len = 0;
	while (s[i] && !ft_isspace(s[i]))
	{
		i++;
		len++;
	}
	return (len);
}

char *ft_strdup2(char *s, int len, int *i)
{
	char *ptr;
	int j;

	j = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[*i] && !ft_isspace(s[*i]))
	{
		ptr[j] = s[*i];
		j++;
		*i += 1;
	}
	ptr[j] = '\0';
	return (ptr);
}

char **ft_split(char *s)
{
	char **splitted;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * (ft_wordcount(s) + 1));
	if (!splitted)
		return (NULL);
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			splitted[j] = ft_strdup2(s, ft_wordlen(s, i) + 1, &i);
			j++;
		}
		if (!s[i])
			break;
		i++;
	}
	splitted[j] = NULL;
	return (splitted);
}

/* int main()
{
	char *s = "Hello darkness my old friend";
	char **new = ft_split(s);
	int i = 0;
	while (new[i])
	{
		printf("%s\n", new[i]);
		i++;
	}
	return (0);
} */
