#include <unistd.h>

int ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int ft_islower(char c)
{
	return ((c >= 'a' && c <= 'z'));
}

int ft_isupper(char c)
{
	return ((c >= 'A' && c <= 'Z'));
}

char ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void str_capitalizer(char *str)
{
	int i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
		{
			write(1, &str[i], 1);
			i++;
		}

		if (str[i])
		{
			if (ft_islower(str[i]))
				str[i] = ft_toupper(str[i]);
			write(1, &str[i], 1);
			i++;
		}

		while (str[i] && !ft_isspace(str[i]))
		{
			if (ft_isupper(str[i]) && !ft_isspace(str[i + 1]))
				str[i] = ft_tolower(str[i]);
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
