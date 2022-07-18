#include <stddef.h>
#include <stdio.h>
#include <string.h>

int		find_char(const char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		++str;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (find_char(*s1, s2) == 1)
			return ((char *)s1);
		++s1;
	}
	return (0);
}

/*
int main()
{
    // Declaring three strings
    char s1[] = "geeksforgeeks";
    char s2[] = "app";
    char s3[] = "kite";
    char* r, *t;

    // Checks for matching character
    // no match found
    r = ft_strpbrk(s1, s2);
    if (r != 0)
        printf("First matching character: %c\n", *r);
    else
        printf("Character not found");

    // Checks for matching character
    // first match found at "e"
    t = ft_strpbrk(s1, s3);
    if (t != 0)
        printf("\nFirst matching character: %c\n", *t);
    else
        printf("Character not found");

    return (0);
}
*/
