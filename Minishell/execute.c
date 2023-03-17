#include "minishell.h"

char *access_path(t_data *data)
{
    char *args;
	args = "ls";
	char **split_path;
    int i;
    char *str;
    char *exe;

    i = 0;
    exe = ft_strjoin("/", args);
    split_path = ft_split(ft_get_value("PATH", data), ':');
    while (split_path[i])
    {
        str = ft_strjoin(split_path[i], exe);
        if(access(str, F_OK)==0)
        {
            free(exe);
            return(str);
        }
        free(str);
        i++;
    }
    free(exe);
    return(NULL);
}

int lsh_launch(t_data *data)
{
	char *ptr = "ls";
	char **args;
	args = ft_split(ptr, ' ');
	int i = 0;
	while(args[i])
	{
		// printf("hello%d, %s\n", i, args[i]);
		i++;
	}
	if(execve(access_path(data), args, data->env)== -1)
		perror("Could not execve");
	return (1);
}