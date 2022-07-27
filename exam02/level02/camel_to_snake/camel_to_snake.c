#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     ft_isUpper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int     ft_toLower(int c)
{
    if (ft_isUpper(c))
        return (c + 32);
    return (c);
}

int     main(int argc, char **argv)
{	
	int i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
    	{
        	if (ft_isUpper(argv[1][i]))
            	ft_putchar('_');
        	ft_putchar(ft_toLower(argv[1][i]));
        	i++;
    	}
    }
    ft_putchar('\n');
    return (0);
}