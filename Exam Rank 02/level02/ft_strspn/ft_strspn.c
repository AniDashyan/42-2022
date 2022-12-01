#include <stdio.h>
#include <string.h>

int ft_strchr(char *s, char c)
{
	int i = 0;
	while(s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	while (s[i])
	{
		if (ft_strchr((char *)accept, s[i]) == 0)
			break;
		i++;
	}
	return (i);
}


int main () {
   int len1, len2;
   const char str1[] = "ABCDEFG019874";
   const char str2[] = "ABCD";

   len1 = strspn(str1, str2);
   len2 = ft_strspn(str1, str2);

   printf("Length of initial segment matching %d\n", len1);
   printf("Length of initial segment matching %d\n", len2);
   return(0);
} 
