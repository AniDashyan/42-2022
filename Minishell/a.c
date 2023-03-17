#include "minishell.h"
// void	ft_free_tox(char *cmd)
// {	
// 	if (cmd != NULL)
// 	{
// 		free(cmd);
// 		cmd = 0;
// 	}
// }
char *heredoc(char *ptr)
{
    char *s;
    int fd;
    char *file;

    char *result;

    file = ft_strjoin(".hd", ptr);
    ptr += 2;
    fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
    while (1)
    {
        s = readline("herdoc:");
        printf("s,,,%s\n",s);
        printf("ptr%s\n",ptr);
        if (ft_strcmp(s,ptr) == 0)
            break;
    }
    
    return (result);
}