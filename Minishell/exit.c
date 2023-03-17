#include "minishell.h"

int is_digit(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
           return (2);
        i++;
    }
    return (0);
}

int is_char(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isalpha(str[i]))
            return (2);
        i++;
    }
    return (0);
}

void	max_int(char *str, t_data *data)
{
	if (ft_strcmp(str, "9223372036854775807") > 0)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		perror(": ");
		//exit status = 255;
		exit(255);//exit status
	}
}

int	neg_to_pos(long double nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

int ft_exit(char **str, t_data *data)
{
	if (!str[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit(0);//exit status
	}
	else if (is_digit(str[1]) == 0 && !str[2])
	{
		max_int(str[1], data);
		if (str[1][0] != '-' || str[1][0] == '+')
			printf("exit_status 255");
			//exit_status = ft_atoi(str[1]) % 256
		else
			printf("exit status ?");
			//exit_status = 256 - neg_to_pos(ft_atoi(str[1]) % 256);
	}
	else if (str[2])
	{
		perror("minishell: ");
		//exit_status = 1;
		return(0);
	}
	max_int(str[1], data);
	//exit_status;
	exit(255);
   
    return (0);
}
