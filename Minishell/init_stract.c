#include "minishell.h"

void	struct_zeroed(t_data *data, char **env)
{
    
    init(data, env);
    data->splited_pipe = NULL;
    data->pipe= NULL;
    data->env = env; // jamanakavor;

    // vars->pipe->head_env = env;
    /*vars->env = env;
    vars->fd_in = 0;
    vars->fd_out = 1; */
    

    // char			*content;
	// /* int				fd_in;  // 0
	// int				fd_out; // 1*/
	// char			**argv; // null
	// // char			*type;
	// t_redirect		*red; // null
	// t_env			*head_env;  // data->env;
	// char			**env;  // env;
	// struct s_pipe	*next;  // null

}