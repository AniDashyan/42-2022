#include "minishell.h"

int ft_cd(char *str, t_data *data)
{
	
    if (str == NULL)
        // our env
        chdir(ft_get_value("HOME", data));
    chdir(str);
    return (0);
}