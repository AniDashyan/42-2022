#include "minishell.h"

int check_symbol(char *str)
{
    int i;
    i = 0;
    if(str[i] == '-')
    {
        i++;
        while (str[i] && str[i] == 'n') 
            i++;
        if(str[i] == '\0')
            return (1);
        else
            return (0);
    }
    return (0);
}

void    ft_echo(char **ptr)
{
    int     i;
    int     flag;
    // char    **ptr;

    i = 1;
    flag = 0;
    // ptr = ft_split(str, ' ');
    while(ptr[i])
    {
        if(check_symbol(ptr[i]) == 0)
        {
            write(1, ptr[i], ft_strlen(ptr[i]));
            i++;
            
            if(ptr[i] && ptr[i] == '\0')
                write(1, " ", 1);
        }
        else
        {
            flag = 1;
            i++;
        }
    }
    if (flag == 0)
        write(1, "\n", 1);
}