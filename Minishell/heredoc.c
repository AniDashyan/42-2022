#include "minishell.h"

// void	ft_free_tox(char *cmd)
// {	
// 	if (cmd != NULL)
// 	{
// 		free(cmd);
// 		cmd = 0;
// 	}
// }

void heredoc(char *ptr,t_data *data)
{
    char *s;
    int fd[2];
   
    pipe(fd);
    while (1)
    {
        s = readline("herdoc:");
        // printf("s,,,%s\n",s);
        //  printf("ptr%s\n",ptr);
        if (ft_strcmp(s,ptr) == 0)
            break;
        write(fd[1], s, ft_strlen(s));
        write(fd[1], "\n", 1);
        free(s);
        // s = NULL;
    }
    close(fd[1]);
    data->fd_herdoc=fd[0];
}
