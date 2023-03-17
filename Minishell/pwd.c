#include "minishell.h"

int    ft_pwd(void)
{
    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
      perror("getcwd() error");
    else
      printf("%s\n", cwd);
   return (0); 
}
